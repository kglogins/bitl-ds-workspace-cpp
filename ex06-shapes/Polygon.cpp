#include <cmath>
#include <cstring>
#include "Polygon.h"
#include "Matrix.h"

ds_course::Polygon::Polygon(std::string color, int n)
{
    this->color = color;
    this->n = n;

    this->points = (Matrix<double> *)malloc(sizeof(Matrix<double>) * n);
    double rad = ((float)360 / (float)n) * (M_PI / (float)180);

    for (int i = 0; i < n; i++)
    {
        Matrix<double> vv(3, 1);
        vv.a[0][0] = cos(rad * i);
        vv.a[1][0] = sin(rad * i);
        vv.a[2][0] = 1;
        points[i] = vv;
    }
}

ds_course::Polygon::~Polygon()
{
}

std::string ds_course::Polygon::draw()
{
    std::string result = "<path d=\"";

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            result = result + "M " + std::to_string(points[i].a[0][0]) + " " + std::to_string(points[i].a[1][0]);
        }
        else
        {
            result = result + " L " + std::to_string(points[i].a[0][0]) + " " + std::to_string(points[i].a[1][0]);
        }
    }

    result = result + "\" fill=\"" + this->color + "\" />\n";

    return result;
}

void ds_course::Polygon::transform(ds_course::Matrix<double> m)
{
    for (int i = 0; i < n; i++)
    {
        points[i] = m * points[i];
    }
}

ds_course::Shape *ds_course::Polygon::clone()
{
    ds_course::Polygon *cloneShape = new ds_course::Polygon(this->color, this->n);
    memcpy(cloneShape->points, this->points, sizeof(ds_course::Matrix<double>) * this->n);

    return cloneShape;
}