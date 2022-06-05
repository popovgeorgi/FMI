#pragma once
#include "MyString.h"

class Account
{
	MyString m_username;
	MyString m_password;
	MyString m_address;
	MyString m_timeOfOpening;
	int m_iban;
	int m_customerId;
	double m_balance{};

public:
	Account(const char* username, const char* password, const char* address, int customerId);
	virtual void print() const = 0;

	int getCustomerId() const;
	const MyString& getUsername() const;
	const MyString& getPassword() const;
	double getBalance() const;
	int getIban() const;

	virtual void withdraw(double amount) = 0; // will return exception
	void deposit(double amount);	

	void setBalance(double balance);
};

