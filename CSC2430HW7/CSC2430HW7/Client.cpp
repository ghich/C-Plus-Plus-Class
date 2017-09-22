//Aaron Dingler
//CSC2430
//2-28-15
//Client to test Hobbit class
// this can form the basis for your HW7
// or you can use your implementation

#include "Hobbit.h"
#include "MyString.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printFamilyStick(Hobbit*, unsigned short);
void printRelation(Hobbit *a, Hobbit *b);
void printState(Hobbit*);

int main()
{
  MyString samwise("Samwise Gamgee", 15);
  MyString gaff("Gaffer Gamgee", 14);
  MyString test = gaff;
  unsigned short currentYear = 2015;
 
  //MyString test = gaff;
  //test.outputString();

  //Hobbit tmp;
  //tmp.setName(gaff);


  //Create Sam and Gaffer, link them
  Hobbit sam(samwise, 1380, NULL, NULL);
  Hobbit gaffer(gaff, 1326, NULL, &sam);
  sam.setAntecedent(&gaffer);

  MyString temp = sam.getName();
  temp.outputString();
  cout << endl;
  
  //Create Elanor, link to Sam and vice versa
  MyString elan("Elanor Gamgee", 14);
  Hobbit elanor = Hobbit(elan, 1421, &sam, NULL);
  sam.setDescendent(&elanor);
  elanor.setAntecedent(&sam);

  MyString eeg("Eegmag Gamgee", 14);
  Hobbit eegmag = Hobbit(eeg, 1461, NULL, NULL);

  //Test printRelation for all 3 cases
  cout << endl << "===== Testing printRelation on Samwise and Gaffer: =====" << endl;
  printRelation(&sam, &gaffer);
  cout << endl << "===== Testing printRelation on Samwise and Elanor: =====" << endl;
  printRelation(&sam, &elanor);
  cout << endl << "===== Testing printRelation on Gaffer and Elanor: =====" << endl;
  printRelation(&gaffer, &elanor);

  //Test printFamilyStick on the Gaffer
  cout << endl << "===== Testing printFamilyStick on Gaffer: =====" << endl;
  printFamilyStick(&gaffer, currentYear);

  MyString kayak("KayAk", 6);
  cout << boolalpha;
  cout << kayak.isPalindrome() << endl;

  return 0;
}

//A funciton to print a family "stick"
//Simply traverses hob's descendents, printing their names
//Parameters: the Hobbit whose family stick we should print (Hobbit *)
//Returns: nothing
void printFamilyStick(Hobbit *hob, unsigned short currentYear)
{
	Hobbit *tempHob = hob;
	Hobbit *child = tempHob->getDescendent();

	cout << "The family stick of ";
	tempHob->getName().toUpper();
	tempHob->getName().outputString();
	cout << ": " << endl;

	cout << setw(35);
	tempHob->getName().outputString();
	cout << " (Born: " << tempHob->getBirthYear() << " Age:" << tempHob->calculateAge(currentYear) << ")" << endl;

	while (child != NULL)
	{
		//Using setw for simple formatting
		cout << setw(28) << "|" << endl;
		cout << setw(35);
		child->getName().outputString();
		cout << " (Born: " << child->getBirthYear() << " Age:" << tempHob->calculateAge(currentYear) << ")" << endl;
		child = child->getDescendent();
	}


}

//A funciton to print the relation status between two Hobbits
//Parameters: the Hobbits we will determine relationship on (Hobbit*)
//Returns: nothing
void printRelation(Hobbit *a, Hobbit *b)
{
	MyString temp = a->getName();
	MyString tempTwo = b->getName();

	//If first Hobbit is parent of the second
	if (a->isParentOf(b))
	{
		temp.outputString();
		cout << " is a parent of ";
		tempTwo.outputString();
		cout << endl;
	}
	//If second Hobbit is parent of the first
	else if (b->isParentOf(a))
	{
		temp.outputString();
		cout << " is a parent of ";
		tempTwo.outputString();
		cout << endl;
	}

	else if (temp.findStr("Gamgee") == true && tempTwo.findStr("Gamgee") == true)
	{
		temp.outputString();
		cout << " is related to ";
		tempTwo.outputString();
		cout << " but not directly" << endl;
	}

	//Otherwise, no relation!
	else
	{
		temp.outputString();
		cout << " is not the parent of ";
		temp.outputString();
		cout << " and vice versa" << endl;
	}

}


void printStats(Hobbit *hob)
{
	Hobbit *child = hob->getDescendent();
	Hobbit *parent = hob->getAntecedent();

	cout << "The number of vowels in: ";
	MyString temp = hob->getName();
	cout << " is: ";
	cout << temp.countVowels() << endl;

	if (child != NULL)
	{
		cout << "The number of vowels in: ";
		child->getName().outputString();
		cout << " is: ";
		cout << child->getName().countVowels() << endl;
	}

	if (parent != NULL)
	{

		cout << "The number of vowels in: ";
		parent->getName().outputString();
		cout << " is: ";
		cout << parent->getName().countVowels() << endl;
	}
}