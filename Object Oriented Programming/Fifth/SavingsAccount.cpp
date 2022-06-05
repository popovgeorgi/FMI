#include "SavingsAccount.h"
#include "InsufficientBalanceException.h"

SavingsAccount::SavingsAccount(const char* username, const char* password, const char* address, int customerId, double interestRate)
	:Account(username, password, address, customerId), m_interestRate(interestRate) {}

void SavingsAccount::print() const
{
	std::cout << "Savings Account" << std::endl;
}

void SavingsAccount::withdraw(double amount)
{
	throw InsufficientBalanceException("Your account does not allow withdrawing!!");
}