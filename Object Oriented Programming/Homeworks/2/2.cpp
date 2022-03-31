#include <iostream>
#include <fstream>
#include "StudentCollection.h"

using namespace std;

const char* SAVE_COMMAND = "save";
const char* PRINT_COMMAND = "print";
const char* EDIT_COMMAND = "edit";
const char* SORT_COMMAND = "sort";
const char* SUCCESSFUL_OPERATION_MESSAGE = "Operation successfully executed!";
const char* ERROR_MESSAGE = "Error! Data not in correct format!";
const char* INVALID_COMMAND_MESSAGE = "Invalid command! Please enter a new one!";


int main()
{
    char fileName[100];
    cin.getline(fileName, 100);
    StudentCollection library(fileName);

    char input[100];
    while (true)
    {
        char* command = new char[6];
        cin >> command;

        if (areEqual(command, EDIT_COMMAND))
        {
            int fn;
            char* field = new char[10];
            char* value = new char[20];

            cin >> fn;
            cin >> field;
            cin >> value;

            bool result = library.editStudent(fn, field, value);
            if (!result)
            {
                cout << ERROR_MESSAGE << endl;
            }
            else
            {
                cout << SUCCESSFUL_OPERATION_MESSAGE << endl;
            }

            delete[] field;
            delete[] value;
        }
        else if (areEqual(command, SORT_COMMAND))
        {
            char* field = new char[25];
            cin >> field;
            library.sort(field);
            cout << SUCCESSFUL_OPERATION_MESSAGE << endl;
        }
        else if (areEqual(command, PRINT_COMMAND))
        {
            library.printStudents();
        }
        else if (areEqual(command, SAVE_COMMAND))
        {
            library.saveChanges(fileName);
            break;
        }
        else 
        {
            cout << INVALID_COMMAND_MESSAGE << endl;
            continue;
        }
    }
}