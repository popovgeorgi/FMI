#pragma once
#include "Shape.h"
#include "Helpers.h"

class Rectangle : public Shape
{
public:
	Rectangle(int x1, int y1, int x3, int y3, const char* colour);
	double getArea() const override;
	double getPer() const override;
	bool isPointIn(Point point) const override;
	bool isWithin(const Shape& shape) const override;
	void print() const override;
	MyString getXMLRepresentation() const override;
};

Rectangle::Rectangle(int x1, int y1, int x3, int y3, const char* colour)
	: Shape(4, colour)
{
	setPoint(0, x1, y1);
	setPoint(1, x3, y1);
	setPoint(2, x3, y3);
	setPoint(3, x1, y3);
}

MyString Rectangle::getXMLRepresentation() const
{
	MyString res{};
	int x1 = getPointAt(0).getX();
	int y1 = getPointAt(0).getY();
	int width = getPointAt(2).getX() - x1;
	int height = y1 - getPointAt(2).getY();
	const char* colour = getColour();

	res += "<rect x=\"";
	res += getString(x1);
	res += "\" y=\"";
	res += getString(y1);
	res += "\" width=\"";
	res += getString(width);
	res += "\" height=\"";
	res += getString(height);
	res += "\" fill=\"";
	res += colour;
	res += "\" />";
	res += "\n";

	return MyString(res);
}

void Rectangle::print() const
{
	int x1 = getPointAt(0).getX();
	int y1 = getPointAt(0).getY();
	int width = getPointAt(2).getX() - x1;
	int height = y1 - getPointAt(2).getY();
	const char* colour = getColour();

	std::cout << "Rectangle" << " " << x1 << " " << y1 << " " << width << " " << height << " " << colour << std::endl;
}

double Rectangle::getArea() const
{
	Point p0 = getPointAt(0);
	Point p1 = getPointAt(1);
	Point p3 = getPointAt(3);
	return p0.getDist(p1) * p0.getDist(p3);
}

double Rectangle::getPer() const
{
	return (getPointAt(0).getDist(getPointAt(1)) * 2) + (getPointAt(0).getDist(getPointAt(3)) * 2);
}

bool Rectangle::isPointIn(Point point) const
{
	if (getPointAt(0).getX() <= point.getX() && getPointAt(1).getX() >= point.getX())
	{
		if (getPointAt(3).getY() <= point.getY() && getPointAt(0).getY() >= point.getY())
		{
			return true;
		}
	}

	return false;
}

bool Rectangle::isWithin(const Shape& shape) const 
{
	if (shape.isPointIn(getPointAt(0)) && shape.isPointIn(getPointAt(1)) &&
		shape.isPointIn(getPointAt(2)) && shape.isPointIn(getPointAt(3)))
	{
		return true;
	}

	return false;
}