#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "ShapeStack.h"
#include "Circle.h"
#include "Polygon.h"
#include "Group.h"
#include "Transformation.h"

int main()
{
    ds_course::ShapeStack stack;

    std::string inputLine;
    std::string cmd;
    int width;
    int height;

    while (getline(std::cin, inputLine))
    {
        std::istringstream sstr(inputLine);

        sstr >> cmd;

        if (cmd.compare("CIRCLE") == 0)
        {
            std::string color;
            sstr >> color;

            stack.push(new ds_course::Circle(color));
        }
        else if (cmd.compare("POLYGON") == 0)
        {
            std::string color;
            int edges;
            sstr >> color >> edges;

            stack.push(new ds_course::Polygon(color, edges));
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
                stack.top()->transform(vv);
            }
            else if (transfCmd.compare("ROT") == 0)
            {
                double angle;
                sstr >> angle;
                ds_course::Matrix<double> vv = ds_course::getROT(angle);
                stack.top()->transform(vv);
            }
            else if (transfCmd.compare("SCA") == 0)
            {
                double cx, cy;
                sstr >> cx >> cy;
                ds_course::Matrix<double> vv = ds_course::getSCA(cx, cy);
                stack.top()->transform(vv);
            }
            else if (transfCmd.compare("SHE") == 0)
            {
                double cx, cy;
                sstr >> cx >> cy;
                ds_course::Matrix<double> vv = ds_course::getSHE(cx, cy);
                stack.top()->transform(vv);
            }
        }
        else if (cmd.compare("COPY") == 0)
        {
            stack.push(stack.top()->clone());
        }
        else if (cmd.compare("GROUP") == 0)
        {
            int items;
            sstr >> items;

            ds_course::ShapeStack groupStack;

            for (int i = 0; i < items; i++)
            {
                groupStack.push(stack.top());
                stack.pop();
            }

            stack.push(new ds_course::Group(groupStack));
        }
        else if (cmd.compare("SHOW") == 0)
        {
            sstr >> width >> height;

            printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
            printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%i\" height=\"%i\">\n", width, height);
            printf("<path d=\"M 0 0 L %i 0 L %i %i L 0 %i\" fill=\"#cccccc \"/>", width, width, height, height);

            stack.iterReset();

            while (stack.iterHasNext())
            {
                std::cout << stack.iterNext()->draw();
            }

            printf("<rect x=\"0\" y=\"0\" width=\"%i\" height=\"%i\" stroke=\"#999999\" fill=\"none\" stroke-width=\"1\"/>\n</svg>\n", width, height);

            return 1;
        }
        else
        {
            printf("Unknown command used\n");
        }
    }

    return 0;
}