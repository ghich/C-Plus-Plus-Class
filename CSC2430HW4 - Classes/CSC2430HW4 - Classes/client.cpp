//Nate Kaldor
//CSC2430 - HW4
//This homework is an exercise in class creation: Creates an array of computers shown as inventory
//to a small store--outputs two different ways.

#include "Computer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Global constant
const int MAX = 10;

//Function prototype
void formattedDisplay(Computer[], int);

int main()
{
	//Declaring variables
	Computer inventory[MAX];	//Array of computers
	fstream computers;
	float clock, price, value;
	int stock;
	string brand;
	unsigned short modelNumber;

	//This uses the second constructor to initialize a pc
	//which will default the price and inventory count to 0.01 and 0
	Computer dell(17, "Dell", 3.33);
	float dellValue;
	dellValue = dell.calcValue();
	cout << "Demonstrating third constructor to initiliaze default values: " << endl;
	dell.outputData(dellValue);
	cout << endl;

	//Reading from file to create the array
	computers.open("C:\\Users\\TRON\\documents\\visual studio 2013\\Projects\\CSC2430HW4 - Classes\\CSC2430HW4 - Classes\\computers.txt");
	//Testing the input file
	if (computers.fail())
	{
		cout << "Input file failed to open!" << endl;
		exit(1); //exit with bad code
	}

	//Initialize the datatype array from the .txt file
	//Tested this by stepping through with the debugger
	int i = 0;
	while (computers.good() && i < MAX)
	{
		//Loading the variables with the data in the file
		computers >> modelNumber >> brand >> clock >> price >> stock;
		//Using mutator to set all data members
		inventory[i].setAll(modelNumber, brand, clock, price, stock);
		i++;
	}
	//Close the file
	computers.close();

	cout << "Demonstrating class function for displaying data: " << endl;
	//This for loop outputs from the output function in the class
	for (int j = 0; j < MAX; j++)
	{
		value = inventory[j].calcValue();
		inventory[j].outputData(value);
	}
	cout << endl;


	//Created an object to test the mutators
	Computer userTestMutators;
	//Tests all mutators
	userTestMutators.setModelNumber(modelNumber);
	userTestMutators.setManufacturer(brand);
	userTestMutators.setClockSpeed(clock);
	userTestMutators.setPricePoint(price);
	userTestMutators.setNumStocked(stock);
	value = userTestMutators.calcValue();
	//This should output same model as the last row in the txt file
	cout << "Demonstrating mutators work: " << endl;
	userTestMutators.outputData(value);
	cout << endl;


	//Calling display function
	formattedDisplay(inventory, MAX);

	return 0;
}

//Description: This function outputs data from the Computer array
//Parameters: Computer array and size
//Returns: Nothing
void formattedDisplay(Computer inventoryData[], int MAX)
{
	//Declaring variables
	float clock, price, value;
	int stock;
	string brand;
	unsigned short modelNumber;

	cout << "Demonstrating client function for displaying data: " << endl;
	//For loop to access all elements of the array
	for (int j = 0; j < MAX; j++)
	{
		//Using all accessors
		modelNumber = inventoryData[j].getModel();
		brand = inventoryData[j].getManufacturer();
		clock = inventoryData[j].getClockSpeed();
		price = inventoryData[j].getPrice();
		stock = inventoryData[j].getNumStocked();
		//Calculating the value
		value = inventoryData[j].calcValue();

		//Formatted output from this function
		cout << left << "Model: " << setw(3) << modelNumber << " Brand: " << setw(8) << brand << " CPU Speed: " << clock << "Ghz" << endl;
		cout << setw(2) << right << stock << " in inventory at: $" << price << " each. Total value of $" << value << endl << endl;
	}


}