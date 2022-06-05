#pragma once
#include <exception>
#include "MyString.h"

class InvalidCredentialsException : public std::exception
{
	MyString m_message{};

public:
	InvalidCredentialsException(const char* message)
		:m_message(message) {}

	const char* what() const noexcept override { return m_message.getString(); }

};