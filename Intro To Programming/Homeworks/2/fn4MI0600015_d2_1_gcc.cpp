/**
*
* Solution to homework assignment 1
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

using namespace std;

bool hasAlternatingBits(unsigned int n);
bool validateInput();

int main() {
    unsigned int n;
    cin >> n;
    if (!validateInput()) {
        cout << "-1";
        return -1;
    }

    string result = hasAlternatingBits(n) == 1 ? "True" : "False";
    cout << result;
}

bool hasAlternatingBits(unsigned int n) {
    unsigned int previousRemainer = -1;

    while(true) {
        if (n % 2 == previousRemainer) {
            return false;
        }

        previousRemainer = n % 2;
        n = n/2;
        if (n == 0) {
            return true;
        }
    }
}

bool validateInput() {
    if (cin.fail()) {
        return false;
    }

    return true;
}

