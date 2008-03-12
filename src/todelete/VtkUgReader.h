#ifndef __VTK_UG_READER_H__
#define __VTK_UG_READER_H__

#include <string> 

#include "Reader.h"

#include "vtkUnstructuredGridReader.h"
#include "vtkUnstructuredGrid.h"

namespace cigma
{
    class VtkUgReader;
}

class cigma::VtkUgReader : cigma::Reader
{
public:
    VtkUgReader();
    ~VtkUgReader();

public:
    ReaderType getType() { return VTK_READER; }

public:
    void open(std::string filename);
    void close();

public:
    void get_coordinates(double **coordinates, int *nno, int *nsd);
    void get_connectivity(int **connectivity, int *nel, int *ndofs);
    void get_vector_point_data(const char *name, double **vectors, int *num, int *dim);
    void get_scalar_point_data(const char *name, double **scalars, int *num, int *dim);

public:
    vtkUnstructuredGridReader *reader;
    vtkUnstructuredGrid *grid;
};

// ---------------------------------------------------------------------------

#endif