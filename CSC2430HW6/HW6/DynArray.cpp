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

	for (int i = (capacity); i < timesTwo; i++)
	{
		pArr[i] = 0;
	}

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
	int i = 0;

	while (i < capacity)
	{
		if (i < capacity)
			cout << setw(8) << pArr[i];
		i++;
		if (i < capacity)
			cout << setw(8) << pArr[i];
		i++;
		if (i < capacity)
			cout << setw(8) << pArr[i];
		i++;
		if (i < capacity)
			cout << setw(8) << pArr[i];
		i++;
		if (i < capacity)
			cout << setw(8) << pArr[i] << '\n';
		i++;
	}

	//for (i = 0; i < (capacity - 5); i++)
	//	cout << setw(8) << pArr[i] << '\n';
	//cout << endl;
}

//Selection sort function
void DynArray::sortArray()
{
	if (isSorted == true)
	{
		cout << "This array is already sorted. There is nothing to sort." << endl;
	}

	else
	{
		int index, smallestIndex, location;
		int temp; //for swap, ok variable name since is a temporary value!

		//pick a starting value: first starting value is 0, last is capacity - 2
		for (index = 0; index < capacity - 1; index++)
		{
			smallestIndex = index;
			//find the smallest element in the rest of the array
			for (location = index + 1; location < capacity; location++)
				if (pArr[location] < pArr[smallestIndex])
					smallestIndex = location;

			//swap elements, need temporary storage so don't clobber
			//	one of the elements before we can swap it!
			temp = pArr[smallestIndex];
			pArr[smallestIndex] = pArr[index];
			pArr[index] = temp;
		}
		isSorted = true;
	}
}

bool DynArray::linearSearch(elementType searchKey)
{
	int loc;
	bool found = false;

	//starting position to search in array 
	loc = 0;

	//step through array until hit end, or find item
	while (loc < capacity && !found)
	{
		//compare key to current element
		if (pArr[loc] == searchKey)
			found = true;
		else
			loc++;
	}

	//return the location of the item, or -1 if not in array
	if (found)
		return true;
	else
		return false;
	
}

int DynArray::binarySearch(elementType key)
{
	int left, right, midpt;

	//set left and right to select correct starting midpoint
	left = 0;
	right = capacity - 1;


	if (isSorted == false)
		return -1;

	//loop until we have only 1 element left
	// when 1 element is left, it either matches the key, or the 
	// key was not in the array
	while (left <= right)
	{
		midpt = (left + right) / 2;

		//if the midpoint is equal to key, have found what we're looking for!
		if (key == pArr[midpt])
		{
			return 1;		//return location where found
		}
		//otherwise, the key is either to the right of the midpoint
		else if (key > pArr[midpt])
		{
			//update left bound to be one past midpoint
			//i.e., throw out everything to left of midpoint (including midpoint)
			left = midpt + 1;
		}
		//or to the left of the midpoint
		else
		{
			//update right bound to be one before midpoint
			//i.e., throw out everything to right of midpoint (including midpoint)
			right = midpt - 1;
		}
	}

	//-1 means "not found"
	return 0;
}

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

	//Updating with the bool to be deep copied
	isSorted = original.isSorted;

}
