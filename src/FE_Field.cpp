#include <cassert>
#include "FE_Field.h"

// ---------------------------------------------------------------------------

cigma::FE_Field::FE_Field()
{
    dim = 0;
    rank = 0;
    fe = 0;
    meshPart = 0;
    dofHandler = 0;
}

cigma::FE_Field::~FE_Field()
{
}

// ---------------------------------------------------------------------------

void cigma::FE_Field::get_cell_dofs(int cellIndex, double *cellDofs)
{
    assert(fe != 0);
    assert(dofHandler != 0);
    assert(meshPart != 0);
    assert(0 <= cellIndex);
    assert(cellIndex < (meshPart->nel));

    const int ndofs = fe->cell->n_nodes();
    const int valdim = n_rank();

    int *n = &(meshPart->connect[ndofs * cellIndex]);
    for (int i = 0; i < ndofs; i++)
    {
        for (int j = 0; j < valdim; j++)
        {
            cellDofs[valdim * i + j] = dofHandler->dofs[valdim * n[i] + j];
        }
    }
}

// ---------------------------------------------------------------------------

void cigma::FE_Field::eval(double *point, double *value)
{
    assert(fe != 0);
    assert(meshPart != 0);

    // get reference cell object from fe
    Cell *cell = fe->cell;
    assert(cell != 0);

    // find the cell which contains given point
    int e;
    bool found_cell = false;
    found_cell = meshPart->find_cell(point, &e);
    assert(found_cell);

    // use dofs as weights on the shape function values
    const int ndofs = cell->n_nodes();
    int valdim = n_rank();

    //double globalCellCoords[cell_nno * cell_nsd];
    //meshPart->get_cell_coords(e, globalCellCoords);
    //cell->interpolate(globalCellCoords, point, value, valdim);

    double field_dofs[ndofs * valdim];
    get_cell_dofs(e, field_dofs);
    double uvw[3];
    cell->xyz2uvw(point,uvw);
    cell->interpolate(field_dofs, uvw, value, valdim);
}

void cigma::FE_Field::tabulate()
{
    assert(fe != 0);
    assert(meshPart != 0);

    Cell *cell = fe->cell;
    assert(cell != 0);

    // quadrature
    Quadrature *quadrature = fe->quadrature;
    assert(quadrature != 0);
    int nq = quadrature->n_points();
    double *qpts = quadrature->qpts;
    double *qwts = quadrature->qwts;

    // get shape function values at known quadrature points
    cell->shape(nq, qpts, fe->basis_tab);

    // get shape function derivatives at known quadrature points
    cell->grad_shape(nq, qpts, fe->basis_jet);

    // evaluate jacobian at known quadrature points and calculate jxw
    int q;
    int celldim = cell->n_celldim();
    double *jxw = fe->jxw;
    for (q = 0; q < nq; q++)
    {
        double jac[3][3];
        jxw[q] = qwts[q] * cell->jacobian(&qpts[celldim*q], jac);
    }
}

// ---------------------------------------------------------------------------