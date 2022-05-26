#pragma once
#include "CarPart.h"
#include <iostream>

class Engine : public CarPart
{
	int m_horsePower{};

public:
	Engine(unsigned int id, myString manufacturer, myString description, int horsePower);
	friend ostream& operator<<(ostream& stream, const Engine& engine);
	int getHorsePower();
};

Engine::Engine(unsigned int id, myString manufacturer, myString description, int horsePower)
	: CarPart(id, manufacturer, description), m_horsePower(horsePower) {}
	
ostream& operator<<(ostream& stream, const Engine& engine)
{
	stream << static_cast<CarPart>(engine);
	stream << " - " << engine.m_horsePower << " hp";
	return stream;
}

int Engine::getHorsePower() { return m_horsePower; }