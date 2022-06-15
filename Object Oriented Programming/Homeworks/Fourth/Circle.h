#pragma once
#include <iostream>
#include "Shape.h"
#include "Helpers.h"

class Circle : public Shape
{
	int m_radius;
public:
	Circle(int x1, int y1, int radius, const char* colour);
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(Point point) const override;
	bool isWithin(const Shape& shape) const override;
	void print() const override;
	MyString getXMLRepresentation() const override;
};

MyString Circle::getXMLRepresentation() const
{
	int x0 = getPointAt(0).getX();
	int y0 = getPointAt(0).getY();
	const char* colour = getColour();
	//<circle cx="5" cy="5" r="10" fill="blue" />
	MyString res{};
	res += "<circle cx=\"";
	res += getString(x0);
	res += "\" cy=\"";
	res += getString(y0);
	res += "\" r=\"";
	res += getString(m_radius);
	res += "\" fill=\"";
	res += colour;
	res += "\" />";
	res += "\n";

	return res;
}

double Circle::getArea() const
{
	double pi = 3.14;
	return pi * m_radius * m_radius;
}

double Circle::getPer() const
{
	double pi = 3.14;
	return 2 * pi * m_radius;
}

void Circle::print() const
{
	int x0 = getPointAt(0).getX();
	int y0 = getPointAt(0).getY();
	const char* colour = getColour();

	std::cout << "Circle" << " " << x0 << " " << y0 << " " << m_radius << " " << colour << std::endl;
}

bool Circle::isWithin(const Shape& shape) const
{
	const Point& center = getPointAt(0);
	if (shape.isPointIn(Point(center.getX() - m_radius, center.getY())) && shape.isPointIn(Point(center.getX() + m_radius, center.getY())) &&
		shape.isPointIn(Point(center.getX(), center.getY() + m_radius)) && shape.isPointIn(Point(center.getX(), center.getY() - m_radius)))
	{
		return true;
	}

	return false;
}

bool Circle::isPointIn(Point point) const
{
	int dx = point.getX() - getPointAt(0).getX();
	int dy = point.getY() - getPointAt(0).getY();

	if (sqrt(dx*dx + dy*dy) <= m_radius)
	{
		return true;
	}

	return false;
}

Circle::Circle(int x1, int y1, int radius, const char* colour)
	:Shape(2, colour), m_radius(radius)
{
	setPoint(0, x1, y1);
	setPoint(1, x1 + radius, y1);
}