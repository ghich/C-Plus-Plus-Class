//Aaron Dingler
//CSC2430
//2-28-15
//Implementation of Hobbit class using MyString
// this can form the basis for your HW7
// or you can use your implementation

#include "Hobbit.h"

using namespace std;

//Default constructor
Hobbit::Hobbit()
{
	antecedent = NULL;
	descendent = NULL;
	birthYear = 0;
	
}

Hobbit::Hobbit(MyString& n, unsigned short a, Hobbit *an, Hobbit *d)
{
	antecedent = an;
	descendent = d;

	name = new MyString(n);
  //Note: will always be >= 0, since we are using
  // an unsigned short.  If you use a signed int for some
  // reason, need to make sure it is >=0!
	birthYear = a;
}

//Destructor
Hobbit::~Hobbit()
{
	delete name;
}

Hobbit* Hobbit::getDescendent() const
{
	return descendent;
}

MyString Hobbit::getName() const
{
	return *name;
}

unsigned short Hobbit::getBirthYear() const
{
	return birthYear;
}

Hobbit* Hobbit::getAntecedent() const
{
	return antecedent;
}

void Hobbit::setAntecedent(Hobbit *a)
{
	antecedent = a;
}

void Hobbit::setDescendent(Hobbit *d)
{
	descendent = d;
}

void Hobbit::setName(MyString& n)
{
	delete name;
	name = new MyString(n);
}

void Hobbit::setBirthYear(unsigned short a)
{
  //No need to check for age >=0
  // since working with unsigned short
  // BUT if you went "off script"
  // for the assignment and used an int, 
  // would need to check
	birthYear = a;
}

bool Hobbit::isParentOf(Hobbit *child)
{
  //Is this the parent of child?
  //Simply check child's antecedent,
  // (and doesn't hurt to check descendent of this too)
  if((child->getAntecedent() == this) && (this->getDescendent() == child))
    return true;

  return false;
}

unsigned short Hobbit::calculateAge(unsigned short currentYear)
{
	unsigned short age = 0;
	age	= (currentYear - birthYear);
	return age;
}
