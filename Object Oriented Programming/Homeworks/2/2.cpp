#include <iostream>
#include <fstream>
#include "helper.h"

using namespace std;

class Student
{
    char name[25];
    int fn;
    int age;
    char gender[6];
    char email[25];
    float grade;

public:
    void printStudent()
    {
        cout << "Name: " << name << endl;
        cout << "Fn: " << fn << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Email: " << email << endl;
        cout << "Grade: " << grade << endl;
        cout << endl;
    }

    void saveToFile(fstream& file)
    {
        file << "<student>" << std::endl;
        file << '\t' << "<name>" << name << "<\\name>" << std::endl;
        file << '\t' << "<fn>" << fn << "<\\fn>" << std::endl;
        file << '\t' << "<age>" << age << "<\\age>" << std::endl;
        file << '\t' << "<gender>" << gender << "<\\gender>" << std::endl;
        file << '\t' << "<email>" << email << "<\\email>" << std::endl;
        file << '\t' << "<grade>" << grade << "<\\grade>" << std::endl;
        file << "<\\student>" << std::endl;
        file << std::endl;
    }

    char* getName()
    {
        return name;
    }

    char* getGender()
    {
        return gender;
    }

    char* getEmail()
    {
        return email;
    }

    int getFn()
    {
        return fn;
    }

    int getAge()
    {
        return age;
    }

    float getGrade()
    {
        return grade;
    }

    bool setGender(char* str)
    {
        if (strcomp(str, (char*)"Male") && strcomp(str, (char*)"Female"))
        {
            return false;
        }

        strcopy(str, this->gender);

        return true;
    }

    bool setName(char* str)
    {
        if (strlen(str) > 25)
        {
            return false;
        }

        strcopy(str, this->name);

        return true;
    }

    bool setEmail(char* str)
    {
        if (strlen(str) > 25 || !containsMonkey(str))
        {
            return false;
        }

        strcopy(str, this->email);

        return true;
    }

    bool setFn(char* str)
    {
        //validation
        fn = getIntFromString(str);

        return true;
    }

    bool setFn(int fn)
    {
        this->fn = fn;
        return true;
    }

    bool setGrade(char* str)
    {
        //validation
        grade = getDoubleFromString(str);

        return true;
    }

    bool setAge(char* str)
    {
        int age = getIntFromString(str);
        if (age < 15 || age > 65)
        {
            return false;
        }

        this->age = age;

        return true;
    }
};

struct StudentCollection
{
    Student* data;
    size_t studentsCount;

    StudentCollection(char* fileName)
    {
        fstream file(fileName);
        if (!file.is_open())
        {
            return;
        }

        studentsCount = getStudentsCount(file);
        data = new Student[studentsCount];
        this->populateData(file);
    }

    bool editStudent(int fn, char* field, char* value)
    {
        for (size_t i = 0; i < studentsCount; i++)
        {
            if (data[i].getFn() == fn)
            {
                if (areEqual(field, (char*)"grade"))
                {
                    if (!data[i].setGrade(value))
                    {
                        return false;
                    }
                }
                else if (areEqual(field, (char*)"name"))
                {
                    if (!data[i].setName(value))
                    {
                        return false;
                    }
                }
                else if (areEqual(field, (char*)"age"))
                {
                    if (!data[i].setAge(value))
                    {
                        return false;
                    }
                }
                else if (areEqual(field, (char*)"gender"))
                {
                    if (!data[i].setGender(value))
                    {
                        return false;
                    }
                }
                else if (areEqual(field, (char*)"email"))
                {
                    if (!data[i].setEmail(value))
                    {
                        return false;
                    }
                }
                else if (areEqual(field, (char*)"fn"))
                {
                    if (!data[i].setFn(value))
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    void sort(char* field)
    {
        if (areEqual(field, (char*)"grade"))
        {
            
        }
        else if (areEqual(field, (char*)"name"))
        {
        }
        else if (areEqual(field, (char*)"age"))
        {
            
        }
        else if (areEqual(field, (char*)"gender"))
        {
            
        }
        else if (areEqual(field, (char*)"email"))
        {
            sortByEmail();
        }
        else if (areEqual(field, (char*)"fn"))
        {
            sortByFn();
        }
    }

    void printStudents()
    {
        for (size_t i = 0; i < studentsCount; i++)
        {
            data[i].printStudent();
        }
    }

    void saveChanges(char* fileName)
    {
        fstream file(fileName, ios::trunc);
        if (!file.is_open())
        {
            return;
        }

        for (size_t i = 0; i < studentsCount; i++)
        {
            data[i].saveToFile(file);
        }
    }

private:
    void sortByName();

    void sortByAge();

    void sortByGender();

    void sortByEmail()
    {
        for (size_t i = 0; i < studentsCount - 1; i++)
        {
            for (size_t j = i + 1; j < studentsCount; j++)
            {
                if (strcomp(data[j].getEmail(), data[i].getEmail()) == 1)
                {
                    char temp[50];
                    strcopy(data[i].getEmail(), temp);
                    //why this does not work
                    //char* temp = data[i].getEmail();
                    data[i].setEmail(data[j].getEmail());
                    data[j].setEmail(temp);

                    if (i != studentsCount - 1)
                    {
                        i--;
                    }
                    break;
                }
            }
        }
    }

    void sortByFn()
    {
        for (size_t i = 0; i < studentsCount - 1; i++)
        {
            int firstStudentFn = data[i].getFn();

            for (size_t j = i + 1; j < studentsCount; j++)
            {
                int secondStudentFn = data[j].getFn();

                if (secondStudentFn < firstStudentFn)
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

    void sortByGrade();

    void populateData(fstream& file)
    {
        int studentsFound = 0;

        bool isInStudent = false;
        while (true)
        {
            char line[200];
            file.getline(line, 200);
            if (file.eof())
            {
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

            char** result = new char*[2];
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
            
        // optimize new lines
        // getter
    }

    void getTagInfo(char* line, char** result, int& index)
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

    int getTagInfo(char* line, int index, char* tagInfo)
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

    void getTagName(char* line, int index, char* tagName)
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

    int countTagLength(char* line, int index)
    {
        int counter = 0;
        while (line[index] !='>')
        {
            counter++;
            index++;
        }

        return counter;
    }

    int getStudentsCount(fstream& file)
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

        file.seekg(0);

        return counter;
    }

    bool isStudentOpenTag(char* text)
    {
        if (text[0] == '<' && text[1] == 's')
        {
            return true;
        }

        return false;
    }

    bool isStudentClosingTag(char* text)
    {
        if (text[0] == '<' && text[1] == '\\' && text[2] == 's')
        {
            return true;
        }

        return false;
    }
};

int main()
{
    // const strings should be constants
    StudentCollection library((char*)"students.xml-fmi.txt");

    char input[100];
    while (true)
    {
        char* command = new char[6];
        cin >> command;

        if (areEqual(command, (char*)"edit"))
        {
            int fn;
            // do they need to be dynamic
            char* field = new char[10];
            char* value = new char[20];

            cin >> fn;
            cin >> field;
            cin.getline(value, 20);

            bool result = library.editStudent(fn, field, value);
            if (!result)
            {
                //error
            }
            else
            {
                cout << "good job";
            }

            delete[] field;
            delete[] value;
        }
        else if (areEqual(command, (char*)"sort"))
        {
            char* field = new char[25];
            cin >> field;
            library.sort(field);
        }
        else if (areEqual(command, (char*)"print"))
        {
            library.printStudents();
        }
        else if (command == "save")
        {
            library.saveChanges((char*)"students.xml-fmi.txt");
            break;
        }
    }
}