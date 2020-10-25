#include <string>
#include "Shape.h"

namespace ds_course
{
    class Polygon : public ds_course::Shape
    {
    private:
        int n;
        std::string color;
        ds_course::Matrix<double> **points;

    public:
        Polygon(std::string color, int n);
        ~Polygon();
        std::string draw();
        void transform(ds_course::Matrix<double> m);
        ds_course::Shape *clone();
    };
} // namespace ds_course