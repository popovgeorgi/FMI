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

int main() {
    int number;
    cin >> number;

    if (number < 1 || number > 9) {
        cout << -1 << endl;
        return -1;
    }

    for (int i = 1; i <= number; i++) {
        int blankSpaces = i - 1;
        for (int j = 0; j < blankSpaces; ++j) {
            cout << " ";
        }

        for (int j = i; j <= number; ++j) {
            cout << j;
        }

        cout << "\n";
    }

    for (int i = 2; i <= number; ++i) {
        int blankSpaces = number - 1;
        for (int j = 0; j < blankSpaces; ++j) {
            cout << " ";
        }

        for (int j = number; j > number - i; --j) {
            cout << j;
        }

        cout << "\n";
    }

    return 0;
}