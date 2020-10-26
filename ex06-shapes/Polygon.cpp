#include <cmath>
#include "Polygon.h"
#include "Matrix.h"

ds_course::Polygon::Polygon(std::string color, int n)
{
    this->color = color;

    this->points = (Matrix<double> **)malloc(sizeof(Matrix<double> *) * n);
    double rad = ((float)360 / (float)n) * (M_PI / (float)180);

    for (int i = 0; i < n; i++)
    {
        Matrix<double> *vv = NULL;
        vv = (Matrix<double> *)malloc(sizeof(Matrix<double>));
        vv->a[0][0] = cos(rad * i);
        vv->a[1][0] = sin(rad * i);
        vv->a[2][0] = 1;
        points[i] = vv;
    }
}

ds_course::Polygon::~Polygon()
{
}

std::string ds_course::Polygon::draw()
{
}

void ds_course::Polygon::transform(ds_course::Matrix<double> m)
{
}

ds_course::Shape *ds_course::Polygon::clone()
{
}