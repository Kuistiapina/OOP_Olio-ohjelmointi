#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
public:

    Student(string nimi, int ika);
    void setAge(int ika);
    void setName(const string &nimi);
    string getName() const;
    int getAge() const;
    void printStudentInfo();

private:

    string Name;
    int Age;

};

#endif // STUDENT_H
