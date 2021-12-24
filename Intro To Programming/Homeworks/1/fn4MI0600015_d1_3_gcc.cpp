/**
*
* Solution to homework assignment 1
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
#include <cmath>

using namespace std;

bool validateInput(int numberOfTabs, double salary) {
    if (numberOfTabs < 1 || numberOfTabs > 10) {
        return false;
    }

    if (salary < 700 || salary > 1500) {
        return false;
    }

    return true;
}

int main() {
    int numberOfTabs;
    double salary;

    cin >> numberOfTabs >> salary;
    if (!validateInput(numberOfTabs, salary)) {
        cout << -1 << endl;
        return -1;
    }

    for (int i = 0; i < numberOfTabs; ++i) {
        char input;
        cin >> input;

        if (input == 'F') {
            salary = salary - 150;
        }
        else if (input == 'I') {
            salary = salary - 100;
        }
        else if (input == 'R') {
            salary = salary - 50;
        }

        if (salary <= 0) {
            cout << "You have lost your salary.";
            return 0;
        }
    }

    cout << round(salary);
    return 0;
}