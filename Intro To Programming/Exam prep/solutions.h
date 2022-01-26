#ifndef EXAM_PREP_SOLUTIONS_H
#define EXAM_PREP_SOLUTIONS_H

//task 1
void convertArr(long arr[], long startIndex, long endIndex) {
    if (startIndex >= endIndex) {
        return;
    }

    int subArrayLength = (endIndex - startIndex + 1) / 2;
    for (int i = startIndex; i < subArrayLength + startIndex; ++i) {
        int temp = arr[i];
        arr[i] = arr[endIndex];
        arr[endIndex] = temp;

        endIndex--;
    }
}

//task 2
int findElement(long arr[], int length) {
    for (int i = length - 2 ; i >= 1 ; --i) {
        double average = (arr[i+1] + arr[i-1]) / 2;
        if (arr[i] > average) {
            return i;
        }
    }

    return -1;
}

const int NUMBER_OF_ROWS = 2;

//task 3
int** mergeArrays(int* first, int* second, int m) {
    int** mergeTable = new int*[NUMBER_OF_ROWS];

    for (int i = 0; i < NUMBER_OF_ROWS; ++i) {
        mergeTable[i] = new int[m];

        for (int j = 0; j < m; ++j) {
            if (i == 0) {
                mergeTable[i][j] = first[j];
            }
            else if (i == 1) {
                mergeTable[i][j] = second[j];
            }
        }
    }

    return mergeTable;
}

//task 4
struct Point {
    int x;
    int y;
};

bool haveSameX(const Point& first, const Point& second) {
    return first.x == second.x;
}

bool haveSameY(const Point& first, const Point& second) {
    return first.y == second.y;
}

bool checkRectangular(const Point& first, const Point& second, const Point& third) {
    if (haveSameX(first, second)) {
        if (haveSameY(first, third)) {
            return true;
        }
        else if (haveSameY(second, third)) {
            return true;
        }
    }
    else if (haveSameX(first, third)) {
        if (haveSameY(first, second)) {
            return true;
        }
        else if (haveSameY(third, second)) {
            return true;
        }
    }
    else if (haveSameX(second, third)) {
        if (haveSameY(second, first)) {
            return true;
        }
        else if (haveSameY(third, first)) {
            return true;
        }
    }

    return false;
}

//task 5
int pow(int number, int pow) {
    int result = 1;
    for (int i = 0; i < pow; ++i) {
        result *= number;
    }

    return result;
}

int* extract(const int number) {
    int realNumber = number;
    if (number < 0) {
        realNumber = number * -1;
    }

    int best = 0;
    int countingArr[10] = {};
    int counter = 0;
    do {
        int currentDigit = (realNumber / pow(10, counter)) % 10;
        countingArr[currentDigit]++;
        if (countingArr[currentDigit] > best) {
            best = countingArr[currentDigit];
        }

        counter++;
    }
    while (realNumber / pow(10, counter) != 0);

    int bestDigits = 0;
    for (int i = 0; i < 10; ++i) {
        if (countingArr[i] == best) {
            bestDigits++;
        }
    }

    int* resArr = new int[bestDigits + 1];
    int index = 0;
    for (int i = 0; i < 10; ++i) {
        if (countingArr[i] == best) {
            resArr[index] = i;
            index++;
        }
    }
    resArr[index] = -1;

    return resArr;
}

#endif //EXAM_PREP_SOLUTIONS_H
