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

using namespace std;

bool validateInput(unsigned int n);
bool isPalidrome(unsigned int n);
int getNumberLength(unsigned int n);

int main() {
    unsigned int n;
    cin >> n;
    if (!validateInput(n)) {
        cout << "-1";
        return -1;
    }

    unsigned int smallerNumber = n - 1;
    unsigned int largerNumber = n + 1;

    if (largerNumber / 100 == 0) {
        cout << 101;
        return 0;
    }

    if (isPalidrome(n)) {
        cout << n;
        return 0;
    }

    while (true) {
        if (isPalidrome(smallerNumber)) {
            cout << smallerNumber;
            return 0;
        }
        if (isPalidrome(largerNumber)) {
            cout << largerNumber;
            return 0;
        }

        largerNumber++;
        smallerNumber--;
    }
}

bool isPalidrome(unsigned int n) {
    int numberOfDigits = getNumberLength(n);

    for (int i = 1; i <= numberOfDigits / 2; ++i) {
        int iterarionPow = pow(10, i);
        int backDigit = (n % iterarionPow) / pow(10, i-1);

        int frontNumber = n / pow(10, numberOfDigits - i);
        int frontDigit = frontNumber % 10;

        if (frontDigit != backDigit) {
            return false;
        }
    }

    return true;
}

int getNumberLength(unsigned int n) {
    int length = 0;

    while (n != 0) {
        n = n/10;
        length++;
    }

    return length;
}

bool validateInput(unsigned int n) {
    if (cin.fail()) {
        return false;
    }

    if (n < 1 || n > pow(10,9)) {
        return false;
    }

    return true;
}

