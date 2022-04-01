#pragma once
#include <iostream>
#include "Student.h"

using namespace std;

struct StudentCollection
{
    Student* data;
    size_t studentsCount;
    bool isFileLoaded = false;

    StudentCollection(char* fileName);

    bool editStudent(int fn, char* field, char* value);

    void sort(const char* field);

    void printStudents() const;

    void saveChanges(char* fileName) const;

private:
    void sortByName();
    void sortByAge();
    void sortByGender();
    void sortByEmail();
    void sortByFn();
    void sortByGrade();

    void getTagInfo(char* line, char** result, int& index) const;
    int getTagInfo(char* line, int index, char* tagInfo) const;
    void getTagName(char* line, int index, char* tagName) const;

    int countTagLength(char* line, int index) const;
    bool isStudentOpenTag(char* text) const;
    bool isStudentClosingTag(char* text) const;

    void populateData(fstream& file);
    int getStudentsCount(fstream& file) const;
};