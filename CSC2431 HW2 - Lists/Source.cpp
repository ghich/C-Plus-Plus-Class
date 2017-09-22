//Nate Kaldor
//CSC2431 - HW2
//Long int addition and multiplication

#include <iostream>
#include <iomanip>
#include <cmath>
#include "LongInt.h"

using namespace std;

int main()
{
	system("cls");
	//Testing constructors
	//Works
	LongInt test("123");
	LongInt testTwo("123");

	//Checking << overloaded operator
	//Works
	cout << setw(7) << test << endl;

	//Checking size function
	//Works
	cout << test.size() << endl;

	//Checking == overloaded operator
	//Works
	cout << boolalpha;
	cout << (test == testTwo) << endl;

	//Checking >> overloaded operator
	//Works -- Best I can tell.
	cout << "Test stream extraction operator overload: " << endl;
	cin >> test;


	return 0;
}