#ifndef DS_SHAPESTACK_H
#define DS_SHAPESTACK_H

#include "Shape.h"

namespace ds_course
{
    class ShapeStack
    {
    private:
        int topElem;
        ds_course::Shape **shapes;
        int iterCursor;

    public:
        ShapeStack();
        ~ShapeStack();
        int size();
        bool empty();
        ds_course::Shape *top();
        void push(Shape *sh);
        void pop();

        void iterReset();
        bool iterHasNext();
        Shape *iterNext();
    };
} // namespace ds_course

#endif