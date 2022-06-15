#pragma once
#include "MyString.h"

const int getNumberLen(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}

	return count;
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


const MyString getString(int n)
{
	int len = getNumberLen(n);
	int arrSize = len + 1;
	char* result = new char[arrSize];
	result[len] = '\0';

	int index = len - 1;
	while (n != 0)
	{
		int digit = n % 10;
		result[index--] = (char)digit + 48;
		n /= 10;
	}

	MyString res(result);
	delete[] result;

	return res;
}