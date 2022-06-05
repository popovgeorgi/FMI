#pragma once
#include "Account.h"

class NormalAccount : public Account
{
public:
	NormalAccount(const char* username, const char* password, const char* address, int customerId);

	void print() const override final;
	void withdraw(double amount) override final;
};