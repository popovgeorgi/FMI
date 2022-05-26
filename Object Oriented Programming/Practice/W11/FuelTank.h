#pragma once
#include "InsufficientFuelException.h"

class FuelTank
{
	double m_capacity{};
	double m_currentAmount{};

public:
	FuelTank(double capacity);
	void fill(double amount);
	void use(double amount);

	double getCurrentAmount() const;
};

FuelTank::FuelTank(double capacity)
	: m_capacity(capacity), m_currentAmount(capacity) {}

double FuelTank::getCurrentAmount() const { return m_currentAmount; }

void FuelTank::fill(double amount)
{
	if (m_currentAmount + amount > m_capacity)
	{
		m_currentAmount = m_capacity;
	}
	else
	{
		m_currentAmount += amount;
	}
}

void FuelTank::use(double amount)
{
	if (amount > m_currentAmount)
	{
		throw InsufficientFuelException("You do not have such an amount of fuel!");
	}

	m_currentAmount -= amount;	
}