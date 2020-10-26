#ifndef DS_SHAPE_H
#define DS_SHAPE_H

#include <string>
#include <stdio.h>
#include "Matrix.h"

namespace ds_course
{
    class Shape
    {
    public:
        virtual std::string draw() = 0;
        virtual void transform(ds_course::Matrix<double> m) = 0;
        virtual ds_course::Shape *clone() = 0;
    };
} // namespace ds_course

#endif