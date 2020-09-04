#include <string>
#include <iostream>
#include <sstream>
#include "Periodic.h"

using namespace ds_course;
using namespace std;

Periodic::Periodic()
{
}

int Periodic::findPeriod(unsigned long long number)
{

    int periodLength = 1;
    int periodStartIndex = 0;

    std::string stringNumber = to_string(number);
    int stringNumberLength = stringNumber.size();

    if (stringNumberLength == 1)
    {
        return 0;
    }

    for (periodLength; (stringNumberLength / 2) >= periodLength; periodLength++)
    {

        if (stringNumberLength % periodLength == 0)
        {

            for (int i = 1; i <= (stringNumberLength / periodLength); i++)
            {

                int nextPeriodStartIndex = periodStartIndex + (i * periodLength);

                if (stringNumber.substr(periodStartIndex, periodLength) == stringNumber.substr(nextPeriodStartIndex, periodLength))
                {
                    if (nextPeriodStartIndex + periodLength >= stringNumberLength)
                    {
                        return periodLength;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    return 0;
}

int Periodic::findPeriod(std::string word)
{
    int periodLength = 1;
    int periodStartIndex = 0;

    int wordLength = word.size();

    if (wordLength == 1)
    {
        return 0;
    }

    for (periodLength; (wordLength / 2) >= periodLength; periodLength++)
    {

        if (wordLength % periodLength == 0)
        {

            for (int i = 1; i <= (wordLength / periodLength); i++)
            {

                int nextPeriodStartIndex = periodStartIndex + (i * periodLength);

                if (word.substr(periodStartIndex, periodLength) == word.substr(nextPeriodStartIndex, periodLength))
                {
                    if (nextPeriodStartIndex + periodLength >= wordLength)
                    {
                        return periodLength;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    return 0;
}

int Periodic::findPeriodHex(unsigned long long number)
{

    int periodLength = 1;
    int periodStartIndex = 0;

    std::stringstream stream;
    stream << std::hex << number;
    std::string hexString(stream.str());

    int hexStringLength = hexString.size();

    if (hexStringLength == 1)
    {
        return 0;
    }

    for (periodLength; (hexStringLength / 2) >= periodLength; periodLength++)
    {

        if (hexStringLength % periodLength == 0)
        {

            for (int i = 1; i <= (hexStringLength / periodLength); i++)
            {

                int nextPeriodStartIndex = periodStartIndex + (i * periodLength);

                if (hexString.substr(periodStartIndex, periodLength) == hexString.substr(nextPeriodStartIndex, periodLength))
                {
                    if (nextPeriodStartIndex + periodLength >= hexStringLength)
                    {
                        return periodLength;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

    return 0;
}
