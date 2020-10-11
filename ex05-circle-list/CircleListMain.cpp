#include <iostream>
#include <sstream>
#include <string>
#include "CircleList.h"

void INS(ds_course::CircleList *cL, int pos, int val);
void DEL(ds_course::CircleList *cL, int pos);

int main()
{
    int elementCount;
    std::cin >> elementCount;

    int elementValue;
    ds_course::CircleList *pCL = NULL;
    pCL = (ds_course::CircleList *)malloc(sizeof(ds_course::CircleList));

    for (int i = 0; i < elementCount; i++)
    {
        std::cin >> elementValue;
        pCL->add(elementValue);
        pCL->advance();
    }

    std::string inputLine;
    std::string operation;
    int index;
    int value;

    std::cin.ignore(10000, '\n');

    while (getline(std::cin, inputLine))
    {
        std::istringstream sstr(inputLine);
        if (sstr.peek() == '#')
        {
            continue;
        }
        else
        {
            sstr >> operation;

            if (operation.compare("INS") == 0)
            {
                sstr >> index >> value;
                try
                {
                    INS(pCL, index, value);
                }
                catch (ds_course::OutOfBoundsException &e)
                {
                    std::cout << e.getMessage() << std::endl;
                    return -1;
                }
            }
            else if (operation.compare("DEL") == 0)
            {
                sstr >> index;
                try
                {
                    DEL(pCL, index);
                }
                catch (ds_course::OutOfBoundsException &e)
                {
                    std::cout << e.getMessage() << std::endl;
                    return -1;
                }
            }
            else
            {
                std::cout << "No such operation supported" << std::endl;
            }
        }
    }

    std::cout << pCL->to_str() << std::endl;

    return EXIT_SUCCESS;
}

void INS(ds_course::CircleList *cL, int pos, int val)
{

    if (pos > cL->getSize())
    {
        throw ds_course::OutOfBoundsException("OutOfBoundsException");
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        cL->advance();
    }

    cL->add(val);

    for (int i = 0; i < (cL->getSize() - pos); i++)
    {
        cL->advance();
    }
}

void DEL(ds_course::CircleList *cL, int pos)
{
    int size = cL->getSize();

    if (pos >= size)
    {
        throw ds_course::OutOfBoundsException("OutOfBoundsException");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (pos == i)
        {
            cL->remove();
            continue;
        }
        cL->advance();
    }
}
