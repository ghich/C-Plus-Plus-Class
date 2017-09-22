//Nate Kaldor
//CSC2431 HW2 - LongInt Class
//
//LongInt.h - LongInt Header
//Embedded STL <list>

#pragma once

#include <iostream>
#include <list>
#include <string>
using namespace std;

class LongInt
{
public:

	LongInt(void);

	
	LongInt(const string v);


	~LongInt(void);  //If necessary, decide later


	// Size of LongInt value in characters
	int size(void);


	friend LongInt operator+(const LongInt& x, const LongInt& y);


	friend LongInt operator*(const LongInt& x, const LongInt& y);


	LongInt& operator +=(const LongInt rhs);
	
	
	LongInt& operator *=(const LongInt rhs);


	friend ostream& operator<<(ostream& out, const LongInt& v);
	
	
	friend istream& operator>>(istream& in, LongInt& v);

	
	friend bool operator==(const LongInt& x, const LongInt& y);


private:
	
	list<char> val;
};