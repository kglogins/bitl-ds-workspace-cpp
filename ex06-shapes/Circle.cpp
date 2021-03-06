#include <string>
#include <cmath>
#include <cstring>
#include "Circle.h"

ds_course::Circle::Circle(std::string color)
{
    this->color = color;

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

ds_course::Circle::~Circle()
{
}

std::string ds_course::Circle::draw()
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

void ds_course::Circle::transform(ds_course::Matrix<double> m)
{
    for (int i = 0; i < n; i++)
    {
        points[i] = m * points[i];
    }
}

ds_course::Shape *ds_course::Circle::clone()
{
    ds_course::Circle *cloneShape = new ds_course::Circle(this->color);
    memcpy(cloneShape->points, this->points, sizeof(ds_course::Matrix<double>) * this->n);

    return cloneShape;
}