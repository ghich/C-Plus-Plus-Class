//DynArray.cpp - function implementations
#include <iostream>
#include "DynArray.h"
#include <iomanip>

using namespace std;

//Constructors and Destructor

//Default constructor
//Create a pointer to an empty array of capacity 0
DynArray::DynArray()
{
	capacity = 0;
	pArr = new elementType[capacity];
	isSorted = false;
}

//Copy constructor
//Current object gets deep copy of original object (passed in)
DynArray::DynArray(const DynArray& original)
{
	deepCopy(original);
}

//Constructor to create an array with a given number of elements
DynArray::DynArray(int size)
{
	if (size < 0)
		capacity = 0;
	else
		capacity = size;
	pArr = new elementType[capacity];
	isSorted = false;
}

//Destructor
DynArray::~DynArray()
{
	delete[] pArr;
}

//Add a data item at a given spot in the array
//Default is end of array (if here not specified, or set to -1)
void DynArray::addElement(elementType val, int here)
{
	//store at end if -1 (default) passed in,
	//or any other negative number
	if (here < 0)
		pArr[capacity - 1] = val;

	//otherwise, if within bounds, update value
	else if (here < capacity && here >= 0)
		pArr[here] = val;

	//need else if to account for unsigned to signed comparison
	else if (here > capacity)
	{

		doubleSize(here);
		pArr[here] = val;
	}

	//Element added = array is not sorted, changing the bool
	isSorted = false;
}

void DynArray::halfSize() //Cuts size of the array in half
{
	unsigned int half = (capacity / 2);

	elementType *temp = new elementType[half];

	copy(pArr, temp, half);

	delete[] pArr;

	pArr = temp;

	temp = NULL;

	capacity = half;
}

void DynArray::doubleSize(unsigned int timesTwo)
{
	timesTwo = (capacity * 2);

	elementType *temp = new elementType[timesTwo];

	copy(pArr, temp, timesTwo);

	delete[] pArr;

	pArr = temp;

	temp = NULL;

	capacity = timesTwo;
}

//Accessors

//Accessor - get array size
unsigned int DynArray::getCapacity() const
{
	return capacity;
}

//Accessor - return a given element
elementType DynArray::getValue(int here) const
{
	//No subscript validation (may be useful to add
	// to help you when testing homework!)
	return pArr[here];
}

//Utilities
//Output the array one elementType per line
void DynArray::outputArray() const
{
	int i;

	for (i = 0; i < (capacity); i++)
		cout << setw(8) << pArr[i] << '\n';
	cout << endl;
}

//Linear sort function


//Private member functions
//Copying from ptrOne into ptrTwo
void DynArray::copy(elementType *ptrOne, elementType* ptrTwo, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		ptrTwo[i] = ptrOne[i];

}

//Perform a deep copy.  Contents of original --> this
void DynArray::deepCopy(const DynArray& original)
{

	capacity = original.capacity;
	pArr = new elementType[capacity];
	copy(original.pArr, pArr, capacity);

	//Updating the bool to be deep copied
	isSorted = original.isSorted;

}