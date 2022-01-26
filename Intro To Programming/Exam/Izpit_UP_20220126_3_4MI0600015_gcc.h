//
// GEORGI POPOV
// 4MI0600015
//

#ifndef EXAM_IZPIT_UP_20220126_3_4MI0600015_GCC_H
#define EXAM_IZPIT_UP_20220126_3_4MI0600015_GCC_H

//task 1
int pow(int number, int power) {
    int result = 1;
    for (int i = 0; i < power; ++i) {
        result *= number;
    }

    return result;
}

long newNum(long num) {
    int newNum = 0, power = 0;
    while (num != 0) {
        int currentDigit = num % 10;
        if (currentDigit % 2 == 0) {
            newNum += pow(10, power) * currentDigit;
            power++;
        }

        num /= 10;
    }

    return newNum;
}

//task 2
int* mergeArr(int * arr1, int * arr2, int len) {
    int* mergeArr = new int[len];

    for (int i = 0; i < len; ++i) {
        bool hasSmaller = false;
        int element = arr1[i];

        for (int j = 0; j < len; ++j) {
            if (element < arr2[j]) {
                mergeArr[i] = j;
                hasSmaller = true;
                break;
            }
        }
        if (hasSmaller == false) {
            mergeArr[i] = -1;
        }
    }

    return mergeArr;
}

//task 3
bool isLower(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

char* getWord (char* str, int k) {
    char* word = new char[500];
    int index = 0, spaces = 0, wordIndex = 0;

    while (str[index] != '\0') {
        if (str[index] == ' ') {
            spaces++;
            index++;
            continue;
        }

        if (spaces + 1 == k) {
            if (isLower(str[index])) {
                word[wordIndex] = str[index] - 32;
            }
            else {
                word[wordIndex] = str[index] + 32;
            }
            wordIndex++;
        }
        else if (spaces + 1 > k) {
            break;
        }

        index++;
    }

    if (k - spaces > 1) {
        return "Wrong number!";
    }

    word[wordIndex] = '\0';
    return word;
}

#endif //EXAM_IZPIT_UP_20220126_3_4MI0600015_GCC_H
