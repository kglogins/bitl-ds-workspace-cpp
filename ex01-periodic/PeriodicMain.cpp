#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Periodic.h"

using namespace std;
using namespace ds_course;

int main()
{
    Periodic per;
    string mode;
    cin >> mode;
    std::string inputString;
    unsigned long long int inputDec;
    unsigned long long int inputHex;

    //cout << '\'' << mode << '\'' << endl;
    cin.ignore(10000, '\n');

    std::string inputLine;
    while (getline(cin, inputLine))
    {
        istringstream sstr(inputLine);
        if (sstr.peek() == '#')
        {
            continue;
        }
        else
        {
            if (mode == "dec")
            {
                sstr >> inputDec;
                int res = per.findPeriod(inputDec);
                cout << inputDec << " " << res << endl;
            }
            else if (mode == "str")
            {
                sstr >> inputString;
                int res = per.findPeriod(inputString);
                cout << inputString << " " << res << endl;
            }
            else if (mode == "hex")
            {
                sstr >> hex >> inputHex;
                int res = per.findPeriodHex(inputHex);

                std::stringstream stream;
                stream << std::hex << inputHex;
                std::string numberString(stream.str());

                cout << numberString << " " << res << endl;
            }
        }
    }
}
