#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
// #include "ShapeStack.h"
#include "Circle.h"
#include "Transformation.h"

int main()
{
    // ds_course::ShapeStack s;

    std::string inputLine;
    std::string cmd;
    int width;
    int height;

    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%i\" height=\"%i\">\n", width, height);

    while (getline(std::cin, inputLine))
    {
        std::istringstream sstr(inputLine);

        sstr >> cmd;

        if (cmd.compare("CIRCLE") == 0)
        {
            std::string color;
            sstr >> color;

            ds_course::Circle circle(color);

            std::cout << circle.draw();

            // s.push(ds_course::Circle(color));
        }
        else if (cmd.compare("POLYGON") == 0)
        {
        }
        else if (cmd.compare("TRANSF") == 0)
        {
            std::string transfCmd;
            sstr >> transfCmd;

            if (transfCmd.compare("TRA") == 0)
            {
                double dx, dy;
                sstr >> dx >> dy;
                ds_course::Matrix<double> vv = ds_course::getTRA(dx, dy);
            }
            else if (transfCmd.compare("ROT") == 0)
            {
                double angle;
                sstr >> angle;
                ds_course::Matrix<double> vv = ds_course::getROT(angle);
            }
            else if (transfCmd.compare("SCA") == 0)
            {
                double cx, cy;
                sstr >> cx >> cy;
                ds_course::Matrix<double> vv = ds_course::getSCA(cx, cy);
            }
            else if (transfCmd.compare("SHE") == 0)
            {
                double cx, cy;
                sstr >> cx, cy;
                ds_course::Matrix<double> vv = ds_course::getSHE(cx, cy);
            }
        }
        else if (cmd.compare("COPY") == 0)
        {
        }
        else if (cmd.compare("GROUP") == 0)
        {
        }
        else if (cmd.compare("SHOW") == 0)
        {
            sstr >> width >> height;
        }
        else
        {
            printf("Unknown command used\n");
        }
    }

    printf("<rect x=\"0\" y=\"0\" width=\"%i\" height=\"%i\" stroke=\"#999999\" fill=\"none\" stroke-width=\"1\"/>\n</svg>\n", width, height);

    return 0;
}