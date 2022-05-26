#pragma once
#include <cmath>
#include "FuelTank.h"
#include "Engine.h"
#include "Tyre.h"
#include "Accumulator.h"

class Car
{
	double m_kilometersPassed{};
	int m_weight{};
	Engine* m_engine{};
	Tyre* m_tyres[4];
	Accumulator* m_accumulator{};
	FuelTank m_tank;

	double getFuelExpenditure(double kilometers);

public:
	Car(int weight, Engine* engine, Tyre* tyres[4], Accumulator* accumulator, double tankCapacity)
		: m_tank(tankCapacity), m_engine(engine), m_accumulator(accumulator), m_weight(weight) 
	{
		for (size_t i = 0; i < 4; i++)
		{
			m_tyres[i] = tyres[i];
		}
	}

	const FuelTank& getFuelTank();
	void drive(double kilometers);
	friend Car* dragRace(Car* car1, Car* car2);
};

const FuelTank& Car::getFuelTank()
{
	return m_tank;
}

double Car::getFuelExpenditure(double kilometers)
{
	return ((log(m_engine->getHorsePower()) + log(m_weight)) / 100)* kilometers;
}

void Car::drive(double kilometers)
{
	m_tank.use(getFuelExpenditure(kilometers));
	m_kilometersPassed += kilometers;
}

Car* dragRace(Car* car1, Car* car2)
{
	bool isCar1Eligible = car1->getFuelTank().getCurrentAmount() - car1->getFuelExpenditure(0.4) >= 0 ? true : false;
	bool isCar2Eligible = car2->getFuelTank().getCurrentAmount() - car2->getFuelExpenditure(0.4) >= 0 ? true : false;

	if (!isCar1Eligible)
	{
		if (!isCar2Eligible)
		{
			return nullptr;
		}
		else
		{
			return car2;
		}

		return car1;
	}
	else
	{
		if (!isCar2Eligible)
		{
			return car1;
		}

		car1->drive(0.4);
		car2->drive(0.4);

		return (car1->m_engine->getHorsePower() / car1->m_weight) / (car2->m_engine->getHorsePower() / car2->m_weight) > 1 ? car1 : car2;
	}
}

