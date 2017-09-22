//Aaron Dingler
//CSC2430
//2-28-15
//Implementation of Hobbit class using MyString
// this can form the basis for your HW7
// or you can use your implementation

#include "Hobbit.h"
#include <iostream>
#include <string>


using namespace std;

Hobbit::Hobbit(string n, unsigned short a, Hobbit *an, Hobbit *d, Hobbit *sib)
{
	antecedent = an;
	descendent = d;
	sibling = sib;
	name = n;

  //Note: will always be >= 0, since we are using
  // an unsigned short.  If you use a signed int for some
  // reason, need to make sure it is >=0!
	age = a;
}

Hobbit* Hobbit::getDescendent() const
{
	return descendent;
}

string Hobbit::getName() const
{
	return name;
}

unsigned short Hobbit::getAge() const
{
	return age;
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

void Hobbit::setName(string n)
{
	name = n;
}

void Hobbit::setAge(unsigned short a)
{
  //No need to check for age >=0
  // since working with unsigned short
  // BUT if you went "off script"
  // for the assignment and used an int, 
  // would need to check
	age = a;
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

bool Hobbit::searchSibling(string key)
{
	Hobbit *temp = this;
	Hobbit *tempSib = sibling;
	string tempName;

	while (tempSib != NULL)
	{
		tempName = temp->getName;
		if (tempName == key)
			return true;
		else
			temp = temp->sibling;
	}

	return false;
}


Hobbit Hobbit::operator=(Hobbit original)
{

	//Multiple assignment
	name = original.name;
	age = original.age;
	descendent = original.descendent;
	antecedent = original.antecedent;
	sibling = original.sibling;
}


bool Hobbit::operator==(Hobbit first)
{
	if (first.age == age && first.name == name)
		return true;

	else
		return false;
}