#pragma once
#include "vector.hpp"
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"

class Bank
{
	Vector<Customer> customers;
	Vector<Account*> accounts;
	Vector<Transaction> transcations;

public:
	void addCustomer(int id, const char* name, const char* address);
	void addAccount(const char* type, const char* arguments); // dateOfCreation
	void listAllCustomers() const;
	void listCustomerAccounts(int userId) const;
	void deleteCustomer(int userId); //delete all associated accounts
	void deleteAccount(const char* username, const char* password);
	void exportTransactions() const;

	void transfer(const char* username, const char* password, int receiverIban, double money);
	double viewBalance(const char* username, const char* password) const;
	void deposit(const char* username, const char* password, double money);
	void withdraw(const char* username, const char* password, double money);
};

