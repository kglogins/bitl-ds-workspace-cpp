#include <cstdlib>

#include "AlienFamily.h"

ds_course::AlienFamily::AlienFamily(struct ds_course::Alien *headNode)
{
    this->headNode = headNode;
    this->next = NULL;
    this->numberOfAliens = 1;
};

ds_course::AlienFamily::~AlienFamily()
{
}

void ds_course::AlienFamily::addChild(int parentVal, int childVal, std::string side)
{
    if (parentVal == childVal)
    {
        printf("error1\n");
        return;
    }

    ds_course::AlienFamily *currentFamily = this;
    struct ds_course::Alien *parentNodeSaved = NULL;
    struct ds_course::Alien *childNodeSaved = NULL;
    struct ds_course::Alien *parentNode = NULL;
    struct ds_course::Alien *childNode = NULL;

    while (currentFamily != NULL)
    {
        parentNode = currentFamily->findAlienByValue(currentFamily->headNode, parentVal);
        childNode = currentFamily->findAlienByValue(currentFamily->headNode, childVal);

        if (parentNode != NULL)
        {
            parentNodeSaved = parentNode;
        }

        if (childNode != NULL)
        {
            childNodeSaved = childNode;
        }

        currentFamily = currentFamily->next;
    }

    if (parentNodeSaved == NULL)
    {
        printf("error2\n");
        return;
    }

    if (childNodeSaved != NULL)
    {
        printf("error3\n");
        return;
    }

    struct ds_course::Alien *child = new ds_course::Alien(childVal);

    if (side.compare("L") == 0) // left
    {
        if (parentNodeSaved->left != NULL)
        {
            printf("error4\n");
        }
        else
        {
            parentNodeSaved->left = child;
            this->numberOfAliens++;
            return;
        }
    }
    else if (side.compare("R") == 0) // right
    {
        if (parentNodeSaved->right != NULL)
        {
            printf("error5\n");
        }
        else
        {
            parentNodeSaved->right = child;
            this->numberOfAliens++;
            return;
        }
    }
}

ds_course::Alien *ds_course::AlienFamily::findAlienByValue(struct ds_course::Alien *alien, int value)
{
    if (alien == NULL)
    {
        return NULL;
    }

    if (alien->value == value)
    {
        return alien;
    }

    struct ds_course::Alien *leftResult = findAlienByValue(alien->left, value);
    struct ds_course::Alien *rightResult = findAlienByValue(alien->right, value);

    if (leftResult != NULL)
    {
        return leftResult;
    }
    else if (rightResult != NULL)
    {
        return rightResult;
    }
    else
    {
        return NULL;
    }
}

ds_course::Alien *ds_course::AlienFamily::getHeadNode()
{
    return this->headNode;
}

void ds_course::AlienFamily::lookupAlien(int value)
{
    ds_course::AlienFamily *currentFamily = this;
    struct ds_course::Alien *foundAlien = NULL;

    while ((foundAlien = currentFamily->findAlienByValue(currentFamily->headNode, value)) == NULL)
    {
        currentFamily = currentFamily->next;
        if (currentFamily == NULL)
        {
            printf("error0\n");
            return;
        }
    }

    int inorderArray[currentFamily->numberOfAliens];
    this->traversalPosition = 0;
    this->fillInorderArray(currentFamily->headNode, inorderArray);

    for (int alienIndex = 0; alienIndex < this->traversalPosition; alienIndex++)
    {
        if (inorderArray[alienIndex] == value)
        {
            if (alienIndex != 0)
            {
                printf("%i ", inorderArray[alienIndex - 1]);
            }
            else
            {
                printf("0 ");
            }

            if (alienIndex != this->traversalPosition - 1)
            {
                printf("%i\n", inorderArray[alienIndex + 1]);
            }
            else
            {
                printf("0\n");
            }
        }
    }
}

void ds_course::AlienFamily::fillInorderArray(struct ds_course::Alien *node, int *inorderArray)
{
    if (node == NULL)
    {
        return;
    }

    fillInorderArray(node->left, inorderArray);

    inorderArray[traversalPosition] = node->value;
    traversalPosition++;

    fillInorderArray(node->right, inorderArray);
}

void ds_course::AlienFamily::addNewFamily(int headVal)
{
    ds_course::AlienFamily *currentFamily = this;

    while (currentFamily->findAlienByValue(currentFamily->headNode, headVal) == NULL)
    {
        if (currentFamily->next == NULL)
        {
            struct ds_course::Alien *newHeadNode = new ds_course::Alien(headVal);
            struct ds_course::AlienFamily *newFamily = new ds_course::AlienFamily(newHeadNode);
            currentFamily->next = newFamily;

            return;
        }

        currentFamily = currentFamily->next;
    }

    printf("error6\n");
    return;
}
