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
    std::string result;

    while (this->stack.iterHasNext())
    {
        result = result + this->stack.iterNext()->draw();
    };

    result = result + this->stack.iterNext()->draw();

    this->stack.iterReset();

    return result;
}

void ds_course::Group::transform(ds_course::Matrix<double> m)
{

    while (this->stack.iterHasNext())
    {
        this->stack.iterNext()->transform(m);
    };

    this->stack.iterNext()->transform(m);

    this->stack.iterReset();
}

ds_course::Shape *ds_course::Group::clone()
{
    return new ds_course::Group(*this);
}