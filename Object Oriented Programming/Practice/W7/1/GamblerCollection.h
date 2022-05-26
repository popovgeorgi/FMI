#pragma once
#include <vector>
#include "Gambler.h"

using namespace std;

class GamblerCollection
{
	vector<Gambler> data;

public:
	void addGambler(const char* name, const char* password, unsigned int age, double money);

	int isValidPassword(char* password);
	Gambler& getGamblerByIndex(int index);
};