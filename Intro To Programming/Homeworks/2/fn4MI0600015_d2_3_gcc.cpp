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

using namespace std;

bool validateInput();
int findBestRoute(unsigned int n, unsigned int destination, unsigned int operations);

int main() {
    unsigned int n, destination;
    cin >> n >> destination;
    if (!validateInput()) {
        cout << "-1";
        return -1;
    }

    cout <<  findBestRoute(n, destination, 0);
    return 0;
}

int findBestRoute(unsigned int n, unsigned int destination, unsigned int operations) {
    if (destination % 2 == 0) {
        operations++;
        if (n < destination / 2) {
            return findBestRoute(n, destination / 2, operations);
        }
        else {
            operations += n - (destination / 2);
            return operations;
        }
    }
    else {
        while(n < destination) {
            n = n * 2;
            operations++;
        }

        operations += n - destination;
        return operations;
    }
}

bool validateInput() {
    if (cin.fail()) {
        return false;
    }

    return true;
}

