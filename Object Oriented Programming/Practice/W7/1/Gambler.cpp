#include <cstring>
#include "Gambler.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

Gambler::Gambler(const char* name, const char* password, unsigned int age, double money)
{
	// initialize pointers
	srand(time(NULL));
	strcpy(this->name, name);
	strcpy(this->password, password);
	this->age = age;
	this->money = money;
}

void Gambler::generateRandomness()
{
	randomNumber = rand() % 101;
}

bool Gambler::guessParity(bool guess)
{
	generateRandomness();
	if ((randomNumber % 2 == 0 && guess == true) || (randomNumber % 2 == 1 && guess == false))
	{
		return true;
	}
	
	return false;
}

bool Gambler::isPrime()
{
	generateRandomness();

	return true;
}

bool Gambler::isPowerOfTwo()
{
	generateRandomness();

	for (size_t i = 0; i < 6; i++)
	{
		if (pow(2, i) == randomNumber)
		{
			return true;
		}
	}

	return false;
}

bool Gambler::isUpperOrLower(unsigned int number, bool upper)
{
	generateRandomness();

	if ((number > randomNumber && upper == true) || (number < randomNumber && upper == false))
	{
		return true;
	}

	return false;
}

bool Gambler::isGuessed(unsigned int number)
{
	generateRandomness();

	return number == randomNumber;
}