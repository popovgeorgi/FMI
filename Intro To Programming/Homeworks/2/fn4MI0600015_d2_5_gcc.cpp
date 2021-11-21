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

using namespace std;

bool validateInput();
void unixToDate(unsigned int unix);
int getNumberLength(unsigned int n);
string format(unsigned int number);

int main() {
    unsigned int unix;
    cin >> unix;
    if (!validateInput()) {
        cout << "-1";
        return -1;
    }

    unixToDate(unix);
}

void unixToDate(unsigned int unix) {
    int seconds = unix % 60;
    int minutes = (unix / 60) % 60;
    int hours = ((unix / 60) / 60) % 24;


    int days = ((unix / 60) / 60) / 24;

    int years = 0;
    if (days > 365 * 4) {
        years = (days / (365 * 4 + 1));
    }

    int remainingDays = days - years * (365 * 4 + 1);
    years = years * 4 + remainingDays / 365;

    days = remainingDays % 365;

    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sum = 0;
    int month = 0;
    int daysInMonth = days;
    for (int i = 0; i < sizeof(daysInMonths); ++i) {
        sum += daysInMonths[i];
        if (days > sum) {
            daysInMonth -= daysInMonths[i];
            continue;
        }
        else {
            month = i + 1;
            break;
        }
    }

    string dot = ".";
    years = years + 1970;

    cout << format(daysInMonth) << "." << format(month) << "." << years << " " << format(hours) << ":" << format(minutes) << ":" << format(seconds);
}

string format(unsigned int number) {
    if (getNumberLength(number) <= 1) {
        string numberAsString = to_string(number);
        string zeroAsString = "0";
        string newNumber = zeroAsString.append(numberAsString);
        return newNumber;
    }

    return to_string(number);
}

int getNumberLength(unsigned int n) {
    int length = 0;

    while (n != 0) {
        n = n/10;
        length++;
    }

    return length;
}

bool validateInput() {
    if (cin.fail()) {
        return false;
    }

    return true;
}

