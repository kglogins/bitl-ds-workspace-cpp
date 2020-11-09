#include <string>

namespace ds_course
{
    struct Alien
    {
        int value;
        struct Alien *left;
        struct Alien *right;
        Alien(int val)
        {
            this->value = val;
            this->left = NULL;
            this->right = NULL;
        };
    };

    class AlienFamily
    {
    private:
        struct Alien *headNode;
        struct AlienFamily *next;
        int numberOfAliens;
        int traversalPosition = 0;

    public:
        AlienFamily(struct ds_course::Alien *headNode);
        ~AlienFamily();
        void addChild(int parentVal, int childVal, std::string side);
        struct Alien *findAlienByValue(struct ds_course::Alien *alien, int value);
        struct Alien *getHeadNode();
        void lookupAlien(int value);
        void addNewFamily(int headVal);
        void fillInorderArray(struct ds_course::Alien *headNode, int *inorderArray);
    };

} // namespace ds_course