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

int ds_course::AVLTree::compare_words(std::string a, std::string b)
{
    if (this->mode == 0)
    {
        return compare_LEX(a, b);
    }
    else if (this->mode == 1)
    {
        return compare_SHORTLEX(a, b);
    }
    else if (this->mode == 2)
    {
        return compare_COLEX(a, b);
    }
    else
    {
        printf("Error in ordering\n");
        return -1;
    }
}

int ds_course::AVLTree::max(int left, int right)
{
    if (right < left)
        return left;
    return right;
}

ds_course::Node *ds_course::AVLTree::insert(ds_course::Node *node, std::string word)
{
    if (node == NULL)
    {
        node = new ds_course::Node(word);
        return node;
    }

    int compareResult = compare_words(word, node->word);

    if (compareResult == 0)
    {
        node->left = insert(node->left, word);
    }
    else if (compareResult == 1)
    {
        node->right = insert(node->right, word);
    }
    else
    {
        node->badnessValue++;
        return node;
    }

    node->height = ds_course::AVLTree::max(get_height(node->left), get_height(node->right)) + 1;

    int balance = get_balance(node);

    if (balance > 1)
    {
        if (compare_words(word, node->left->word) == 0)
        {
            return single_right_rotate(node);
        }
    }

    if (balance < -1)
    {
        if (compare_words(word, node->right->word) == 1)
        {
            return single_left_rotate(node);
        }
    }

    if (balance > 1)
    {
        if (compare_words(word, node->left->word) == 1)
        {
            node->left = single_left_rotate(node->left);
            return single_right_rotate(node);
        }
    }

    if (balance < -1)
    {
        if (compare_words(word, node->right->word) == 0)
        {
            node->right = single_right_rotate(node->right);
            return single_left_rotate(node);
        }
    }

    return node;
}

int ds_course::AVLTree::get_balance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return get_height(node->left) - get_height(node->right);
}

ds_course::Node *ds_course::AVLTree::erase(Node *node, std::string word)
{
    if (node == NULL)
    {
        return node;
    }

    int compareResult = compare_words(word, node->word);

    if (compareResult == 0)
    {
        node->left = erase(node->left, word);
    }
    else if (compareResult == 1)
    {
        node->right = erase(node->right, word);
    }
    else
    {
        if ((node->left == NULL) || (node->right == NULL))
        {
            ds_course::Node *temp = NULL;

            if (node->left != NULL)
            {
                temp = node->left;
                *node = *temp;
            }
            else if (node->right != NULL)
            {
                temp = node->right;
                *node = *temp;
            }
            else
            {
                temp = node;
                node = NULL;
            }
            free(temp);
        }
        else
        {
            ds_course::Node *temp = find_min(node->right);

            node->word = temp->word;
            node->badnessValue = temp->badnessValue;

            node->right = erase(node->right, temp->word);
        }
    }

    if (node == NULL)
    {
        return node;
    }

    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;

    int balance = get_balance(node);

    if (balance > 1 && get_balance(node->left) >= 0)
    {
        return single_right_rotate(node);
    }

    if (balance > 1 && get_balance(node->left) < 0)
    {
        node->left = single_left_rotate(node->left);
        return single_right_rotate(node);
    }

    if (balance < -1 && get_balance(node->right) <= 0)
    {
        return single_left_rotate(node);
    }

    if (balance < -1 && get_balance(node->right) > 0)
    {
        node->right = single_right_rotate(node->right);
        return single_left_rotate(node);
    }

    return node;
}

ds_course::Node *ds_course::AVLTree::get(ds_course::Node *node, std::string word)
{
    if (node == NULL)
    {
        return NULL;
    }

    int compareResult = compare_words(word, node->word);

    if (compareResult == 0)
    {
        return get(node->left, word);
    }
    else if (compareResult == 2)
    {
        return node;
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

    int compareResult = compare_words(word, node->word);

    if (compareResult == 2)
    {
        std::cout << " " << path;
        return node;
    }
    else if (compareResult == 0)
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

    dump(node->left, start, end);

    if (start.compare("_") == 0 && end.compare("_") == 0)
    {
        std::cout << " (" << node->word << "," << node->badnessValue << ")";
    }
    else if (start.compare("_") == 0)
    {
        if (compare_words(end, node->word) == 1 || end == node->word)
        {
            std::cout << " (" << node->word << "," << node->badnessValue << ")";
        }
    }
    else if (end.compare("_") == 0)
    {
        if (compare_words(start, node->word) == 0 || start == node->word)
        {
            std::cout << " (" << node->word << "," << node->badnessValue << ")";
        }
    }
    else
    {
        int compareStartResult = compare_words(start, node->word);
        int compareEndResult = compare_words(end, node->word);

        if (((compareStartResult == 0) || (start == node->word)) && ((compareEndResult == 1) || (end == node->word)))
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
    return (node == NULL ? 0 : node->height);
}

ds_course::Node *ds_course::AVLTree::find_min(ds_course::Node *node)
{
    ds_course::Node *temp = node;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
    // if (node == NULL)
    // {
    //     return NULL;
    // }
    // else if (node->left == NULL)
    // {
    //     return node;
    // }
    // else
    // {
    //     return find_min(node->left);
    // }
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

int ds_course::AVLTree::compare_lower_case(char a, char b)
{
    bool aIsUpper = false;
    bool bIsUpper = false;

    if (a < 91 && a > 64)
    {
        aIsUpper = true;
        a = a + 32;
    }

    if (b < 91 && b > 64)
    {
        bIsUpper = true;
        b = b + 32;
    }

    if (a < b)
    {
        return -1;
    }

    if (a > b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ds_course::AVLTree::compare_upper_case(char a, char b)
{
    bool aIsUpper = false;
    bool bIsUpper = false;

    if (a < 91 && a > 64)
    {
        aIsUpper = true;
        a = a + 32;
    }

    if (b < 91 && b > 64)
    {
        bIsUpper = true;
        b = b + 32;
    }

    if (aIsUpper == true && bIsUpper == false)
    {
        return -1;
    }

    if (aIsUpper == false && bIsUpper == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ds_course::AVLTree::compare_LEX(std::string a, std::string b)
{
    int lenA = a.length();
    int lenB = b.length();
    int minLen = 0, i = 0, j = 0, resultLower = 0, resultUpper = 0;

    if (lenA < lenB || lenA == lenB)
    {
        minLen = lenA;
    }
    else
    {
        minLen = lenB;
    }

    while (i < minLen)
    {
        resultLower = ds_course::AVLTree::compare_lower_case(a[i], b[i]);
        if (resultLower == -1)
        {
            return 0;
        }

        if (resultLower == 1)
        {
            return 1;
        }

        if (i == minLen - 1 && resultLower == 0)
        {
            if (lenA < lenB)
            {
                return 0;
            }

            if (lenA > lenB)
            {
                return 1;
            }

            j = 0;
            while (j < minLen)
            {
                resultUpper = ds_course::AVLTree::compare_upper_case(a[j], b[j]);
                if (resultUpper == -1)
                {
                    return 0;
                }

                if (resultUpper == 1)
                {
                    return 1;
                }

                if (j == minLen - 1 && resultUpper == 0)
                {
                    return 2;
                }
                j++;
            }
        }
        i++;
    }
    return 2;
}

int ds_course::AVLTree::compare_SHORTLEX(std::string a, std::string b)
{
    if (a == b)
        return 2;

    if (a.length() < b.length())
        return 0;

    if ((a.length() == b.length()) && ds_course::AVLTree::compare_LEX(a, b) == 0)
        return 0;

    return 1;
}

int ds_course::AVLTree::compare_COLEX(std::string a, std::string b)
{
    a = ds_course::AVLTree::reverse_string(a);
    b = ds_course::AVLTree::reverse_string(b);

    if (ds_course::AVLTree::compare_LEX(a, b) == 0)
    {
        return 0;
    }
    else if (ds_course::AVLTree::compare_LEX(a, b) == 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

ds_course::Node *ds_course::AVLTree::single_right_rotate(ds_course::Node *node)
{
    ds_course::Node *x = node->left;
    ds_course::Node *T2 = x->right;

    x->right = node;
    node->left = T2;

    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    x->height = std::max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

ds_course::Node *ds_course::AVLTree::single_left_rotate(ds_course::Node *node)
{
    ds_course::Node *y = node->right;
    ds_course::Node *T2 = y->left;

    y->left = node;
    node->right = T2;

    node->height = std::max(get_height(node->left), get_height(node->right)) + 1;
    y->height = std::max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}
