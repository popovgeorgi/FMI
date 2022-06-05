#include <iostream>
#include "Bank.h"

int main()
{
    Bank bank;
    char input[150];

	while (true)
	{
		std::cin >> input;
		if (strcmp(input, "edit") == 0)
		{
			std::cin >> input;
			if (strcmp(input, "customer") == 0)
			{
				if (strcmp(input, "add") == 0)
				{
					std::cin >> input;
					int id = atoi(input);

					std::cin >> input;
					char name[50];
					strcpy(name, input);

					std::cin >> input;
					char address[50];
					strcpy(address, input);

					bank.addCustomer(id, name, address);
				}
				else if (strcmp(input, "delete") == 0)
				{

				}
			}
			else if (strcmp(input, "account") == 0)
			{

			}
		}
		else if (strcmp(input, "list") == 0)
		{

		}
		else if (strcmp(input, "action") == 0)
		{

		}
		else if (strcmp(input, "display") == 0)
		{

		}
		else if (strcmp(input, "exit") == 0)
		{
			break;
		}
	}
}
