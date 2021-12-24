/**
*
* Solution to homework assignment 3
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
#include <vector>

using namespace std;

int strlen(const char str[]);

int main() {
    char input[500];
    cin.getline(input, 500);
    if (strlen(input) > 255) {
        cout << "-1";
        return -1;
    }
    if (strlen(input) % 2 == 1) {
        cout << "No";
        return 0;
    }

    vector<char> lowerLetters;
    vector<char> upperLetters;

    int index = 0;
    while (input[index] != '\0') {
        char symbol = input[index];
        if (symbol >= 65 && symbol <= 90) {
            upperLetters.push_back(symbol);
        }
        else if (symbol >= 97 && symbol <= 123) {
            lowerLetters.push_back(symbol);
        }
        index++;
    }

    if (lowerLetters.size() != upperLetters.size()) {
        cout << "No";
        return 0;
    }

    for (int i = 0; i < lowerLetters.size(); ++i) {
        if (lowerLetters[i] - 32 != upperLetters[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}

int strlen(const char arr[])
{
    int counter = 0;
    int i = 0;
    while (arr[i] != '\0')
    {
        counter++;
        i++;
    }
    return counter;
}
