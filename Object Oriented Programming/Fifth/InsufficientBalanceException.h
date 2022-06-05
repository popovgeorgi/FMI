#pragma once
#include <exception>
#include "MyString.h"

class InsufficientBalanceException : public std::exception
{
	MyString m_message{};

public:
	InsufficientBalanceException(const char* message)
		:m_message(message) {}

	const char* what() const noexcept override { return m_message.getString(); }

};