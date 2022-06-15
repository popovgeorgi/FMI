#pragma once
#include "MyVector.hpp"
#include "Point.h"
#include "MyString.h"
#include <vector>

#pragma warning(disable: 4996)

class Shape
{
	vector<Point> m_points;
	MyString m_colour;

public:
	Shape(int pointsCount, const char* colour);

	virtual double getArea() const = 0;
	virtual double getPer() const = 0;
	virtual bool isPointIn(Point point) const = 0;
	virtual bool isWithin(const Shape& shape) const = 0;
	virtual void print() const = 0;
	virtual MyString getXMLRepresentation() const = 0;

	void translate(int vertical, int horizontal);
	void setPoint(int index, int x, int y);
	const Point& getPointAt(int index) const;

	const char* getColour() const;
};

Shape::Shape(int pointsCount, const char* colour)
	: m_points(pointsCount), m_colour(colour)
{
}

void Shape::translate(int vertical, int horizontal)
{
	for (size_t i = 0; i < m_points.size(); i++)
	{
		const Point& p = getPointAt(i);
		setPoint(i, p.getX() + vertical, p.getY() + horizontal);
	}
}

const char* Shape::getColour() const { return m_colour.getString(); }

void Shape::setPoint(int index, int x, int y)
{
	m_points[index] = Point(x, y);
}

const Point& Shape::getPointAt(int index) const
{
	return m_points[index];
}