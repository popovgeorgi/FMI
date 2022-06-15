#include <iostream>
#include "Rectangle.h"
#include "Shape.h"
#include <fstream>
#include "Read.h"
#include "ShapeFactory.h"
#include <vector>
#include "Write.h";

int main()
{
    char fileName[100];
    std::cin >> fileName;
    std::vector<Shape*> shapes;

    readFromFile(fileName, shapes);

    char command[50];
    std::cin >> command;
    while (true)
    {
        if (strcmp(command, "print") == 0)
        {
            for (size_t i = 0; i < shapes.size(); i++)
            {
                std::cout << i + 1 << ". ";
                shapes[i]->print();
            }
        }
        else if (strcmp(command, "create") == 0)
        {
            char figure[20];
            std::cin >> figure;
            std::cin.get();
            char description[100];
            std::cin.getline(description, 100);

            Shape* shape = ShapeFactory::Create(figure, description);
            shapes.push_back(shape);
        }
        else if (strcmp(command, "erase") == 0)
        {
            int id;
            std::cin >> id;
            vector<Shape*>::iterator it;

            it = shapes.begin() + id;
            shapes.erase(it);
        }
        else if (strcmp(command, "areas") == 0)
        {
            for (size_t i = 0; i < shapes.size(); i++)
            {
                std::cout << shapes[i]->getArea() << std::endl;
            }
        }
        else if (strcmp(command, "pers") == 0)
        {
            for (size_t i = 0; i < shapes.size(); i++)
            {
                std::cout << shapes[i]->getPer() << std::endl;
            }
        }
        else if (strcmp(command, "translate") == 0)
        {
            char attr[50];

            std::cin >> attr;
            int vert = atoi(getAttributeValueAfterSign(attr, '=').getString());

            std::cin >> attr;
            int hor = atoi(getAttributeValueAfterSign(attr, '=').getString());

            for (size_t i = 0; i < shapes.size(); i++)
            {
                shapes[i]->translate(vert, hor);
            }
        }
        else if (strcmp(command, "pointIn") == 0)
        {
            int x, y;
            std::cin >> x >> y;
            for (size_t i = 0; i < shapes.size(); i++)
            {
                if (shapes[i]->isPointIn(Point(x, y)))
                {
                    shapes[i]->print();
                }
            }
        }
        else if (strcmp(command, "within") == 0)
        {
            char figure[20];
            std::cin >> figure;
            std::cin.get();
            char description[100];
            std::cin.getline(description, 100);

            Shape* shape = ShapeFactory::Create(figure, description);
            for (size_t i = 0; i < shapes.size(); i++)
            {
                if (shapes[i]->isWithin(*shape))
                {
                    shapes[i]->print();
                }
            }

            delete shape;
        }
        else if (strcmp(command, "exit") == 0)
        {
            writeIntoFile("figures.svg", shapes);
            break;
        }
        else
        {
            std::cout << "Wrong input!" << std::endl;
        }

        std::cin >> command;
    }
}