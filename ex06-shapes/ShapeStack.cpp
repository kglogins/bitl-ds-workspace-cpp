#include "ShapeStack.h"
#include "Shape.h"

#define MAX_SIZE 1000

ds_course::ShapeStack::ShapeStack()
{
    shapes = (Shape **)malloc(sizeof(Shape *) * MAX_SIZE);
    topElem = -1;
}

ds_course::ShapeStack::~ShapeStack()
{
}

int ds_course::ShapeStack::size()
{
    return topElem + 1;
}

bool ds_course::ShapeStack::empty()
{
    return topElem == -1;
}

ds_course::Shape *ds_course::ShapeStack::top()
{
    return shapes[topElem];
}

void ds_course::ShapeStack::push(Shape *sh)
{
    shapes[++topElem] = sh;
}

void ds_course::ShapeStack::pop()
{
    topElem--;
}

void ds_course::ShapeStack::iterReset()
{
    iterCursor = size() - 1;
}

bool ds_course::ShapeStack::iterHasNext()
{
    return iterCursor > 0;
}

ds_course::Shape *ds_course::ShapeStack::iterNext()
{
    return shapes[iterCursor--];
}