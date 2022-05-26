#pragma once
#include <exception>	
#include <stdexcept>
#include "myString.h"

using namespace std;

class InsufficientFuelException : public logic_error
{
public:
	InsufficientFuelException(const char* message);
};

InsufficientFuelException::InsufficientFuelException(const char* message)
	:logic_error(message) {}