#include <iostream>

using namespace std;

int replace(char *text, const char *const replaced, const char *const replacing);
int strlen(const char str[]);
bool contains(char* text, int index, const char *const replaced, const char *const replacing);
void populateNewText(char* text, int index, const char* const replaced, const char *const replacing);

int main() {
    char input[4000], replaced[1000], replacing[1000];
    cin.getline(input, 4000);
    cin.getline(replaced, 1000);
    cin.getline(replacing, 1000);

    int result = replace(input, replaced, replacing);
    cout << result << endl;
    cout << input;

    return 0;
}

int replace(char *text, const char *const replaced, const char *const replacing) {
    int counter = 0;

    for (int i = 0; i < strlen(text); ++i) {
        char firstReplacedLetter = replaced[0];
        if (text[i] == firstReplacedLetter) {
            bool match = contains(text, i, replaced, replacing);
            if (match) {
                counter++;
            }
        }
    }

    return counter;
}

bool contains(char* text, int index, const char* const replaced, const char *const replacing) {
    bool contains = true;

    for (int i = 1; i < strlen(replaced); ++i) {
        if (text[++index] != replaced[i]) {
            contains = false;
            break;
        }
    }

    if (contains) {
        populateNewText(text, index, replaced, replacing);
        return true;
    }

    return false;
}

void populateNewText(char* text, int index, const char* const replaced, const char *const replacing) {
    char* newText = new char[4000];
    index -= strlen(replaced) - 1;
    int initialIndex = index;

    for (int i = 0; i < index; ++i) {
        newText[i] = text[i];
    }
    for (int i = 0; i < strlen(replacing); ++i) {
        newText[index++] = replacing[i];
    }
    for (int i = initialIndex + strlen(replaced); i < strlen(text); ++i) {
        newText[index++] = text[i];
    }
    newText[index++] = '\0';

    for (int i = 0; i < index; ++i) {
        text[i] = newText[i];
    }
    free(newText);
}



int strlen(const char str[]) {
    int counter = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        counter++;
        i++;
    }
    return counter;
}
