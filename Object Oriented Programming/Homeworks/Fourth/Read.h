#pragma once
#include <iostream>
#include "Rectangle.h"
#include "Shape.h"
#include "Circle.h"
#include <fstream>
#include <vector>

#pragma warning(disable: 4996)

MyString getAttributeValueAfterSign(const char* attribute, char sign)
{
    char value[10];
    int index = 0;
    int attributeLen = strlen(attribute);
    for (size_t i = 0; i < attributeLen; i++)
    {
        if (attribute[i] == sign)
        {
            for (size_t j = i + 1; j < attributeLen - 1; j++)
            {
                value[index++] = attribute[j];
            }

            value[index] = '\0';
        }
    }

    return MyString(value);
}

void readFromFile(const char* name, std::vector<Shape*>& shapes)
{
    std::ifstream inFile(name);
    if (!inFile.is_open())
    {
        std::cout << "File does not exist" << std::endl;
        return;
    }

    char input[200];
    while (true)
    {
        inFile.getline(input, 200);
        if (strcmp(input, "<svg>") == 0)
        {
            char element[200];

            while (true)
            {
                inFile >> element;

                if (strcmp(element, "<rect") == 0)
                {
                    char attribute[50];

                    inFile >> attribute;
                    int x1 = atoi(getAttributeValueAfterSign(attribute, '\"').getString());

                    inFile >> attribute;
                    int y1 = atoi(getAttributeValueAfterSign(attribute, '\"').getString());

                    inFile >> attribute;
                    int x3 = atoi(getAttributeValueAfterSign(attribute, '\"').getString()) + x1;

                    inFile >> attribute;
                    int y3 = y1 - atoi(getAttributeValueAfterSign(attribute, '\"').getString());

                    inFile >> attribute;
                    MyString colour = getAttributeValueAfterSign(attribute, '\"');

                    Shape* shape = new Rectangle(x1, y1, x3, y3, colour.getString());
                    shapes.push_back(shape);
                }
                else if (strcmp(element, "<circle") == 0)
                {
                    char attribute[50];

                    inFile >> attribute;
                    int x0 = atoi(getAttributeValueAfterSign(attribute, '\"').getString());

                    inFile >> attribute;
                    int y0 = atoi(getAttributeValueAfterSign(attribute, '\"').getString());

                    inFile >> attribute;
                    int radius = atoi(getAttributeValueAfterSign(attribute, '\"').getString());

                    inFile >> attribute;
                    MyString colour = getAttributeValueAfterSign(attribute, '\"');

                    Shape* shape = new Circle(x0, y0, radius, colour.getString());
                    shapes.push_back(shape);
                }
                else if (strcmp(element, "<line") == 0)
                {

                }
                else if (strcmp(element, "</svg>") == 0)
                {
                    break;
                }
            }

            break;
        }
    }
}