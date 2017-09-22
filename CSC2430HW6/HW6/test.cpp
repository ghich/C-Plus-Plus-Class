//Meriadoc Brandybuck
//2-18-15
//CSC2430
//Client to test dynArray
#include <iostream>
#include "DynArray.h"

using namespace std;

int main()
{
	system("cls");
	//create an array with 10 elements
	DynArray myArr(10);
	int size = myArr.getCapacity();
	cout << "Capacity of array is: " << size << endl;
	cout << "Initial contents: " << endl;
	myArr.outputArray();

	for (int i = 0; i < size; i++)
		myArr.addElement(i * 10, i);

	cout << "Final contents: " << endl;
	myArr.outputArray();

	cout << "Array contents at position 5: " << endl;
	cout << myArr.getValue(5) << endl;

	//add an element
	myArr.incSize();
	cout << "Contents after incSize: " << endl;
	myArr.outputArray();

	//test resize (with smaller array size)
	myArr.resize(10);
	cout << "Contents after resize (back to original): " << endl;
	myArr.outputArray();

	//test resize (with larger array size)
	myArr.resize(15);
	cout << "Contents after resize (up to large size): " << endl;
	myArr.outputArray();
	cout << "Capacity is now:"  << myArr.getCapacity() << endl;

	myArr.addElement(12345.6789, 20);
	cout << "Contents after adding: " << endl;
	myArr.outputArray();
	cout << "Capacity is now:" << myArr.getCapacity() << endl;


	myArr.addElement(12345.6789, 5);
	cout << "Contents after adding: " << endl;
	myArr.outputArray();
	cout << "Capacity is now:" << myArr.getCapacity() << endl;

	myArr.addElement(1.5, -1);
	cout << "Contents after adding: " << endl;
	myArr.outputArray();
	cout << "Capacity is now:" << myArr.getCapacity() << endl;

	
	DynArray arrayTwo(myArr);
	cout << "TESTING COPY CONSTRUCTOR" << endl;
	arrayTwo.outputArray();

	return 0;
}