#include <iostream>
#include "Student.h"
#include "StudentCollection.h"

using namespace std;

const char* SUCCESSFULLY_LOADED_FILE_MESSAGE = "File loaded successfully!";

StudentCollection::StudentCollection(char* fileName)
    {
        fstream file(fileName);
        if (!file.is_open())
        {
            return;
        }

        cout << SUCCESSFULLY_LOADED_FILE_MESSAGE << endl;
        studentsCount = getStudentsCount(file);
        data = new Student[studentsCount];
        this->populateData(file);
    }

bool StudentCollection::editStudent(int fn, char* field, char* value)
    {
        for (size_t i = 0; i < studentsCount; i++)
        {
            if (data[i].getFn() == fn)
            {
                if (areEqual(field, "grade"))
                {
                    if (!data[i].setGrade(value))
                    {
                        return false;
                    }

                    return true;
                }
                else if (areEqual(field, (char*)"name"))
                {
                    if (!data[i].setName(value))
                    {
                        return false;
                    }

                    return true;
                }
                else if (areEqual(field, (char*)"age"))
                {
                    if (!data[i].setAge(value))
                    {
                        return false;
                    }

                    return true;
                }
                else if (areEqual(field, (char*)"gender"))
                {
                    if (!data[i].setGender(value))
                    {
                        return false;
                    }

                    return true;
                }
                else if (areEqual(field, (char*)"email"))
                {
                    if (!data[i].setEmail(value))
                    {
                        return false;
                    }

                    return true;
                }
                else if (areEqual(field, (char*)"fn"))
                {
                    if (!data[i].setFn(value))
                    {
                        return false;
                    }

                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }

void StudentCollection::sort(const char* field)
    {
        if (areEqual(field, "grade"))
        {
            sortByGrade();
        }
        else if (areEqual(field, "name"))
        {
            sortByName();
        }
        else if (areEqual(field, "age"))
        {
            sortByAge();
        }
        else if (areEqual(field, "gender"))
        {
            sortByGender();
        }
        else if (areEqual(field, "email"))
        {
            sortByEmail();
        }
        else if (areEqual(field, "fn"))
        {
            sortByFn();
        }
    }

void StudentCollection::printStudents() const
    {
        for (size_t i = 0; i < studentsCount; i++)
        {
            data[i].printStudent();
        }
    }

void StudentCollection::saveChanges(char* fileName) const
    {
        fstream file(fileName);
        if (!file.is_open())
        {
            return;
        }

        for (size_t i = 0; i < studentsCount; i++)
        {
            data[i].saveToFile(file);
        }
    }

void StudentCollection::sortByName()
{
    for (size_t i = 0; i < studentsCount - 1; i++)
    {
        for (size_t j = i + 1; j < studentsCount; j++)
        {
            if (strcomp(data[j].getEmail(), data[i].getEmail()) == 1)
            {
                Student temp = data[i];
                data[i] = data[j];
                data[j] = temp;

                if (i != studentsCount - 1)
                {
                    i--;
                }
                break;
            }
        }
    }
}

void StudentCollection::sortByAge()
{
    for (size_t i = 0; i < studentsCount - 1; i++)
    {
        for (size_t j = i + 1; j < studentsCount; j++)
        {
            if (data[j].getAge() < data[i].getAge())
            {
                int temp = data[i].getAge();
                data[i].setAge(data[j].getAge());
                data[j].setAge(temp);

                if (i != studentsCount - 1)
                {
                    i--;
                }
                break;
            }
        }
    }
}

void StudentCollection::sortByGender()
{
    for (size_t i = 0; i < studentsCount - 1; i++)
    {
        if (strcomp(data[i].getGender(), "Female") == 0)
        {
            continue;
        }

        for (size_t j = i + 1; j < studentsCount; j++)
        {
            if (strcomp(data[j].getGender(), "Female") == 0 && strcomp(data[i].getGender(), "Male") == 0)
            {
                Student temp = data[i];
                data[i] = data[j];
                data[j] = temp;

                if (i != studentsCount - 1)
                {
                    i--;
                }
                break;
            }
        }
    }
}

void StudentCollection::sortByEmail()
    {
        for (size_t i = 0; i < studentsCount - 1; i++)
        {
            for (size_t j = i + 1; j < studentsCount; j++)
            {
                if (strcomp(data[j].getEmail(), data[i].getEmail()) == 1)
                {
                    Student temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;

                    if (i != studentsCount - 1)
                    {
                        i--;
                    }
                    break;
                }
            }
        }
    }

void StudentCollection::sortByFn()
{
    for (size_t i = 0; i < studentsCount - 1; i++)
    {
        for (size_t j = i + 1; j < studentsCount; j++)
        {
            if (data[j].getFn() < data[i].getFn())
            {
                int temp = data[i].getFn();
                data[i].setFn(data[j].getFn());
                data[j].setFn(temp);


                if (i != studentsCount - 1)
                {
                    i--;
                }
                break;
            }
        }
    }
}

void StudentCollection::sortByGrade()
{
    for (size_t i = 0; i < studentsCount - 1; i++)
    {
        for (size_t j = i + 1; j < studentsCount; j++)
        {
            if (data[j].getGrade() < data[i].getGrade())
            {
                double temp = data[i].getGrade();
                data[i].setGrade(data[j].getGrade());
                data[j].setGrade(temp);

                if (i != studentsCount - 1)
                {
                    i--;
                }
                break;
            }
        }
    }
}

void StudentCollection::populateData(fstream& file)
    {
        int studentsFound = 0;

        bool isInStudent = false;
        while (true)
        {
            char line[400];
            file.getline(line, 400);
            if (file.eof())
            {
                file.close();
                break;
            }

            if (!isInStudent)
            {
                // does not work for spaces
                if (isStudentOpenTag(line))
                {
                    isInStudent = true;
                }
                continue;
            }

            if (isInStudent && isStudentClosingTag(line))
            {
                studentsFound++;
                isInStudent = false;
                if (studentsFound == this->studentsCount)
                {
                    break;
                }

                continue;
            }

            char** result = new char* [2];
            int index = 0;
            while (true)
            {
                getTagInfo(line, result, index);
                if (result[0][0] == '0')
                {
                    break;
                }

                char* tagName = result[0];
                char* tagInfo = result[1];

                if (areEqual(tagName, (char*)"grade"))
                {
                    data[studentsFound].setGrade(tagInfo);
                }
                else if (areEqual(tagName, (char*)"name"))
                {
                    data[studentsFound].setName(tagInfo);
                }
                else if (areEqual(tagName, (char*)"age"))
                {
                    data[studentsFound].setAge(tagInfo);
                }
                else if (areEqual(tagName, (char*)"gender"))
                {
                    data[studentsFound].setGender(tagInfo);
                }
                else if (areEqual(tagName, (char*)"email"))
                {
                    data[studentsFound].setEmail(tagInfo);
                }
                else if (areEqual(tagName, (char*)"fn"))
                {
                    data[studentsFound].setFn(tagInfo);
                }

                delete[] tagName;
                delete[] tagInfo;
            }
        }

        file.close();

        // optimize new lines
        // getter
    }

void StudentCollection::getTagInfo(char* line, char** result, int& index) const
    {
        result[0] = new char[25];
        result[1] = new char[25];
        while (line[index] != '\0')
        {
            if (line[index] == '<' && line[index + 1] != '\\')
            {
                int tagLength = countTagLength(line, index + 1);
                getTagName(line, index + 1, result[0]);
                int tagInfoLength = getTagInfo(line, index + tagLength + 2, result[1]);
                index = index + tagLength * 2 + 5 + tagInfoLength;
                return;
            }

            index++;
        }

        result[0][0] = '0';
    }

int StudentCollection::getTagInfo(char* line, int index, char* tagInfo) const
    {
        int i = 0;
        while (line[index] != '<')
        {
            tagInfo[i] = line[index];

            i++;
            index++;
        }
        tagInfo[i] = '\0';

        return i;
    }

void StudentCollection::getTagName(char* line, int index, char* tagName) const
    {
        char result[25];
        int i = 0;
        while (line[index] != '>')
        {
            tagName[i] = line[index];

            index++;
            i++;
        }
        tagName[i] = '\0';
    }

int StudentCollection::countTagLength(char* line, int index) const
    {
        int counter = 0;
        while (line[index] != '>')
        {
            counter++;
            index++;
        }

        return counter;
    }

int StudentCollection::getStudentsCount(fstream& file) const
    {
        char line[50];
        size_t counter = 0;
        while (true)
        {
            file.getline(line, 50);
            if (file.eof())
            {
                break;
            }

            if (isStudentOpenTag(line))
            {
                counter++;
            }
        }

        file.clear();
        file.seekg(0);

        return counter;
    }

bool StudentCollection::isStudentOpenTag(char* text) const
    {
        if (text[0] == '<' && text[1] == 's')
        {
            return true;
        }

        return false;
    }

bool StudentCollection::isStudentClosingTag(char* text) const
    {
        if (text[0] == '<' && text[1] == '\\' && text[2] == 's')
        {
            return true;
        }

        return false;
    }