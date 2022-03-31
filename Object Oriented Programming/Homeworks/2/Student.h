#pragma once
#include <iostream>
#include <fstream>
#include "Helper.h"

using namespace std;

class Student
{
    char name[25];
    int fn;
    int age;
    char gender[7];
    char email[25];
    float grade;

public:
    const char* getName() const;
    const char* getGender() const;
    const char* getEmail() const;
    int getFn() const;
    int getAge() const;
    double getGrade() const;

    bool setGender(const char* str);
    bool setName(const char* str);
    bool setEmail(const char* str);
    bool setFn(const char* str);
    bool setFn(int fn);
    bool setGrade(const char* str);
    bool setGrade(double str);
    bool setAge(const char* str);
    bool setAge(int age);

    void printStudent() const;
    void saveToFile(fstream& file) const;
};
