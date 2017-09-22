//Nate Kaldor
//CSC2431 HW2 - LongInt
//
//LongInt.cpp - Implementation of LongInt Class
#include "LongInt.h"

LongInt::LongInt(void)
{

}


LongInt::LongInt(const string v)
{
	
	for (int i = 0; i < v.length(); i++)
	{
		val.push_back(v[i]);
	}

}

LongInt::~LongInt(void)  //If necessary, decide later
{

}

// Size of LongInt value in characters
int LongInt::size(void)
{
	list <char> temp = val;
	int size = 0;

	while (!temp.empty())
	{
		temp.pop_front();
		size++;
	}

	return size;
}

LongInt operator+(const LongInt& x, const LongInt& y)
{
	list<char> first = x.val;
	list<char> second = y.val;
	char firstChar, secondChar;
	int one, two;

	while (!first.empty() && !second.empty())
	{
		firstChar = first.back();
		secondChar = second.back();

	}


	return 0;
}

LongInt operator*(const LongInt& x, const LongInt& y)
{


	return 0;
}

LongInt& LongInt::operator +=(const LongInt rhs)
{

	return *this;
}

LongInt& LongInt::operator *=(const LongInt rhs)
{

	return *this;
}


ostream& operator<<(ostream& out, const LongInt& v)
{
	//Declaring variables
	char tempChar;
	string temp;

	//Creating copies of data to modify without damaging the original
	list<char> tempList = v.val;
	int width = out.width();

	//First check output length, if larger offset with blank chars.
	if (!v.val.empty() && out.width() > v.val.size())
	{	
		while (width > v.val.size())
		{
			temp += " ";
			width--;
		}
	}

	//Iterate throught the list adding to the string until the output width is filled.
	if (!v.val.empty() && width == v.val.size() || width < v.val.size())
	{	
		for (int i = 0; i < width; i++)
		{
			tempChar = tempList.front();
			tempList.pop_front();
			temp += tempChar;
		}
	}

	//Finalizing output
	out << temp;
	
	return out;
}

istream& operator>>(istream& in, LongInt& v)
{
	char ch;
	string temp;
	int size;

	//Clear out old value, if one exists
	while (!v.val.empty())
	{
		v.val.pop_front();
	}

	//Putting new value into a string
	in >> temp;

	//Pushing that string into internal list
	size = temp.length();
	for (int i = 0; i < size; i++)
	{
		v.val.push_back(temp[i]);
	}

	return in;
}

bool operator==(const LongInt& x, const LongInt& y)
{
	list<char> first = x.val;
	list<char> second = y.val;
	
	while (!second.empty() && !first.empty()) //Fixes if second was longer than first
	{
		if (first.front() == second.front())
		{
			first.pop_front();
			second.pop_front();
		}

		else if (first.front() != second.front())
		{
			return false;
		}
	}

	if (first.empty() && second.empty())
		return true;

	else 
		return false;
}
