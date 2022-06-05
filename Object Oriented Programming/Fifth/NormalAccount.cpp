#include "NormalAccount.h"
#include "InsufficientBalanceException.h"

NormalAccount::NormalAccount(const char* username, const char* password, const char* address, int customerId)
	: Account(username, password, address, customerId) {}

void NormalAccount::print() const
{
	std::cout << "Normal Account" << std::endl;
}

void NormalAccount::withdraw(double amount)
{
	double currentBalance = getBalance();
	if (currentBalance < amount)
	{
		 throw InsufficientBalanceException("You do not have enough money in order to proceed the transaction!");
	}

	setBalance(currentBalance - amount);
}