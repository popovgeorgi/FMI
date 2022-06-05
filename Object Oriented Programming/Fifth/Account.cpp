#include "Account.h"
#include <ctime>

Account::Account(const char* username, const char* password, const char* address, int customerId)
	: m_username(username), m_password(password), m_address(address), m_customerId(customerId)
{
	time_t curr = time(0);
	const char* dt = ctime(&curr);
	m_timeOfOpening = dt;
	m_balance = 0;
	m_iban = std::hash<std::string>{}((m_username + m_password).getString());
}

int Account::getCustomerId() const { return m_customerId; }

const MyString& Account::getUsername() const { return m_username; }

const MyString& Account::getPassword() const { return m_password; }

double Account::getBalance() const { return m_balance; }

int Account::getIban() const { return m_balance; }

void Account::deposit(double amount)
{
	m_balance += amount;
}

void Account::setBalance(double balance)
{
	m_balance = balance;
}