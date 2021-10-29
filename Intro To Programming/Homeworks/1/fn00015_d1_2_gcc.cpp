/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Popov
* @idnumber 4MI0600015
* @task 2
* @compiler GCC
*
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string numberAsString;
    cin >> numberAsString;

    int number = stoi(numberAsString);
    if (number < 1 || number > pow(10,9)) {
        cout << -1 << endl;
        return -1;
    }

    bool hasEvenNumberOfDigits = numberAsString.length() % 2 == 0 ? true : false;
    int numberOfOperations = numberAsString.length() / 2;

    for (int i = 0; i < numberOfOperations; ++i) {
        int backNumber = number / pow(10, i);
        int backDigit = backNumber % 10;

        int frontNumber = number / pow(10, numberAsString.length() - i - 1);
        int frontDigit = frontNumber % 10;
        if (frontDigit > backDigit) {
            cout << frontDigit;
            cout << " ";
        }
        else if (backDigit > frontDigit) {
            cout << backDigit;
            cout << " ";
        }
    }

    if (!hasEvenNumberOfDigits) {
        int wholeNumber = number / pow(10, numberOfOperations);
        cout <<  wholeNumber % 10;
    }

    return 0;
}

