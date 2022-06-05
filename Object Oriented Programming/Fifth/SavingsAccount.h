#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
	double m_interestRate{};

public:
	SavingsAccount(const char* username, const char* password, const char* address, int customerId, double interestRate);

	void print() const override final;
	void withdraw(double amount) override final;
};