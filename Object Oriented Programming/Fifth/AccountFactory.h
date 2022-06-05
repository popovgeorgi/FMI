#pragma once
#include "Account.h"
struct AccountFactory
{
	static Account* Create(const char* type, const char* arguments);
};

