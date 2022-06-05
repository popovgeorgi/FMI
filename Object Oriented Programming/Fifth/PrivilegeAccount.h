#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
	double m_overdraft{};

public:
	PrivilegeAccount(const char* username, const char* password, const char* address, int customerId, double overdraft);

	void print() const override final;
	void withdraw(double amount) override final;
};