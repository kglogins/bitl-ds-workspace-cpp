#include <string>
#include "Shape.h"
#include "Matrix.h"

namespace ds_course
{
    class Circle : public Shape
    {
    private:
        const int n = 1000;
        std::string color;
        ds_course::Matrix<double> *points;

    public:
        Circle(std::string col);
        ~Circle();
        std::string draw();
        void transform(ds_course::Matrix<double> m);
        ds_course::Shape *clone();
    };
} // namespace ds_course