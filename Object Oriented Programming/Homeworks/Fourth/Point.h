#pragma once
class Point
{
	int m_x{};
	int m_y{};

public:
	Point(int x = 0, int y = 0);
	double getDist(const Point& point) const;
	int getX() const;
	int getY() const;
};

Point::Point(int x, int y)
	: m_x(x), m_y(y) {}


double Point::getDist(const Point& point) const
{
	int dx = m_x - point.m_x;
	int dy = m_y - point.m_y;
	return sqrt(dx * dx + dy * dy);
}

int Point::getX() const { return m_x; }
int Point::getY() const { return m_y; }