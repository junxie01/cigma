#ifndef __NUMERIC_H__
#define __NUMERIC_H__

#define MIN(a,b)    (((a) < (b)) ? (a) : (b))
#define MAX(a,b)    (((a) > (b)) ? (a) : (b))
#define SQR(x)      ((x)*(x))

namespace cigma
{
    void prodve(double a[3], double b[3], double c[3]);
    void matvec(double mat[3][3], double vec[3], double res[3]);

    double det3x3(double mat[3][3]);
    double inv3x3(double mat[3][3], double inv[3][3]);

    int sys3x3(double mat[3][3], double b[3], double res[3], double *det);

    void minmax(int n, double *X, double *Y, double *Z, double min[3], double max[3]);
    void centroid(int n, double *X, double *Y, double *Z, double c[3]);
}

#endif
