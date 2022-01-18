#include <iostream>
#include <vector>

using namespace std;

bool isValidCombination(int firstDigit, int secondDigit, int thirdDigit, int firstDigitIndicator, int secondDigitIndicator, int thirdDigitIndicator, int firstSignIndicator, int secondSignIndicator);

int main() {
    char mappingTable[13][13] =
            {
                    {0, -5, -5, -5 ,-5, -5, -1, -5, 1, -1, -5, -5, -5},
                    {-5, 0, -5, -5, -5, -5, -5, 1, -5, -5, -5, -5, -5},
                    {-5, -5, 0, 10, -5, -5, -5, -5, -5, -5, -5, -5, -5},
                    {-5, -5, 0, 0, -5, 0, -5, -5, -5, 1, -5, -5, -5},
                    {-5, -5, -5, -5, 0, -5, -5, -5, -5, -5, -5, -5, -5},
                    {-5, -5, -5, 10, -5, 0, 1, -5, -5, 1 -5, -5, -5},
                    {1, -5, -5, -5, -5, -1, 0, -5, 1, -5, -5, -5, -5},
                    {-5, -1, -5, -5, -5, -5, -5, 0,  -5, -5, -5, -5, -5},
                    {-1, -5, -5, -5, -5, -5, -1,  -5, 0, -1,  -5, -5, -5},
                    {1, -5, -5, -1, -5, -1, -5, -5, 1, 0, -5, -5, -5},
                    {-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, 0, -1, 10},
                    {-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, 1, 0, 1},
                    {-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, 10, -1, 0}
            };

    char input[50];
    cin.getline(input, 50);

    vector<char*> firstCombinations;
    vector<char*> secondCombinations;
    vector<char*> thirdCombinations;
    vector<char*> fourthCombinations;
    vector<char*> fifthCombinations;

    for (int i = 0; i < 5; ++i) {
        char* combinations;

        char symbol = input[i];
        if (symbol == '+' || symbol == '-' || symbol == '=') {
            if (symbol == '+') {
                combinations = mappingTable[10];
            }
            else if (symbol == '-') {
                combinations = mappingTable[11];
            }
            else {
                combinations = mappingTable[12];
            }
        }
        else {
            combinations = mappingTable[symbol - 48];
        }

        for (int j = 0; j < 13; ++j) {
            if (combinations[j] != -5) {
                if (i == 0) {
                    char* combination = new char[2];
                    combination[0] = (char)j;
                    combination[1] = combinations[j];
                    firstCombinations.push_back(combination);
                }
                else if (i == 1) {
                    char sign;
                    if  (j == 10) {
                        sign = '+';
                    }
                    else if (j == 11) {
                        sign = '-';
                    }
                    else {
                        sign = '=';
                    }
                    char* combination = new char[2];
                    combination[0] = sign;
                    combination[1] = combinations[j];
                    secondCombinations.push_back(combination);
                }
                else if (i == 2) {
                    char* combination = new char[2];
                    combination[0] = (char)j;
                    combination[1] = combinations[j];
                    thirdCombinations.push_back(combination);
                }
                else if (i == 3) {
                    char sign;
                    if  (j == 10) {
                        sign = '+';
                    }
                    else if (j == 11) {
                        sign = '-';
                    }
                    else {
                        sign = '=';
                    }
                    char* combination = new char[2];
                    combination[0] = sign;
                    combination[1] = combinations[j];
                    fourthCombinations.push_back(combination);
                }
                else if (i == 4) {
                    char* combination = new char[2];
                    combination[0] = (char)j;
                    combination[1] = combinations[j];
                    fifthCombinations.push_back(combination);
                }
            }
        }
    }

    bool hasCombination = false;

    for (char* firstCombination : firstCombinations) {
        for (char* secondCombination : secondCombinations) {
            for (char* thirdCombination : thirdCombinations) {
                for (char* fourthCombination : fourthCombinations) {
                    for (char* fifthCombination : fifthCombinations) {
                        char firstSign = secondCombination[0];
                        char secondSign = fourthCombination[0];
                        if (firstSign == secondSign || (firstSign != '=' && secondSign != '=')) {
                            continue;
                        }

                        int firstDigit = firstCombination[0];
                        int firstDigitIndicator = firstCombination[1];
                        int secondDigit = thirdCombination[0];
                        int secondDigitIndicator = thirdCombination[1];
                        int thirdDigit = fifthCombination[0];
                        int thirdDigitIndicator = fifthCombination[1];

                        int firstSignIndicator = secondCombination[1];
                        int secondSignIndicator = fourthCombination[1];

                        if (firstSign == '+' && secondSign == '=') {
                            if (firstDigit + secondDigit == thirdDigit) {
                                if (isValidCombination(firstDigit, secondDigit, thirdDigit, firstDigitIndicator, secondDigitIndicator, thirdDigitIndicator, firstSignIndicator, secondSignIndicator) == false) {
                                    continue;
                                }
                                else {
                                    cout << firstDigit << '+' << secondDigit << '=' << thirdDigit << endl;
                                    hasCombination = true;
                                    //return 0;
                                }
                            }
                        }
                        else if (firstSign == '-' && secondSign == '=') {
                            if (firstDigit - secondDigit == thirdDigit) {
                                if (isValidCombination(firstDigit, secondDigit, thirdDigit, firstDigitIndicator, secondDigitIndicator, thirdDigitIndicator, firstSignIndicator, secondSignIndicator) == false) {
                                    continue;
                                }
                                else {
                                    cout << firstDigit << '-' << secondDigit << '=' << thirdDigit << endl;
                                    hasCombination = true;

                                    //return 0;
                                }
                            }
                        }
                        else if (firstSign == '=' && secondSign == '+') {
                            if (firstDigit == secondDigit + thirdDigit) {
                                if (isValidCombination(firstDigit, secondDigit, thirdDigit, firstDigitIndicator, secondDigitIndicator, thirdDigitIndicator, firstSignIndicator, secondSignIndicator) == false) {
                                    continue;
                                }
                                else {
                                    cout << firstDigit << '=' << secondDigit << '+' << thirdDigit << endl;
                                    hasCombination = true;

                                    //return 0;
                                }
                            }
                        }
                        else if (firstSign == '=' && secondSign == '-') {
                            if (firstDigit == secondDigit - thirdDigit) {
                                if (isValidCombination(firstDigit, secondDigit, thirdDigit, firstDigitIndicator, secondDigitIndicator, thirdDigitIndicator, firstSignIndicator, secondSignIndicator) == false) {
                                    continue;
                                }
                                else {
                                    cout << firstDigit << '=' << secondDigit << '-' << thirdDigit << endl;
                                    hasCombination = true;

                                    //return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!hasCombination) {
        cout << "No";
    }

    return 0;
}

bool isValidCombination(int firstDigit, int secondDigit, int thirdDigit, int firstDigitIndicator, int secondDigitIndicator, int thirdDigitIndicator, int firstSignIndicator, int secondSignIndicator) {
    int counter = 0;

    if (firstDigitIndicator != 0) {
        counter++;
    }
    if (secondDigitIndicator != 0) {
        counter++;
    }
    if (thirdDigitIndicator != 0) {
        counter++;
    }
    if (firstSignIndicator != 0) {
        counter++;
    }
    if (secondSignIndicator != 0) {
        counter++;
    }
    if (counter > 2) {
        return false;
    }

    if (firstDigitIndicator == secondDigitIndicator && secondDigitIndicator == thirdDigitIndicator && firstDigitIndicator == 0 && firstSignIndicator == 0 && secondSignIndicator == 0) {
        return false;
    }
    else if (firstDigitIndicator == 10 || secondDigitIndicator == 10 || thirdDigitIndicator == 10) {
        if (firstDigitIndicator + secondDigitIndicator + thirdDigitIndicator != 10) {
            return false;
        }
        //YOU GOT IT
        return true;
    }
    else if (firstDigitIndicator + secondDigitIndicator + thirdDigitIndicator + firstSignIndicator + secondDigitIndicator == 0) {
        // YOU GOT IT
        return true;
    }
    else {
        return false;
    }
}

