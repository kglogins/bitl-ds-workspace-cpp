#ifndef DS_TRANSFORMATION_H
#define DS_TRANSFORMATION_H

#include <cmath>
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
        double rad = (angle * M_PI) / 180;

        Matrix<double> vv(3, 3);
        vv.a[0][0] = cos(rad);
        vv.a[0][1] = -sin(rad);
        vv.a[0][2] = 0;
        vv.a[1][0] = sin(rad);
        vv.a[1][1] = cos(rad);
        vv.a[1][2] = 0;
        vv.a[2][0] = 0;
        vv.a[2][1] = 0;
        vv.a[2][2] = 1;

        return vv;
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
        Matrix<double> vv(3, 3);
        vv.a[0][0] = 1;
        vv.a[0][1] = cx;
        vv.a[0][2] = 0;
        vv.a[1][0] = cy;
        vv.a[1][1] = 1;
        vv.a[1][2] = 0;
        vv.a[2][0] = 0;
        vv.a[2][1] = 0;
        vv.a[2][2] = 1;

        return vv;
    }
} // namespace ds_course

#endif