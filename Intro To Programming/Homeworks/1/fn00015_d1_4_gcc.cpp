/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Popov
* @idnumber 4MI0600015
* @task 4
* @compiler GCC
*
*/

#include <iostream>
#include <cmath>

using namespace std;

bool IsInCircle(int centerX, int centerY, double targetX, double targetY, int radius) {
    double realX = abs(centerX - targetX);
    double realY = abs(centerY - targetY);

    double hypotenuse = sqrt(pow(realX, 2) + pow(realY, 2));
    if (hypotenuse <= radius) {
        return true;
    }
    return false;
}

bool IsUndefined(int centerX, int centerY, double targetX, double targetY, int radius) {
    double realX = abs(centerX - targetX);
    double realY = abs(centerY - targetY);

    double hypotenuse = sqrt(pow(realX, 2) + pow(realY, 2));
    if (hypotenuse == radius) {
        return true;
    }
    return false;
}

int main() {
    double x,y;
    cin >> x >> y;

    if (abs(x) > 4 || abs(y) > 4) {
        cout << "Outside";
    }
    else if (abs(x) == 4 || abs(y) == 4) {
        cout << "Undefined";
    }
    else if (!IsInCircle(0, 0, x, y, 4)) {
        if (y <= 0 && IsUndefined(0, 0, x, y, 4)) {
            cout << "Undefined";
        }
        else {
            cout << "White";
        }
    }
    else {
        if (x <= 0) {
            if (IsInCircle(-2, 0, x, y, 1)) {
                if (IsUndefined(-2, 0, x, y, 1)) {
                    cout << "Undefined";
                }
                else {
                    cout << "White";
                }
            }
            else if (IsInCircle(-2, 0, x, y, 2)) {
                if (y >= 0 && IsUndefined(-2, 0, x, y, 2)) {
                    cout << "Undefined";
                }
                else {
                    cout << "Black";
                }
            }
            else if (y < 0) {
                cout << "Black";
            }
            else {
                cout << "White";
            }
        }
        else if (x > 0) {
            if (IsInCircle(2, 0, x, y, 1)) {
                if (IsUndefined(2, 0, x, y, 1)) {
                    cout << "Undefined";
                }
                else {
                    cout << "Black";
                }
            }
            else if (IsInCircle(2, 0, x, y, 2)) {
                if (y < 0 && IsUndefined(2, 0, x, y, 2)) {
                    cout << "Undefined";
                }
                else {
                    cout << "White";
                }
            }
            else if (y < 0) {
                cout << "Black";
            }
            else {
                cout << "White";
            }
        }
    }

    return 0;
}

