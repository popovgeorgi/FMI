#include "Helper.h"

int strcomp(const char* str1, const char* str2)
{
    int len1 = strlength(str1);
    int len2 = strlength(str2);

    if (strlength(str1) <= strlength(str2))
    {
        for (size_t i = 0; i < len1; i++)
        {
            if (str1[i] < str2[i])
            {
                return 1;
            }
            else if (str1[i] > str2[i])
            {
                return -1;
            }
        }

        return 0;
    }

    for (size_t i = 0; i < len2; i++)
    {
        if (str1[i] < str2[i])
        {
            return 1;
        }
        else if (str1[i] > str2[i])
        {
            return -1;
        }
    }

    return 0;
}

int strlength(const char* str)
{
    size_t count = 0;
    while (str[count] != '\0')
    {
        count++;
    }

    return count;
}

bool areEqual(const char* str1, const char* str2)
{
    size_t firstStrLen = strlength(str1);
    size_t secondStrLen = strlength(str2);
    if (firstStrLen != secondStrLen)
    {
        return false;
    }

    for (size_t i = 0; i < firstStrLen; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

void strcopy(const char* source, char* dest)
{
    size_t sourceLength = strlength(source);
    for (size_t i = 0; i < sourceLength; i++)
    {
        dest[i] = source[i];
    }
    dest[sourceLength] = '\0';
}

int power(int num, int deg)
{
    int res = 1;
    for (size_t i = 0; i < deg; i++)
    {
        res *= num;
    }

    return res;
}

bool containsMonkey(const char* str)
{
    int index = 0;
    while (str[index] != '\0')
    {
        if (str[index] == '@')
        {
            return true;
        }

        index++;
    }

    return false;
}

float getIntFromString(const char* str)
{
    int res = 0;
    const int len = strlength(str);
    for (size_t i = 0; i < len; i++)
    {
        int multiplier = power(10, len - 1 - i);
        int number = str[i] - 48;
        res += multiplier * number;
    }

    return res;
}

void substring(const char* source, char* dest, int length, int index)
{
    int destIndex = 0;

    for (size_t i = index; i < index + length; i++)
    {
        dest[destIndex] = source[i];
        destIndex++;
    }
    dest[destIndex] = '\0';
}

bool containsDot(const char* str)
{
    int len = strlength(str);
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] == '.')
        {
            return true;
        }
    }

    return false;
}

double getDoubleFromString(const char* str)
{
    double result = 0.0;
    int dotIndex = 0;

    bool isDouble = containsDot(str);
    if (!isDouble)
    {
        return getIntFromString(str);
    }

    while (str[dotIndex] != '.')
    {
        dotIndex++;
    }

    char* firstPart = new char[dotIndex + 1];
    substring(str, firstPart, dotIndex, 0);
    result += getIntFromString(firstPart);

    int len = strlength(str);

    int lenOfSecondPart = len - (dotIndex + 1);
    char* secondPart = new char[lenOfSecondPart + 1];
    substring(str, secondPart, lenOfSecondPart, dotIndex + 1);
    double secondPartAsInt = getIntFromString(secondPart);
    double calc = secondPartAsInt / power(10, lenOfSecondPart);

    result += calc;

    delete[] firstPart;
    delete[] secondPart;

    return result;
}