#include "PrivilegeAccount.h"
#include "InsufficientBalanceException.h"

PrivilegeAccount::PrivilegeAccount(const char* username, const char* password, const char* address, int customerId, double overdraft)
	:Account(username, password, address, customerId), m_overdraft(overdraft) {}

void PrivilegeAccount::print() const
{
	std::cout << "Privilege Account" << std::endl;
}

void PrivilegeAccount::withdraw(double amount)
{
	double currentBalance = getBalance();
	if (currentBalance + m_overdraft < amount)
	{
		throw InsufficientBalanceException("You do not have enough money in order to proceed the transaction!");
	}

	setBalance(currentBalance - amount);
}