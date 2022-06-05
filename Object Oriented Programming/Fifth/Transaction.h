#pragma once
#include "MyString.h"

class Transaction
{
	MyString m_from{};
	MyString m_to{};
	double m_amount{};

public:
	Transaction();
	Transaction(const char* from, const char* to, double amount);
};