#include <iostream>
#include "Bank.h"
#include "AccountFactory.h"
#include "InvalidCredentialsException.h"
#include "InsufficientBalanceException.h"

void Bank::addAccount(const char* type, const char* arguments)// dateOfCreation
{
	Account* account = AccountFactory::Create(type, arguments);
	accounts.pushBack(account);
}

void Bank::addCustomer(int id, const char* name, const char* address)
{
	customers.pushBack(Customer(id, name, address)); // Няма ли да го изтрие?
}

void Bank::listAllCustomers() const
{
	int size = customers.getSize();
	for (size_t i = 0; i < size; i++)
	{
		customers[i].print();
	}
}

void Bank::listCustomerAccounts(int userId) const
{
	int size = accounts.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (accounts[i]->getCustomerId() == userId)
		{
			accounts[i]->print();
		}
	}
}

void Bank::deleteAccount(const char* username, const char* password)
{
	int size = accounts.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(accounts[i]->getUsername().getString(), username) == 0)
		{
			if (strcmp(accounts[i]->getPassword().getString(), password) == 0)
			{
				accounts.popAt(i);
				break;
			}
			else
			{
				throw InvalidCredentialsException("Your password does not match the username!");
			}
		}
	}

	throw InvalidCredentialsException("There does not exist an account with such a username!");
}

void Bank::deleteCustomer(int userId)	//delete all associated accounts
{
	int accountSize = accounts.getSize();
	for (size_t i = 0; i < accountSize; i++)
	{
		if (accounts[i]->getCustomerId() == userId)
		{
			accounts.popAt(i);
		}
	}

	int customerSize = customers.getSize();
	for (size_t i = 0; i < customerSize; i++)
	{
		if (customers[i].getId() == userId)
		{
			customers.popAt(i);
		}
	}
}

double Bank::viewBalance(const char* username, const char* password) const
{
	int size = accounts.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(accounts[i]->getUsername().getString(), username) == 0)
		{
			if (strcmp(accounts[i]->getPassword().getString(), password) == 0)
			{
				return accounts[i]->getBalance();
			}
			else
			{
				throw InvalidCredentialsException("Your password does not match the username!");
			}
		}
	}

	throw InvalidCredentialsException("There does not exist an account with such a username!");
}

void Bank::deposit(const char* username, const char* password, double money)
{
	int size = accounts.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(accounts[i]->getUsername().getString(), username) == 0)
		{
			if (strcmp(accounts[i]->getPassword().getString(), password) == 0)
			{
				accounts[i]->deposit(money);
				std::cout << "You've just deposited " << money << std::endl;
				break;
			}
			else
			{
				throw InvalidCredentialsException("Your password does not match the username!");
			}
		}
	}

	throw InvalidCredentialsException("There does not exist an account with such a username!");
}

void Bank::withdraw(const char* username, const char* password, double money)
{
	int size = accounts.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(accounts[i]->getUsername().getString(), username) == 0)
		{
			if (strcmp(accounts[i]->getPassword().getString(), password) == 0)
			{
				accounts[i]->withdraw(money); // exception
				std::cout << "You've just withdrawn " << money << std::endl;
				break;
			}
			else
			{
				throw InvalidCredentialsException("Your password does not match the username!");
			}
		}
	}

	throw InvalidCredentialsException("There does not exist an account with such a username!");
}

void Bank::transfer(const char* username, const char* password, int receiverIban, double money)
{
	// tuk li mu e mqstoto?
	double balance = viewBalance(username, password);
	if (balance - money < 0)
	{
		throw InsufficientBalanceException("You do not have enough money in order to proceed the transaction!");
	}

	int size = accounts.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (accounts[i]->getIban() == receiverIban)
		{
			accounts[i]->deposit(money);
			withdraw(username, password, money);
			transcations.pushBack(Transaction(username, accounts[i]->getUsername().getString(), money));
			return;
		}
	}

	throw InvalidCredentialsException("There does not exist an account with such an IBAN!");
}

void Bank::exportTransactions() const
{

}
