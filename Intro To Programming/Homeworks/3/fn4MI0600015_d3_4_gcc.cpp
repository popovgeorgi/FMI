/**
*
* Solution to homework assignment 3
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

using namespace std;

int longestSubstrWithUniqueSymbolsLength(const char str[]);
int strlen(const char str[]);

int main() {
    char input[100];
    cin.getline(input, 100);
    int result = longestSubstrWithUniqueSymbolsLength(input);
    cout << result;

    return 0;
}

int longestSubstrWithUniqueSymbolsLength(const char str[]) {
    int bestResult = 1, index = 0;
    while (str[index + 1] != '\0') {
        char currentElement = str[index];

        int streak = 1;
        for (int i = index + 1; i < strlen(str); ++i) {
            if (currentElement != str[i]) {
                streak++;
                currentElement = str[i];
            }
            else {
                break;
            }
        }

        if (streak >= strlen(str) / 2) {
            return streak;
        }
        if (streak > bestResult) {
            bestResult = streak;
        }
        index++;
    }

    return bestResult;
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