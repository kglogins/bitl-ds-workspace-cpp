#include <string>

namespace ds_course
{
    class Periodic
    {
    public:
        Periodic();
        int findPeriod(unsigned long long n);
        int findPeriod(std::string str);
        int findPeriodHex(unsigned long long n);
    };
} // namespace ds_course
