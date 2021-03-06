#ifndef __QUADRATURE_IO_H__
#define __QUADRATURE_IO_H__

#include <string>
#include "AnyOption.h"
#include "Reader.h"
#include "Writer.h"
#include "QuadraturePoints.h"
#include "Cell.h"

class QuadratureIO
{
public:
    cigma::Reader *reader;
    cigma::Writer *writer;

public:
    std::string quadrature_order;
    std::string quadrature_path;
    std::string points_path;
    std::string weights_path;
    cigma::QuadraturePoints *quadrature;

public:
    QuadratureIO();
    ~QuadratureIO();
    void load(cigma::Cell *cell);
    void save();
};


void load_args(AnyOption *opt, QuadratureIO *quadratureIO, const char *opt_prefix);
void validate_args(QuadratureIO *quadratureIO, const char *cmd_name);


#endif
