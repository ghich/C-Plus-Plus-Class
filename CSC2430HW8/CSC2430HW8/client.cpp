//Nate Kaldor
//CSC2430 HW8
//Client implementation
//Practice with lists and overloading

#include <string>
#include "Hobbit.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void printFamilyStick(Hobbit*);
void printRelation(Hobbit *a, Hobbit *b);

int main()
{

	//Create Sam and Gaffer, link them
	Hobbit sam("Samwise Gamgee", 41, NULL, NULL);
	Hobbit gaffer("Gaffer Gamgee", 95, NULL, &sam);
	sam.setAntecedent(&gaffer);

	//Create Elanor, link to Sam and vice versa
	Hobbit *elanor = new Hobbit("Elanor Gamgee", 0, &sam, NULL);
	sam.setDescendent(elanor);
	elanor->setAntecedent(&sam);

	//Test printRelation for all 3 cases
	cout << endl << "===== Testing printRelation on Samwise and Gaffer: =====" << endl;
	printRelation(&sam, &gaffer);
	cout << endl << "===== Testing printRelation on Samwise and Elanor: =====" << endl;
	printRelation(&sam, elanor);
	cout << endl << "===== Testing printRelation on Gaffer and Elanor: =====" << endl;
	printRelation(&gaffer, elanor);

	//Test printFamilyStick on the Gaffer
	cout << endl << "===== Testing printFamilyStick on Gaffer: =====" << endl;
	printFamilyStick(&gaffer);


	return 0;
}

//A funciton to print a family "stick"
//Simply traverses hob's descendents, printing their names
//Parameters: the Hobbit whose family stick we should print (Hobbit *)
//Returns: nothing
void printFamilyStick(Hobbit *hob)
{
	Hobbit *child = hob->getDescendent();
	cout << "The family stick of " << hob->getName() << ": " << endl;

	cout << setw(35) << hob->getName() << " (" << hob->getAge() << ")" << endl;
	while (child != NULL)
	{
		//Using setw for simple formatting
		cout << setw(28) << "|" << endl;
		cout << setw(35) << child->getName() << " (" << child->getAge() << ")" << endl;
		child = child->getDescendent();
	}


}

//A funciton to print the relation status between two Hobbits
//Parameters: the Hobbits we will determine relationship on (Hobbit*)
//Returns: nothing
void printRelation(Hobbit *a, Hobbit *b)
{
	//If first Hobbit is parent of the second
	if (a->isParentOf(b))
		cout << a->getName() << " is a parent of " << b->getName() << endl;

	//If second Hobbit is parent of the first
	else if (b->isParentOf(a))
		cout << b->getName() << " is a parent of " << a->getName() << endl;

	//Otherwise, no relation!
	else
		cout << b->getName() << " is not the parent of " << a->getName() << " and vice versa" << endl;


}
