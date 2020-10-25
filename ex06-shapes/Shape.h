#include <string>
#include <stdio.h>
#include "Matrix.h"

namespace ds_course
{
    class Shape
    {
    public:
        std::string draw();
        void transform(ds_course::Matrix<double> m);
        Shape *clone();
    };
} // namespace ds_course