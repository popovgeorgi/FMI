#pragma once
#include "CarPart.h"

class Accumulator : public CarPart
{
	int m_capacity{};
	myString m_batteryId;

public:
	Accumulator(unsigned int id, myString manufacturer, myString description, int capacity, myString batteryId);
	friend ostream& operator<<(ostream& stream, const Accumulator& accumulator);
};

Accumulator::Accumulator(unsigned int id, myString manufacturer, myString description, int capacity, myString batteryId)
	: CarPart(id, manufacturer, description), m_capacity(capacity), m_batteryId(batteryId) {}

ostream& operator<<(ostream& stream, const Accumulator& accumulator)
{
	stream << (CarPart&)accumulator;
	stream << " - " << accumulator.m_capacity << " Ah";

	return stream;
}