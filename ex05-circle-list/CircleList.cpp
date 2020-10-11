#include <string>
#include <iostream>
#include "CircleList.h"

ds_course::CircleList::CircleList() : cursor(NULL)
{
    size = 0;
}

ds_course::CircleList::~CircleList()
{
    while (!empty())
    {
        remove();
    }
}

bool ds_course::CircleList::empty() const
{
    return cursor == NULL;
}

const int &ds_course::CircleList::front() const
{
    return cursor->next->elem;
}

const int &ds_course::CircleList::back() const
{
    return cursor->elem;
}

void ds_course::CircleList::add(const int &e)
{
    ds_course::CNode *v = new CNode;
    v->elem = e;

    if (cursor == NULL)
    {
        v->next = v;
        cursor = v;
    }
    else
    {
        v->next = cursor->next;
        cursor->next = v;
    }

    size++;
}

void ds_course::CircleList::remove()
{
    ds_course::CNode *old = cursor->next;
    if (old == cursor)
        cursor = NULL;
    else
        cursor->next = old->next;
    delete old;

    size--;
}

void ds_course::CircleList::advance()
{
    cursor = cursor->next;
}

int ds_course::CircleList::getSize()
{
    return size;
}

std::string ds_course::CircleList::to_str() const
{
    if (cursor == NULL)
    {
        return "";
    }

    std::string result;
    ds_course::CNode *next = cursor->next;
    result.append(std::to_string(next->elem));

    for (int i = 1; i < size; i++)
    {
        next = next->next;
        result.append(" ");
        result.append(std::to_string(next->elem));
    }

    return result;
}

ds_course::OutOfBoundsException::OutOfBoundsException(const std::string &msg)
{
    this->msg = msg;
}

ds_course::OutOfBoundsException::~OutOfBoundsException()
{
}

std::string ds_course::OutOfBoundsException::getMessage() const
{
    return this->msg;
}
