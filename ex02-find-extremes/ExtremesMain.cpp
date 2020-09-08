#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Student.h"

using namespace std;
using namespace ds_course;

int main()
{

    int studentCount;
    cin >> studentCount;

    // Should we use vectors?
    std::vector<Student> student;
    std::string studentInput;

    cin.ignore(10000, '\n');

    int age;
    float height;

    for (int i = 0; i < studentCount; i++)
    {
        cin >> age >> height;
        printf("Age: %i; Height: %f\n", age, height);
    }
}

// Student getMin(Student *ss, int count)
// {
// }

// Student getMax(Student *ss, int count)
// {
// }
