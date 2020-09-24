#include <iostream>
#include <stdio.h>
#include <sstream>
#include <map>
#include "Node.h"

using namespace ds_course;
using namespace std;

int findNodeHeadNumber(vector<int> first, vector<int> second);
Node addChildren(int nodeNumber, map<int, vector<int>> nodeMap);

int main()
{

    std::string inputLine;
    std::map<int, std::vector<int>> inputData;

    std::vector<int> mainNumberArray;
    std::vector<int> secondaryNumberArray;
    int headNodeNumber;

    while (getline(cin, inputLine))
    {
        istringstream sstr(inputLine);
        if (sstr.peek() == '0')
        {
            break;
        }
        else
        {
            int number;
            int parentNodeNumber;
            vector<int> childNodeNumbers;
            bool isMain = true;

            while (sstr >> number)
            {
                if (isMain)
                {
                    parentNodeNumber = number;
                    mainNumberArray.push_back(number);

                    isMain = false;
                }
                else
                {
                    childNodeNumbers.push_back(number);
                    secondaryNumberArray.push_back(number);
                }
            }

            inputData.insert(std::pair<int, vector<int>>(parentNodeNumber, childNodeNumbers));
        }
    }

    headNodeNumber = findNodeHeadNumber(mainNumberArray, secondaryNumberArray);

    Node headNode = addChildren(headNodeNumber, inputData);

    headNode.printPreorder();
    cout << "0\n";

    return 0;
}

Node addChildren(int nodeNumber, map<int, vector<int>> nodeMap)
{
    Node node(nodeNumber);

    map<int, vector<int>>::iterator it = nodeMap.find(nodeNumber);

    if (it == nodeMap.end())
    {
        return node;
    }

    for (int i = 0; i < nodeMap.at(nodeNumber).size(); i++)
    {
        Node child = addChildren(nodeMap.at(nodeNumber)[i], nodeMap);
        node.addChild(child);
    }

    return node;
}

int findNodeHeadNumber(vector<int> first, vector<int> second)
{
    int res = -1;

    for (int i = 0; i < first.size(); i++)
    {
        bool dublicateFound = false;

        for (int j = 0; j < second.size(); j++)
        {
            if (first[i] == second[j])
            {
                dublicateFound = true;
                break;
            }
        }

        if (!dublicateFound)
        {
            return first[i];
        }
    }

    cout << "No head found (probably invalid tree)\n";
    return res;
}
