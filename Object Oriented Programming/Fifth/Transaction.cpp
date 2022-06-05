#include "Transaction.h"

Transaction::Transaction() {}

Transaction::Transaction(const char* from, const char* to, double amount)
	:m_from(from), m_to(to), m_amount(amount){}