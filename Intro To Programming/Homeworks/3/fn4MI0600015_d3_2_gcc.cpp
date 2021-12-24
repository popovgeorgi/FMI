/**
*
* Solution to homework assignment 3
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
#include <vector>
#include <algorithm>

using namespace std;

int longestDist(int arr[], int arrSize);
int occuranceIndex(int arr[], int numberIndex, int arrSize);

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = longestDist(arr, n);
    cout << result;

    return 0;
}

int longestDist(int arr[], int arrSize) {
    if (arrSize < 2) {
        return -2;
    }
    int bestResult = -1;
    int bestIndex = -1;

    vector<int> checkedDigits;

    for (int i = 0; i < arrSize; ++i) {
        if (count(checkedDigits.begin(), checkedDigits.end(), arr[i]))
        {
            continue;
        }
        int occurance = occuranceIndex(arr, i, arrSize);
        if (occurance > bestResult) {
            bestResult = occurance;
            bestIndex = i;
        }

        checkedDigits.push_back(arr[i]);
    }

    return bestIndex;
}

int occuranceIndex(int arr[], int numberIndex, int arrSize) {
    int farthestOccurance = -1;
    
    int number = arr[numberIndex];
    for (int i = numberIndex + 1; i < arrSize; ++i) {
        if (arr[i] == number) {
            farthestOccurance = i - numberIndex - 1;
        }
    }
    
    return farthestOccurance;
}

