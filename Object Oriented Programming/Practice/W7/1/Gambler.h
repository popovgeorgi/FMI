#pragma once
struct Gambler
{
	char* name;
	char* password;
	unsigned int age;
	double money;
	int randomNumber;

	void generateRandomness();

	Gambler(const char* name, const char* password, unsigned int age, double money);

	bool guessParity(bool guess);
	bool isPrime();
	bool isPowerOfTwo();
	bool isUpperOrLower(unsigned int number, bool upper);
	bool isGuessed(unsigned int number);
};