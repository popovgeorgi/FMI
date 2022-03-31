#include <iostream>
#include <fstream>
#include "Helper.h"
#include "Student.h"

using namespace std;

void Student::printStudent() const
{
    cout << "Name: " << name << endl;
    cout << "Fn: " << fn << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Email: " << email << endl;
    cout << "Grade: " << grade << endl;
    cout << endl;
}

void Student::saveToFile(fstream& file) const
{
    file << "<student>" << std::endl;
    file << '\t' << "<name>" << name << "<\\name>" << endl;
    file << '\t' << "<fn>" << fn << "<\\fn>" << endl;
    file << '\t' << "<age>" << age << "<\\age>" << endl;
    file << '\t' << "<gender>" << gender << "<\\gender>" << endl;
    file << '\t' << "<email>" << email << "<\\email>" << endl;
    file << '\t' << "<grade>" << grade << "<\\grade>" << endl;
    file << "<\\student>" << endl;
    file << endl;
}

const char* Student::getName() const
{
    return name;
}

const char* Student::getGender() const
{
    return gender;
}

const char* Student::getEmail() const
{
    return email;
}

int Student::getFn() const
{
    return fn;
}

int Student::getAge() const
{
    return age;
}

double Student::getGrade() const
{
    return grade;
}

bool Student::setGender(const char* str)
{
    if (strcomp(str, (char*)"Male") == false && strcomp(str, (char*)"Female") == false)
    {
        return false;
    }

    strcopy(str, this->gender);

    return true;
}

bool Student::setName(const char* str)
{
    if (strlen(str) > 25)
    {
        return false;
    }

    strcopy(str, this->name);

    return true;
}

bool Student::setEmail(const char* str)
{
    if (strlen(str) > 25 || !containsMonkey(str))
    {
        return false;
    }

    strcopy(str, this->email);

    return true;
}

bool Student::setFn(const char* str)
{
    fn = getIntFromString(str);
    this->fn = fn;
    return true;
}

bool Student::setFn(int fn)
{
    this->fn = fn;
    return true;
}

bool Student::setGrade(const char* str)
{
    grade = getDoubleFromString(str);
    if (grade < 2 || grade > 6)
    {
        return false;
    }

    return true;
}

bool Student::setGrade(double grade)
{
    if (grade < 2 || grade > 6)
    {
        return false;
    }

    return true;
}

bool Student::setAge(const char* str)
{
    int age = getIntFromString(str);
    if (age < 15 || age > 65)
    {
        return false;
    }

    this->age = age;

    return true;
}

bool Student::setAge(int age)
{
    if (age < 15 || age > 65)
    {
        return false;
    }

    this->age = age;

    return true;
}