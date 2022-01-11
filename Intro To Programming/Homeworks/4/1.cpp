#include <iostream>
#include <vector>

using namespace std;

char** letterCasePermutation(char* str);
char* copyArray(char* str, int index);
vector<char*> findPermutation(char* str, char symbol, int index);
bool isLetter(char symbol);
int strlen(const char str[]);

int main() {
    char input[100];
    cin.getline(input, 100);
    letterCasePermutation(input);

    return 0;
}

char** letterCasePermutation(char* str) {
    vector<char*> permutations;

    for (int i = 0; i < strlen(str); ++i) {
        char symbol = str[i];

        bool letter = isLetter(symbol);
        if (letter) {
            if (permutations.empty()) {
                char permutation[100];
                permutation[0] = symbol;
                permutations.push_back(permutation);

                char upperPermutation[100];
                upperPermutation[0] = symbol - 32;
                permutations.push_back(upperPermutation);
            }
            else {
                vector<char*> newPermutations;
                for (char* permutation : permutations) {
                    vector<char*> permutationsFromSymbol = findPermutation(permutation, symbol, i);
                    for (char* permutation : permutationsFromSymbol) {
                        newPermutations.push_back(permutation);
                    }
                }

                permutations = newPermutations;
            }
        }
        else {
            for (char* permutation : permutations) {
                char* newPermutation;
                for (int j = 0; j < strlen(permutation); ++j) {
                    newPermutation[j] = permutation[j];
                }
                newPermutation[strlen(permutation)] = symbol;
                permutations[0] = newPermutation;
            }
        }
    }

    return permutations;
}

vector<char*> findPermutation(char* str, char symbol, int index) {
    vector<char*> permutations;

    char* fArray = copyArray(str, index);
    fArray[index] = symbol;
    permutations.push_back(fArray);

    char* sArray = copyArray(str, index);
    sArray[index] = symbol - 32;
    permutations.push_back(sArray);

    return permutations;
}

char* copyArray(char* str, int index) {
    char* newArray;
    for (int i = 0; i < index; ++i) {
        newArray[i] = str[i];
    }

    return newArray;
}


bool isLetter(char symbol) {
    if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) {
        return true;
    }

    return false;
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
