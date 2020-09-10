#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
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

    cout << minStudent.age << " " << fixed << setprecision(5) << minStudent.height << endl;
    cout << maxStudent.age << " " << fixed << setprecision(5) << maxStudent.height << endl;
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
