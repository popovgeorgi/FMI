#pragma once
#include "CarPart.h"

class Tyre : public CarPart
{
	int m_width{};
	int m_profile{};
	int m_diameter{};

public:
	Tyre(unsigned int id, myString manufacturer, myString description, int width, int profile, int diameter);
	friend ostream& operator<<(ostream& stream, const Tyre& tyre);
};

Tyre::Tyre(unsigned int id, myString manufacturer, myString description, int width, int profile, int diameter)
	: CarPart(id, manufacturer, description), m_width(width), m_profile(profile), m_diameter(diameter) {}

ostream& operator<<(ostream& stream, const Tyre& tyre)
{
	stream << (CarPart&)tyre;
	stream << " - " << tyre.m_width << "/" << tyre.m_profile << "R" << tyre.m_diameter;

	return stream;
}