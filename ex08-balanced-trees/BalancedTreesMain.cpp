#include <iostream>
#include <string>
#include <sstream>

#include "AVLTree.h"

int main()
{
    std::string orderingMode;
    std::string inputLine;
    std::string cmd;
    int lineNumber = 1;
    std::string word;

    getline(std::cin, inputLine);
    std::istringstream sstr(inputLine);
    sstr >> orderingMode;

    ds_course::AVLTree *tree = new ds_course::AVLTree(orderingMode);

    while (getline(std::cin, inputLine))
    {
        std::istringstream sstr(inputLine);
        sstr >> cmd;

        lineNumber++;

        if (cmd.compare("I") == 0)
        {
            while (sstr >> word)
            {
                tree->mainNode = tree->insert(tree->mainNode, word);
            }
        }
        else if (cmd.compare("E") == 0)
        {
            while (sstr >> word)
            {
                tree->mainNode = tree->erase(tree->mainNode, word);
            }
        }
        else if (cmd.compare("G") == 0)
        {
            std::cout << lineNumber;
            sstr >> word;

            ds_course::Node *result = tree->get(tree->mainNode, word);

            if (result == NULL)
            {
                std::cout << " (" << word << ",0)";
            }
            else
            {
                std::cout << " (" << result->word << "," << result->badnessValue << ")";
            }

            std::cout << std::endl;
        }
        else if (cmd.compare("L") == 0)
        {
            std::cout << lineNumber;
            sstr >> word;
            std::string path = "*";

            ds_course::Node *result = tree->locate(tree->mainNode, word, path);

            if (result == NULL)
            {
                std::cout << " N";
            }

            std::cout << std::endl;
        }
        else if (cmd.compare("D") == 0)
        {
            std::cout << lineNumber;

            std::string start, end;

            sstr >> start >> end;

            tree->dump(tree->mainNode, start, end);

            std::cout << std::endl;
        }
        else if (cmd.compare("F") == 0)
        {
            return 0;
        }
        else
        {
            printf("Invalid command entered! Ending program...\n");
            return -1;
        }
    }

    return 0;
}