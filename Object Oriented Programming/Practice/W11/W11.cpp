// W11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FuelTank.h"
#include "Engine.h"
#include "Tyre.h"
#include "Accumulator.h"
#include "Car.h"

using namespace std;

int main()
{
	// smart pointers
	Engine* engine = new Engine(1, "Audi", "Best", 200);
	Accumulator* accumulator = new Accumulator(1, "Audi", "Best", 20, "xhshw23lsa");
	Tyre tyre1(1, "Audi", "Best", 15, 15, 15);
	Tyre* tyres[4] = { &tyre1, &tyre1, &tyre1, &tyre1 };


	Car car1(15, engine, tyres, accumulator, 500);
	Car car2(25, engine, tyres, accumulator, 500);

	try
	{
		car1.drive(100000);
	}
	catch (InsufficientFuelException ex)
	{
		cout << ex.what();
	}

	Car* car = dragRace(&car1, &car2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
