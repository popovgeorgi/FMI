#pragma once
#include "myString.h"

class CarPart
{
	const unsigned int m_id;
	const myString m_manufacturer;
	myString m_description;

public:
	CarPart(unsigned int id, myString manufacturer, myString description);
	friend ostream& operator<<(ostream& stream, const CarPart& carPart);
};

CarPart::CarPart(unsigned int id, myString manufacturer, myString description)
	: m_id(id), m_manufacturer(manufacturer), m_description(description) {}

ostream& operator<<(ostream& stream, const CarPart& carPart)
{
	stream << "(" << carPart.m_id << ")" << " by " << carPart.m_manufacturer;
	stream << " - " << carPart.m_description;
	return stream;
}