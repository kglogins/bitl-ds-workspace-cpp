#ifndef DS_GROUP_H
#define DS_GROUP_H

#include <string>
#include "Matrix.h"
#include "Shape.h"
#include "ShapeStack.h"

namespace ds_course
{
    class Group : public ds_course::Shape
    {
    private:
        ds_course::ShapeStack stack;

    public:
        Group(ds_course::ShapeStack stack);
        ~Group();
        std::string draw();
        void transform(ds_course::Matrix<double> m);
        Shape *clone();
    };
} // namespace ds_course

#endif