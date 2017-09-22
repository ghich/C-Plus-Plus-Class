//Nate Kaldor
//HW4

#include "Computer.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//Default constructor
Computer::Computer()
{
}

//user input initializing constructor
Computer::Computer(unsigned short model, string name, float speed, float price, int stock)
{
	modelNumber = model;
	manufacturer = name;
	clockSpeed = speed;
	pricePoint = price;
	numStocked = stock;
}

//pre-release initializing constructor
//takes model number, manufacturer name, and clock speed 
//sets default values for price and number on hand
Computer::Computer(unsigned short model, string name, float speed)
{
	modelNumber = model;
	manufacturer = name;
	clockSpeed = speed;

	//Initialize value of price to 0.01 and instock to 0
	pricePoint = 0.01;
	numStocked = 0;
}


//model number mutator
void Computer::setModelNumber(unsigned short model)
{
	modelNumber = model;
}

//manufacturer name mutator
void Computer::setManufacturer(string name)
{
	manufacturer = name;
}

//clock speed mutator
void Computer::setClockSpeed(float speed)
{
	if (speed <= 0)
	{
		clockSpeed = 1.0;
	}
	clockSpeed = speed;
}

//price mutator
void Computer::setPricePoint(float price)
{
	if (price <= 0)
	{
		pricePoint = 0.01;
	}
	pricePoint = price;
}

//quantity on hand mutator
void Computer::setNumStocked(int stock)
{
	if (stock < 0)
	{
		numStocked = 0;
	}
	numStocked = stock;
}

//all data members mutator
void Computer::setAll(unsigned short model, string name, float speed, float price, int stock)
{
	modelNumber = model;
	manufacturer = name;
	clockSpeed = speed;
	pricePoint = price;
	numStocked = stock;
}

//model number accessor
unsigned short Computer::getModel() const
{
	return modelNumber;
}

//manufacturer name accessor
string Computer::getManufacturer() const
{
	return manufacturer;
}

//clock speed accessor
float Computer::getClockSpeed() const
{
	return clockSpeed;
}

//price accessor
float Computer::getPrice() const
{
	return pricePoint;
}

//quantity on hand accessor
int Computer::getNumStocked() const
{
	return numStocked;
}

//calculate value of quantity on hand utility
float Computer::calcValue() const
{
	return (pricePoint*numStocked);
}

//Display output utility
void Computer::outputData(float calcValue) const
{
	cout << setw(2) << modelNumber << " " << setw(8) << manufacturer << " " << setw(4) << fixed << setprecision(2) << clockSpeed << "Ghz " << pricePoint << " " << calcValue << endl;
}