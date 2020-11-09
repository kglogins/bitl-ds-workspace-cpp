#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

#include "AlienFamily.h"

int main()
{
    ds_course::AlienFamily *alienFamilies = NULL;

    std::string inputLine;
    std::string cmd;
    int parentVal;
    int childVal;

    while (getline(std::cin, inputLine))
    {
        std::istringstream sstr(inputLine);

        sstr >> cmd;

        if (cmd.compare("T") == 0)
        {
            sstr >> parentVal;

            if (alienFamilies == NULL)
            {
                struct ds_course::Alien *headAlien = new ds_course::Alien(parentVal);
                alienFamilies = new ds_course::AlienFamily(headAlien);
            }
            else
            {
                alienFamilies->addNewFamily(parentVal);
            }
        }
        else if (cmd.compare("R") == 0 || cmd.compare("L") == 0)
        {
            sstr >> parentVal >> childVal;
            alienFamilies->addChild(parentVal, childVal, cmd);
        }
        else if (cmd.compare("?") == 0)
        {
            sstr >> parentVal;
            alienFamilies->lookupAlien(parentVal);
        }
        else if (cmd.compare("F") == 0)
        {
            return 1;
        }
        else
        {
            printf("Unknown command\n");
        }
    }
    return 1;
}