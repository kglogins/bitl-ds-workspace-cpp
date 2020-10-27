#include <cstring>
#include "Group.h"
#include "Shape.h"
#include "Matrix.h"

ds_course::Group::Group(ds_course::ShapeStack stack)
{
    this->stack = stack;
}

ds_course::Group::~Group()
{
}

std::string ds_course::Group::draw()
{
    this->stack.iterReset();
    std::string result;

    while (this->stack.iterHasNext())
    {
        result = result + this->stack.iterNext()->draw();
    };

    return result;
}

void ds_course::Group::transform(ds_course::Matrix<double> m)
{
    stack.iterReset();

    while (stack.iterHasNext())
    {
        stack.iterNext()->transform(m);
    }
}

ds_course::Shape *ds_course::Group::clone()
{
    ds_course::Group *cloneShape = new ds_course::Group(this->stack);

    return cloneShape;
}