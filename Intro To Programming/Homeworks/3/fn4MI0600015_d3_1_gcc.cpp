/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Popov
* @idnumber 4MI0600015
* @task 1
* @compiler GCC
*
*/

#include <iostream>
#include <math.h>

using namespace std;

bool validateInput(int n);
bool isCorrect(char sequence[][20], int sequenceSize);
int strlen(char arr[]);
bool checkForChangeInLetters(char* current, char* next);
bool checkForAddedLetter(char* current, char* next);
bool checkForRemovedLetter(char* current, char* next);

int main() {
    int n;
    cin >> n;
    if (!validateInput(n)) {
        cout << "1";
        return 1;
    }
    char sequence[n][20];
    cin.ignore();

    int i = 0;
    while (i < n) {
        cin.getline(sequence[i], 20);
        i++;
    }

    bool result = isCorrect(sequence, n);
    if (result == false) {
        cout << "false";
    }
    else {
        cout << "true";
    }
    return 0;
}

bool isCorrect(char sequence[][20], int sequenceSize) {
    for (int i = 0; i < sequenceSize - 1; ++i) {
        char* current = sequence[i];
        char* next;

        next = sequence[i + 1];

        if (abs(strlen(current) - strlen(next)) > 1) {
            return false;
        }
        else if (abs(strlen(current) - strlen(next)) == 0) {
            if (!checkForChangeInLetters(current, next)) {
                return false;
            }
        }
        else {
            if (strlen(current) > strlen(next)) {
                if (!checkForRemovedLetter(current, next)) {
                    return false;
                }
            }
            else {
                if (!checkForAddedLetter(current, next)) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool checkForRemovedLetter(char* current, char* next) {
    int mismatches = 0;

    for (int i = 0, j = 0; i < strlen(current); ++i, ++j) {
        if (current[j] != next[i]) {
            mismatches++;
            if (mismatches > 1) {
                return false;
            }
            i--;
        }
    }

    return true;
}

bool checkForAddedLetter(char* current, char* next) {
    int mismatches = 0;

    for (int i = 0, j = 0; j < strlen(next); ++j, ++i) {
        if (current[i] != next[j]) {
            mismatches++;
            if (mismatches > 1) {
                return false;
            }
            i--;
        }
    }

    return true;
}

bool checkForChangeInLetters(char* current, char* next) {
    int different = 0;

    for (int i = 0; i < strlen(current); ++i) {
        if (current[i] != next[i]) {
            different++;
            if (different > 1) {
                return false;
            }
        }
    }

    if (different == 0) return false;

    return true;
}

int strlen(char arr[])
{
    int counter = 0;
    int i = 0;
    while (arr[i] != '\0')
    {
        counter++;
        i++;
    }
    return counter;
}

bool validateInput(int n) {
    if (n <= 1 || n >= 19) {
        return false;
    }

    return true;
}

