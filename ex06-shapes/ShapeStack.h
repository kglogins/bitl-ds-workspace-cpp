#include "Shape.h"

namespace ds_course
{
    class ShapeStack
    {
    private:
        int top;
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
    };
} // namespace ds_course