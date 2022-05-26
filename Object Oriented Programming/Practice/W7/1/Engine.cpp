#include "Engine.h"
#include <iostream>

using namespace std;

void Engine::play(Gambler& gambler) const
{
	char command[25];
	while (true)
	{
		cin >> command;
		if (strcmp(command, "parity") == 0)
		{
			bool result;
			char guess;
			cin >> guess;
			if (guess == '0')
			{
				result = gambler.guessParity(false);
			}
			else if (guess == '1')
			{
				result = gambler.guessParity(true);
			}

			if (result)
			{
				gambler.money += gambler.money / 5;
			}
			else
			{
				gambler.money = 0;
			}
		}
		else if (true)
		{

		}
		else if (true)
		{

		}
		else
		{

		}
	}
}