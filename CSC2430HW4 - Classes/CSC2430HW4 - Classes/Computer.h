//Nate Kaldor
//HW4

#include <string>
#include <iostream>

using namespace std;

#ifndef COMPUTER_DEF
#define COMPUTER_DEF

class Computer
{
public:
	//================== CONSTRUCTORS ===================

	//Default constructor
	//Arguments: none
	//Effects: the model number, manufacturer name, clock speed, price point, and
	//quantity on hand are set to compiler defaults
	//(Please set manually after using this constructor)
	Computer();

	//Constructor to initialize the model number, manufacturer name, clock speed, price point, and 
	//quantity on hand are passed in.
	//Arguments: the model number, manufacturer name, clock speed, price point, and 
	//quantity on hand 
	//Effects: model number, manufacturer name, clock speed, price point, and quantity
	//are all set
	Computer(unsigned short, string, float, float, int);

	//Constructor to initialize a computer into inventory database prior to being in stock 
	//Arguments: the model number, manufacturer name, and clock speed
	//Effects: the model number, manufacturer name, and clock speed are set
	// the price is set to 0.01, and quantity to 0.
	Computer(unsigned short, string, float);

	//================== MUTATORS ======================
	
	//Mutator to set the model number of a computer already in the inventory
	//Arguments: model number as an unsigned short
	//Effects: the model number is set
	void setModelNumber(unsigned short);

	//Mutator to set the manufacturer name of a computer already in the inventory
	//Arguments: manufacturer/brand name as a string
	//Effects: the manufacturer is set
	void setManufacturer(string);

	//Mutator to set the CPU clock speed of a computer already in the inventory
	//Arguments: clock speed as a float
	//Effects: the CPU clock speed is set
	void setClockSpeed(float);

	//Mutator to set the price of a computer in the inventory
	//Arguments: price as a float
	//Effects: sets the price of the computer
	void setPricePoint(float);

	//Mutator to adjust the quantity on hand of a particular computer
	//Argument: the number of that type of computer on hand
	//Effects: the number in stock is set
	void setNumStocked(int);

	//Mutator to modify the model number, manufacturer/brand name, CPU clock speed, price
	//and quantity on hand of a computer already in the inventory
	//Argument: the model number, manufacturer name, clock speed, price point, and 
	//quantity on hand 
	//Effects: model number, manufacturer name, clock speed, price point, and quantity
	//are all set
	void setAll(unsigned short, string, float, float, int);

	//================== ACCESSORS ======================

	//Accessor to return the object's model number member
	//Parameters: none
	//Returns: the model number (unsigned short)
	unsigned short getModel() const;

	//Accessor to return the object's manufacturer member
	//Parameters: none
	//Returns: the manufacturer name (string)
	string getManufacturer() const;

	//Accessor to return the object's clock speed member
	//Parameters: none
	//Returns: the clock speed (float)
	float getClockSpeed() const;

	//Accessor to return the object's price
	//Parameters: none
	//Returns: the price (float)
	float getPrice() const;

	//Accessor to return the object's number stocked member
	//Parameters: none
	//Returns: number stocked (int)
	int getNumStocked() const;


	//================== PUBLIC UTILITIES ======================

	//Utility to calculate the value of the quantity on hand
	//Arguments: inventory number and price point
	//Effects: returns the value of the current inventory
	float calcValue() const;

	//Utility to output the data of the computer to the screen with no descriptions
	//Arguments: model, manufacturer, clock speed, price, quantity stocked, value of instock
	//Effects: outputs inventory data to the screen
	//model - manufacturer - clock speed - price point - number stocked - value of instock
	void outputData(float) const;


private:
	//============DATA MEMBERS============
	//Variables to store the model number, manufacturer/brand name
	//the clock speed, the price, and the quantity on hand (number stocked)
	unsigned short modelNumber;
	string manufacturer;
	float clockSpeed, pricePoint;
	int numStocked;

};
#endif