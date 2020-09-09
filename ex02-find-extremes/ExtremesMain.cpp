#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Student.h"

using namespace std;
using namespace ds_course;

Student getMin(Student *ss, int count);
Student getMax(Student *ss, int count);

int main()
{

    int studentsCount;
    cin >> studentsCount;

    Student students[studentsCount];
    std::string studentInput;

    cin.ignore(10000, '\n');

    int age;
    double height;

    for (int i = 0; i < studentsCount; i++)
    {
        cin >> age >> height;

        Student student;
        student.age = age;
        student.height = height;
        students[i] = student;
    }

    Student minStudent = getMin(students, studentsCount);
    Student maxStudent = getMax(students, studentsCount);

    printf("%i %f\n", minStudent.age, minStudent.height);
    printf("%i %f\n", maxStudent.age, maxStudent.height);
}

Student getMin(Student *ss, int count)
{
    Student minStudent = ss[0];

    for (int i = 0; i < count; i++)
    {
        if (minStudent.compareTo(ss[i]) == 1)
        {
            minStudent = ss[i];
        }
    }

    return minStudent;
}

Student getMax(Student *ss, int count)
{
    Student maxStudent = ss[0];

    for (int i = 0; i < count; i++)
    {
        if (maxStudent.compareTo(ss[i]) == -1)
        {
            maxStudent = ss[i];
        }
    }

    return maxStudent;
}
