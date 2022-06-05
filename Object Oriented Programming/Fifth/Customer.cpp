#include "Customer.h"

Customer::Customer() {}

Customer::Customer(int id, const char* name, const char* address)
	: m_id(id), m_name(name), m_address(address) {}

void Customer::print() const
{
	std::cout << "Id: " << m_id << std::endl;
}

int Customer::getId() const { return m_id; }