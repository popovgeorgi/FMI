/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Popov
* @idnumber 4MI0600015
* @task 3
* @compiler GCC
*
*/

#include <iostream>

using namespace std;

bool validateInput(int x, int y, int maxCombinations);

int main() {
    int x, y, maxCombinations, currentX = 1, currentY = 1;
    cin >> x >> y >> maxCombinations;
    if (!validateInput(x, y, maxCombinations)) {
        cout << "-1";
        return -1;
    }

    int numberOfPasswords = x * y > maxCombinations ? maxCombinations : x * y;
    for (int i = 0; i < numberOfPasswords; ++i) {
        char firstSymbol = 35 + i;
        if (firstSymbol > 55) {
            int overflows = (firstSymbol - 35) / 21;
            firstSymbol -= overflows * 21;
        }
        char secondSymbol = 64 + i;
        if (secondSymbol > 96) {
            int overflows = (secondSymbol - 64) / 33;
            secondSymbol -= overflows * 33;
        }

        cout << firstSymbol << secondSymbol << currentX << currentY << secondSymbol << firstSymbol << "|";
        if (y > currentY) {
            currentY++;
        }
        else {
            currentX++;
            currentY = 1;
        }
    }

    return 0;
}

bool validateInput(int x, int y, int maxCombinations) {
    if (x < 1 || x > 1000) {
        return false;
    }
    if (y < 1 || y > 1000) {
        return false;
    }
    if (maxCombinations < 1 || maxCombinations > 1000000) {
        return false;
    }

    return true;
}

