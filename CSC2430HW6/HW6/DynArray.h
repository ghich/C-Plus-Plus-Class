//DynArray.h - Dynamic Array of (for now) floats
#ifndef DYN_ARRAY
#define DYN_ARRAY

using namespace std;
typedef float elementType;              //Makes DynArray a "reusable container"

class DynArray
{
public:

	//Default constructor
	//Creates dynamic array of elementType with capacity of 0
	DynArray();

	//Constructor
	//Creates dynamic array of elementType with capacity passed in (int)
	// If capacity is < 0, capacity is set to 0
	DynArray(int);

	//Copy constructor
	//Takes another DynArray as parameter, copies all private
	// data into this object.  NOTE: copy constructor NEEDS
	// to take a reference parameter, and we use const for safety.
	DynArray(const DynArray&);

	//Destructor, frees memory used by the dynamic array
	~DynArray();

	//Accessor to return array capacity
	//No Parameters
	//Returns: the array's capacity (an int)
	unsigned int getCapacity() const;

	//Accessor to return element at position
	//Parameters: position to add element at (an int)
	//Returns: array element (elementType) at position
	elementType getValue(int) const;

	//Utility function to output the array one elementType per line
	//No parameters
	//Returns nothing
	//Changes nothing
	void outputArray() const;

	//Mutator that adds a data item at a given spot, at end if no spot given
	//Parameters: the element to add (elementType), and the position (int, default -1)
	//Returns: nothing
	void addElement(elementType, int = -1);




	void halfSize();




	void doubleSize(unsigned int);

	//Parameters: array to sort (array of integers), length of array (an integer)
	//Returns: nothing (but array will be sorted)
	//Description: use selection sort to sort an array of integers
	void sortArray();



	bool linearSearch(elementType);



	int binarySearch(elementType);


private:
	elementType *pArr;      //pointer to 1st element
	unsigned int capacity;          //(current) size of the array
	bool isSorted; //True/false is dynaArray

	//Function to copy elements from one array to another
	//Parameters: the array to copy from (elementType*), the array to copy to (elementType*)
	// the # of elements to copy (int)
	//Returns: nothing
	//Effects: up to n elements of 2nd array are copied into first
	void copy(elementType*, elementType*, unsigned int n);

	//Deep copy of DynArray objects
	//Parameters: the DynArray to copy from
	//Returns: nothing
	//Effects: this object's private member variables set to original's
	// via a deep copy
	void deepCopy(const DynArray&);
};

#endif