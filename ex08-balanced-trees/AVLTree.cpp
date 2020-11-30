#include <iostream>
#include <string>
#include <sstream>

#include "AVLTree.h"

ds_course::AVLTree::AVLTree(std::string mode)
{
    if (mode.compare("LEX") == 0)
    {
        this->mode = 0;
    }
    else if (mode.compare("SHORTLEX") == 0)
    {
        this->mode = 1;
    }
    else if (mode.compare("COLEX") == 0)
    {
        this->mode = 2;
    }
    else
    {
        printf("Invalid sorting mode! Selecting default (LEX)\n");
    }

    this->mainNode = NULL;
}

ds_course::AVLTree::~AVLTree()
{
}

ds_course::Node *ds_course::AVLTree::insert(ds_course::Node *node, std::string word)
{
    if (node == NULL)
    {
        node = new ds_course::Node(word);
        return node;
    }

    if (this->mode == 0) // Lexicographic order
    {
        if (word < node->word)
        {
            node->left = insert(node->left, word);

            if (get_height(node->left) - get_height(node->right) == 2)
            {
                if (word < node->left->word)
                {
                    node = single_right_rotate(node);
                }
                else
                {
                    node = double_right_rotate(node);
                }
            }
        }
        else if (word.compare(node->word) == 0)
        {
            node->badnessValue++;
            return node;
        }
        else if (word > node->word)
        {
            node->right = insert(node->right, word);

            if (get_height(node->right) - get_height(node->left) == 2)
            {
                if (word > node->right->word)
                {
                    node = single_left_rotate(node);
                }
                else
                {
                    node = double_left_rotate(node);
                }
            }
        }
    }
    else if (this->mode == 1) // Shortlex order
    {
    }
    else if (this->mode == 2) // Colexicographic order
    {
        std::string wordTemp = reverse_string(word);
        std::string nodeWordTemp = reverse_string(node->word);

        if (wordTemp < nodeWordTemp)
        {
            node->left = insert(node->left, word);

            if (get_height(node->left) - get_height(node->right) == 2)
            {
                std::string nodeLeftWordTemp = reverse_string(node->left->word);

                if (wordTemp < nodeLeftWordTemp)
                {
                    node = single_right_rotate(node);
                }
                else
                {
                    node = double_right_rotate(node);
                }
            }
        }
        else if (wordTemp.compare(nodeWordTemp) == 0)
        {
            node->badnessValue++;
            return node;
        }
        else if (wordTemp > nodeWordTemp)
        {
            node->right = insert(node->right, word);

            if (get_height(node->right) - get_height(node->left) == 2)
            {
                std::string nodeRightWordTemp = reverse_string(node->right->word);

                if (wordTemp > nodeRightWordTemp)
                {
                    node = single_left_rotate(node);
                }
                else
                {
                    node = double_left_rotate(node);
                }
            }
        }
    }

    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    return node;
}

ds_course::Node *ds_course::AVLTree::erase(Node *node, std::string word)
{
    if (node == NULL)
    {
        return NULL;
    }

    ds_course::Node *temp;
    std::string wordTemp = word;
    std::string nodeWordTemp = node->word;

    if (this->mode == 1)
    {
        // TODO: Short lex
    }
    else if (this->mode == 2)
    {
        wordTemp = reverse_string(wordTemp);
        nodeWordTemp = reverse_string(nodeWordTemp);
    }

    if (wordTemp < nodeWordTemp)
    {
        node->left = erase(node->left, word);
    }
    else if (wordTemp > nodeWordTemp)
    {
        node->right = erase(node->right, word);
    }
    else if (node->left && node->right)
    {
        temp = find_min(node->right);
        node->word = temp->word;
        node->badnessValue = temp->badnessValue;
        node->right = erase(node->right, node->word);
    }
    else
    {
        temp = node;
        if (node->left == NULL)
        {
            node = node->right;
        }
        else if (node->right == NULL)
        {
            node = node->left;
        }
        delete temp;
    }

    if (node == NULL)
    {
        return node;
    }

    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;

    if (get_height(node->left) - get_height(node->right) == 2)
    {
        if (get_height(node->left->left) - get_height(node->left->right) == 1)
        {
            return single_left_rotate(node);
        }
        else
        {
            return double_left_rotate(node);
        }
    }
    else if (get_height(node->right) - get_height(node->left) == 2)
    {
        if (get_height(node->right->right) - get_height(node->right->left) == 1)
        {
            return single_right_rotate(node);
        }
        else
        {
            return double_right_rotate(node);
        }
    }

    return node;
}

ds_course::Node *ds_course::AVLTree::get(ds_course::Node *node, std::string word)
{
    if (node == NULL)
    {
        return NULL;
    }

    std::string wordTemp = word;
    std::string nodeWordTemp = node->word;

    if (this->mode == 1)
    {
    }
    else if (this->mode == 2)
    {
        wordTemp = reverse_string(wordTemp);
        nodeWordTemp = reverse_string(nodeWordTemp);
    }

    if (wordTemp.compare(nodeWordTemp) == 0)
    {
        // std::cout << " (" << node->word << "," << node->badnessValue << ")";
        return node;
    }
    else if (wordTemp < nodeWordTemp)
    {
        return get(node->left, word);
    }
    else
    {
        return get(node->right, word);
    }
}

ds_course::Node *ds_course::AVLTree::locate(ds_course::Node *node, std::string word, std::string path)
{
    if (node == NULL)
    {
        return NULL;
    }

    std::string wordTemp = word;
    std::string nodeWordTemp = node->word;

    if (this->mode == 1)
    {
    }
    else if (this->mode == 2)
    {
        wordTemp = reverse_string(wordTemp);
        nodeWordTemp = reverse_string(nodeWordTemp);
    }

    if (wordTemp.compare(nodeWordTemp) == 0)
    {
        std::cout << " " << path;
        return node;
    }
    else if (wordTemp < nodeWordTemp)
    {
        path.push_back('L');
        return locate(node->left, word, path);
    }
    else
    {
        path.push_back('R');
        return locate(node->right, word, path);
    }
}

void ds_course::AVLTree::dump(ds_course::Node *node, std::string start, std::string end)
{
    if (node == NULL)
    {
        return;
    }

    std::string startWordTemp = start;
    std::string endWordTemp = end;
    std::string nodeWordTemp = node->word;

    if (this->mode == 1)
    {
        // TODO: Short lex
    }
    else if (this->mode == 2)
    {
        startWordTemp = reverse_string(start);
        endWordTemp = reverse_string(end);
        nodeWordTemp = reverse_string(node->word);
    }

    dump(node->left, start, end);

    if (start.compare("_") == 0 && end.compare("_") == 0)
    {
        std::cout << " (" << node->word << "," << node->badnessValue << ")";
    }
    else if (start.compare("_") == 0)
    {
        if (startWordTemp < nodeWordTemp)
        {
            std::cout << " (" << node->word << "," << node->badnessValue << ")";
        }
    }
    else if (end.compare("_") == 0)
    {
        if (endWordTemp > nodeWordTemp)
        {
            std::cout << " (" << node->word << "," << node->badnessValue << ")";
        }
    }
    else
    {
        if (startWordTemp < nodeWordTemp && endWordTemp > nodeWordTemp)
        {
            std::cout << " (" << node->word << "," << node->badnessValue << ")";
        }
    }

    dump(node->right, start, end);
}

std::string ds_course::AVLTree::reverse_string(std::string str)
{
    int len = str.length();
    std::string temp;

    for (int i = 0; i < len; i++)
    {
        temp.push_back(str[len - i - 1]);
    }

    return temp;
}

int ds_course::AVLTree::get_height(ds_course::Node *node)
{
    return (node == NULL ? -1 : node->height);
}

ds_course::Node *ds_course::AVLTree::find_min(ds_course::Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->left == NULL)
    {
        return node;
    }
    else
    {
        return find_min(node->left);
    }
}

ds_course::Node *ds_course::AVLTree::find_max(ds_course::Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->right == NULL)
    {
        return node;
    }
    else
    {
        return find_max(node->right);
    }
}

ds_course::Node *ds_course::AVLTree::single_right_rotate(ds_course::Node *&node)
{
    if (node->left == NULL)
    {
        return node;
    }

    ds_course::Node *u = node->left;
    node->left = u->right;
    u->right = node;
    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    u->height = std::max(get_height(u->left), node->height) + 1;

    return u;
}

ds_course::Node *ds_course::AVLTree::single_left_rotate(ds_course::Node *&node)
{
    if (node->right == NULL)
    {
        return node;
    }

    ds_course::Node *u = node->right;
    node->right = u->left;
    u->left = node;
    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    u->height = std::max(get_height(node->right), node->height) + 1;

    return u;
}

ds_course::Node *ds_course::AVLTree::double_left_rotate(ds_course::Node *&node)
{
    node->right = single_right_rotate(node->right);
    return single_left_rotate(node);
}

ds_course::Node *ds_course::AVLTree::double_right_rotate(ds_course::Node *&node)
{
    node->left = single_left_rotate(node->left);
    return single_right_rotate(node);
}