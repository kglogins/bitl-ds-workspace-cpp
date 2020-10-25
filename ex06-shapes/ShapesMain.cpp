#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "ShapeStack.h"

int main()
{
    ds_course::ShapeStack s;

    std::string inputLine;
    std::string cmd;

    while (getline(std::cin, inputLine))
    {
        std::istringstream sstr(inputLine);

        sstr >> cmd;

        if (cmd.compare("CIRC") == 0)
        {
        }
        else if (cmd.compare("POLYGON") == 0)
        {
        }
        else if (cmd.compare("TRANSF") == 0)
        {
        }
        else if (cmd.compare("COPY") == 0)
        {
        }
        else if (cmd.compare("GROUP") == 0)
        {
        }
        else if (cmd.compare("SHOW") == 0)
        {
        }
        else
        {
            printf("Unknown command used\n");
        }
    }

    return 0;
}