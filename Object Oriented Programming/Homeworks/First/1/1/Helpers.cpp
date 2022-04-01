#include <iostream>
#include <fstream>
#include "Helpers.h"

using namespace std;

int power(int num, int deg)
{
	int res = 1;
	for (size_t i = 0; i < deg; i++)
	{
		res *= num;
	}

	return res;
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

int getIntFromString(const char* str)
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

int getBytesOfFile(char* fileName)
{
	ifstream inFile(fileName, ios::binary);
	if (!inFile)
	{
		return -1;
	}

	size_t counter = 0;
	while (true)
	{
		inFile.get();
		if (inFile.eof())
		{
			break;
		}
		counter++;
	}

	return counter;
}

char getCharForInt(int n)
{
	if (n >= 0 && n <= 9)
	{
		return n + '0';
	}
	else
	{
		if (n == 10)
		{
			return 'A';
		}
		else if (n == 11)
		{
			return 'B';
		}
		else if (n == 12)
		{
			return 'C';
		}
		else if (n == 13)
		{
			return 'D';
		}
		else if (n == 14)
		{
			return 'E';
		}
		else if (n == 15)
		{
			return 'F';
		}
	}
}

char* getHexFromDecimal(int n)
{
	char* hex = new char[3];

	int remainer = n / 16;
	if (remainer == 0)
	{
		hex[0] = '0';
		remainer = n % 16;
	}
	else
	{
		hex[0] = getCharForInt(remainer);
		remainer = n - 16 * remainer;
	}

	if (remainer >= 0 || remainer <= 9)
	{
		hex[1] = getCharForInt(remainer);
	}
	else
	{
		hex[1] = getCharForInt(remainer);
	}
	hex[2] = '\0';

	return hex;
}

void printBytesFromFile(char* fileName)
{
	ifstream inFile(fileName, ios::binary);
	if (!inFile)
	{
		return;
	}

	char byte;
	while (true)
	{
		inFile.get(byte);
		if (inFile.eof())
		{
			return;
		}

		cout << getHexFromDecimal(int(byte)) << " ";
	}
}

void printTextFromFile(char* fileName)
{
	ifstream inFile(fileName, ios::binary);
	if (!inFile)
	{
		return;
	}

	char byte;
	while (true)
	{
		inFile.get(byte);
		if (inFile.eof())
		{
			return;
		}

		if ((byte >= 65 && byte <= 90) || (byte >= 97 && byte <= 122))
		{
			cout << byte;
		}
		else
		{
			cout << '.';
		}
	}
}