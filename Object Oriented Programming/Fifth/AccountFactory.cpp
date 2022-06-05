#include "AccountFactory.h"
#include "NormalAccount.h";
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"
#include "Helpers.h"


Account* AccountFactory::Create(const char* type, const char* arguments)
{
	Account* account = nullptr;

	if (strcmp(type, "normal") == 0)
	{
		const char* username = getWordFromString(0, arguments);
		const char* password = getWordFromString(1, arguments);
		const char* address = getWordFromString(2, arguments);
		int userId = atoi(getWordFromString(3, arguments));
		
		account = new NormalAccount(username, password, address, userId);
	}
	else if (strcmp(type, "savings") == 0)
	{
		const char* username = getWordFromString(0, arguments);
		const char* password = getWordFromString(1, arguments);
		const char* address = getWordFromString(2, arguments);
		int userId = atoi(getWordFromString(3, arguments));
		double interestRate = atoi(getWordFromString(4, arguments));

		account = new SavingsAccount(username, password, address, userId, interestRate);
	}
	else if (strcmp(type, "privilege") == 0)
	{
		const char* username = getWordFromString(0, arguments);
		const char* password = getWordFromString(1, arguments);
		const char* address = getWordFromString(2, arguments);
		int userId = atoi(getWordFromString(3, arguments));
		double overdraft = atoi(getWordFromString(4, arguments));

		account = new PrivilegeAccount(username, password, address, userId, overdraft);
	}

	return account;
}


