#include <iostream>

using namespace std;

bool isHacksaw(int* arr, int index, char sign, int numbersCount);
bool validateInput(int n);

int main() {
    int n, input[1000];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    if (validateInput(n) == false) {
        cout << "-1";
        return -1;
    }

    bool firstVariation = isHacksaw(input, 0, '>', n);
    bool secondVariation = isHacksaw(input, 0, '<', n);
    if (firstVariation || secondVariation) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

    return 0;
}

bool isHacksaw(int* arr, int index, char sign, int numbersCount) {
    if (index + 1 >= numbersCount) {
        return true;
    }
    else {
        if (sign == '>') {
            if (arr[index] > arr[index + 1]) {
                return isHacksaw(arr, index + 1, '<', numbersCount);
            }
            else {
                return false;
            }
        }
        else if (sign == '<') {
            if (arr[index] < arr[index + 1]) {
                return isHacksaw(arr, index + 1, '>', numbersCount);
            }
            else {
                return false;
            }
        }
    }
}

bool validateInput(int n) {
    if (n < 3 || n > 1000) {
        return false;
    }

    return true;
}
