#include "student.h"
#include <iostream>

using namespace std;

Student::Student(string nimi, int ika)
{
    Name = nimi;
    Age = ika;

}

void Student::setAge(int ika)
{
    Age = ika;
}

void Student::setName(const string &nimi)
{
    Name = nimi;
}

string Student::getName() const
{
    return Name;
}

int Student::getAge() const
{
    return Age;
}

void Student::printStudentInfo()
{
    cout << "Opiskelijan nimi: " << Name << " ja ika: " << Age << endl;

}
