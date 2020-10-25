#include "Matrix.h"

namespace ds_course
{
    ds_course::Matrix<double> getTRA(double dx, double dy)
    {
        Matrix<double> vv(3, 3);
        vv.a[0][0] = 1;
        vv.a[0][1] = 0;
        vv.a[0][2] = dx;
        vv.a[1][0] = 0;
        vv.a[1][1] = 1;
        vv.a[1][2] = dy;
        vv.a[2][0] = 0;
        vv.a[2][1] = 0;
        vv.a[2][2] = 1;

        return vv;
    }

    ds_course::Matrix<double> getROT(double angle)
    {
    }

    ds_course::Matrix<double> getSCA(double cx, double cy)
    {
        Matrix<double> vv(3, 3);
        vv.a[0][0] = cx;
        vv.a[0][1] = 0;
        vv.a[0][2] = 0;
        vv.a[1][0] = 0;
        vv.a[1][1] = cy;
        vv.a[1][2] = 0;
        vv.a[2][0] = 0;
        vv.a[2][1] = 0;
        vv.a[2][2] = 1;

        return vv;
    }

    ds_course::Matrix<double> getSHE(double cx, double cy)
    {
    }
} // namespace ds_course