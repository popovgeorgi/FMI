/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Popov
* @idnumber 4MI0600015
* @task 5
* @compiler GCC
*
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string numberAsString;
    cin >> numberAsString;
    int number = stoi(numberAsString);
    int count = 0;

    for (int i = 0; i < numberAsString.length(); ++i) {
        int frontNumber = number / pow(10, numberAsString.length() - i - 1);
        int frontDigit = frontNumber % 10;
        if (frontDigit % 2 == 1) {
            cout << frontDigit;
            count++;
        }
    }

    if (count == 0) {
        cout << 0;
    }

    return 0;
}

