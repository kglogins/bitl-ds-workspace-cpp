#include <string>

namespace ds_course
{

    class CNode
    {
    private:
        int elem;
        CNode *next;

        friend class CircleList;
    };

    class CircleList
    {
    public:
        CircleList();
        ~CircleList();

        bool empty() const;
        const int &front() const;
        const int &back() const;
        void add(const int &e);
        void remove();
        void advance();
        void retreat();
        int getSize();
        std::string to_str() const;

    private:
        CNode *cursor;
        int size;
    };

    class OutOfBoundsException
    {
    public:
        OutOfBoundsException(const std::string &msg);
        ~OutOfBoundsException();

        std::string getMessage() const;

    private:
        std::string msg;
    };
} // namespace ds_course
