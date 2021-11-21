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
#include <vector>
#include <algorithm>

using namespace std;

int getNumberLength(unsigned int n);
vector<unsigned int> getCommonDigits(unsigned int n, unsigned int k);
bool areAllCommonDigitsAtTheStart(vector<unsigned int> commonDigits, unsigned int n);
int numbersOfMatchesAfterPlacing(vector<unsigned int> commonDigits, int lengthOfK, int kAsArray[]);

int main() {
    unsigned int n, k, operations = 0;
    cin >> n >> k;

    int lengthOfN = getNumberLength(n);
    int lengthOfK = getNumberLength(k);
    int nAsArray[lengthOfN], kAsArray[lengthOfK];

    for (int i = 1; i <= lengthOfN; ++i) {
        int frontNumber = n / pow(10, lengthOfN - i);
        int frontDigit = frontNumber % 10;

        nAsArray[i - 1] = frontDigit;
    }
    for (int i = 1; i <= lengthOfK ; ++i) {
        int frontNumber = k / pow(10, lengthOfK - i);
        int frontDigit = frontNumber % 10;

        kAsArray[i - 1] = frontDigit;
    }

    // look for matches
    for (int i = 0; i < lengthOfK; ++i) {
        if (kAsArray[i] == nAsArray[i]) {
            kAsArray[i] = -1;
            nAsArray[i] = -1;
        }
    }

    vector<unsigned int> commonDigits = getCommonDigits(n, k);

    // look for symmetry
    for (int i = 0; i <= lengthOfK / 2; ++i) {
        int corenspondingNumber = nAsArray[i];
        if (find(commonDigits.begin(), commonDigits.end(), corenspondingNumber) != commonDigits.end() == false) {
            continue;
        }
        else {
            int numberFromK = kAsArray[i];
            bool foundSymmetry = false;

            for (int j = i + 1; j < lengthOfK; ++j) {
                if (kAsArray[j] == corenspondingNumber) {
                    if (nAsArray[j] == numberFromK) {
                        nAsArray[j] = -1;
                        nAsArray[j] = -1;
                        foundSymmetry = true;
                        operations++;
                        break;
                    }
                }
            }

            if (foundSymmetry) {
                nAsArray[i] = -1;
                kAsArray[i] = -1;
            }
        }
    }

    if (areAllCommonDigitsAtTheStart(commonDigits, n)) {
        int commonDigitsSize = commonDigits.size();
        operations += abs(commonDigitsSize - lengthOfK);
        int matches = numbersOfMatchesAfterPlacing(commonDigits, lengthOfK, kAsArray);
        operations += lengthOfK - matches;
    }
    else {
        if (commonDigits.size() == lengthOfK) {
            operations += lengthOfN;
        }

        // :)
    }

    cout << operations;

    return 0;
}

int numbersOfMatchesAfterPlacing(vector<unsigned int> commonDigits, int lengthOfK, int kAsArray[]) {
    int result = 0;
    vector<int> leftNumbers;

    for (int i = 0; i < lengthOfK; ++i) {
        if (kAsArray[i] == -1) continue;
        if (find(commonDigits.begin(), commonDigits.end(), kAsArray[i]) != commonDigits.end() == false) {
            leftNumbers.push_back(kAsArray[i]);
        }
    }

    for (int i = commonDigits.size() ; i < lengthOfK; ++i) {
        for (int j = 0; j < leftNumbers.size(); ++j) {
            if (kAsArray[i] == -1) continue;
            if (leftNumbers[j] == kAsArray[i]) {
                result++;
            }
        }
    }

    return result;
}

bool areAllCommonDigitsAtTheStart(vector<unsigned int> commonDigits, unsigned int n) {
    int commonDigitsCount = commonDigits.size();
    int nLength = getNumberLength(n);

    for (int i = 0; i < commonDigitsCount; ++i) {
        int frontNumberN = n / pow(10, nLength - i - 1);
        int digitN = frontNumberN % 10;

        if (!count(commonDigits.begin(), commonDigits.end(), digitN)) {
            return false;
        }
    }

    return true;
}

vector<unsigned int> getCommonDigits(unsigned int n, unsigned int k) {
    int nLength = getNumberLength(n);
    int kLength = getNumberLength(k);

    vector<unsigned int> commonDigits;

    for (int i = 0; i < nLength; ++i) {
        int frontNumberN = n / pow(10, nLength - i - 1);
        int digitN = frontNumberN % 10;

        for (int j = 0; j < kLength; ++j) {
            int frontNumberK = k / pow(10, kLength - j - 1);
            int digitK = frontNumberK % 10;

            if (digitN == digitK) {
                commonDigits.push_back(digitN);
                break;
            }
        }
    }

    return commonDigits;
}

int getNumberLength(unsigned int n) {
    int length = 0;

    while (n != 0) {
        n = n/10;
        length++;
    }

    return length;
}

