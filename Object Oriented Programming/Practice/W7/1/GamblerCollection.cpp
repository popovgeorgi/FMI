#include "GamblerCollection.h"
#include <cstring>

void GamblerCollection::addGambler(const char* name, const char* password, unsigned int age, double money)
{
	Gambler gambler(name, password, age, money);
	data.push_back(gambler);
}

int GamblerCollection::isValidPassword(char* password)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		char* gamblerPassword = data[i].password;
		if (strcmp(gamblerPassword, password) == 0)
		{
			return i;
		}
	}

	return -1;
}

Gambler& GamblerCollection::getGamblerByIndex(int index)
{
	return data[index];
}