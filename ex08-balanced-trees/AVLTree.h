#include <iostream>
#include <string>
#include <sstream>

namespace ds_course
{
    class AVLTree
    {
    private:
        int mode;

    public:
        AVLTree(std::string mode);
        ~AVLTree();

        struct Node *mainNode;
        Node *insert(Node *node, std::string word);
        Node *erase(Node *node, std::string word);
        Node *get(Node *node, std::string word);
        Node *locate(Node *node, std::string word, std::string path);
        void dump(Node *node, std::string start, std::string end);
        std::string reverse_string(std::string str);
        int get_height(Node *node);
        Node *find_min(Node *node);
        Node *find_max(Node *node);

        Node *single_right_rotate(Node *&node);
        Node *single_left_rotate(Node *&node);
        Node *double_left_rotate(Node *&node);
        Node *double_right_rotate(Node *&node);
    };

    struct Node
    {
        std::string word;
        int badnessValue;
        struct Node *left;
        struct Node *right;
        int height;

        Node(std::string word)
        {
            this->word = word;
            this->badnessValue = 1;
            this->left = NULL;
            this->right = NULL;
            this->height = 1;
        };
    };
} // namespace ds_course