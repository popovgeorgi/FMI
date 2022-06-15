#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

class ShapeFactory
{
public:
	static Shape* Create(const char* figure, char* description);
};

Shape* ShapeFactory::Create(const char* figure, char* description)
{
	if (strcmp(figure, "rectangle"))
	{
		char* value = strtok(description, " ");
		int x1 = atoi(value);

		value = strtok(NULL, " ");
		int y1 = atoi(value);

		value = strtok(NULL, " ");
		int width = atoi(value);

		value = strtok(NULL, " ");
		int height = atoi(value);

		value = strtok(NULL, " ");
		if (value == NULL)
		{
			return new Rectangle(x1, y1, width, height, nullptr);
		}
		else
		{
			return new Rectangle(x1, y1, width, height, value);
		}
	}
	else if (strcmp(figure, "circle"))
	{
		char* value = strtok(description, " ");
		int x1 = atoi(value);

		value = strtok(NULL, " ");
		int y1 = atoi(value);

		value = strtok(NULL, " ");
		int radius = atoi(value);

		value = strtok(NULL, " ");
		if (value == NULL)
		{
			return new Circle(x1, y1, radius, nullptr);
		}
		else
		{
			return new Circle(x1, y1, radius, value);
		}
	}

	return nullptr;
}
