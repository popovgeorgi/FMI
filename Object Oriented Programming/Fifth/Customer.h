#pragma once
#include "MyString.h"

class Customer
{
	int m_id{};
	MyString m_name{};
	MyString m_address{};

public:
	Customer();
	Customer(int id, const char* name, const char* address);
	void print() const;

	int getId() const;
};