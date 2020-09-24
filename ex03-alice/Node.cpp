#include <iostream>
#include <stdio.h>
#include "Node.h"
#include "algorithm"
#include <bits/stdc++.h>

using namespace ds_course;
using namespace std;

Node::Node(int vv)
{
    this->val = vv;
    std::vector<Node> children;
};

void Node::addChild(Node child)
{
    this->children.push_back(child);
}

void Node::reflect()
{
    reverse(children.begin(), children.end());
};

void Node::printPreorder()
{
    if (this->children.size() == 0)
    {
        return;
    }

    this->reflect();

    cout << this->getVal();

    for (int i = 0; i < this->children.size(); i++)
    {
        std::cout << " " << this->children[i].getVal();
    }

    std::cout << endl;

    for (int i = 0; i < this->children.size(); i++)
    {
        this->children[i].printPreorder();
    }
}

int Node::getVal()
{
    return this->val;
};

vector<int> Node::getChildren()
{
    vector<int> childrenNumbers;

    for (int i = 0; i != this->children.size(); i++)
    {
        childrenNumbers.push_back(this->children[i].getVal());
    }

    return childrenNumbers;
}
