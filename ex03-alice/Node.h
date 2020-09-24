#include <vector>

namespace ds_course
{
    struct Node
    {
    private:
        int val;
        std::vector<Node> children;

    public:
        Node(int vv);
        void addChild(Node nn);
        void reflect();
        void printPreorder();
        int getVal();
        std::vector<int> getChildren();
    };
} // namespace ds_course