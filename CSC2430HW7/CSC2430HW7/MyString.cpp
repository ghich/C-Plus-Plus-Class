//Aaron Dingler
//CSC2430
//2-28-15
//Implementation of simple MyString class
// this can form the basis for your HW7
// or you can use your own
#include "MyString.h"
#include <iostream>

MyString::MyString()
{
  length = 0;
  pStr = new char[length];
}


MyString::MyString(const char* s, unsigned int l)
{
  //we'll copy into temporary memory
  char *tmp = new char[l];
  
  //and make pStr point to start of c-string
  // so pStr points to the start of the string throughout
  pStr = tmp;

  //not looking for \0 because we know exact length
  for(unsigned int i = 0; i < (l - 1); i++)
  {
    //copy contents of s to tmp one at a time
    *tmp = *s;
    //increment tmp and s
    tmp++;
    s++;
  }
  //to be safe, will set last character to \0
  // in case a malformed c-string is passed in
  *tmp = '\0';

  //no longer using tmp, good practice to set to NULL
  //note: pStr points to the newly-allocated memory
  tmp = NULL;

  length = l;
}

//Copy Constructor
MyString::MyString(const MyString& original)
{
	deepCopy(original);
}

//Destructor
MyString::~MyString()
{
  delete[] pStr;
}

//ACCESSORS
unsigned int MyString::getLength() const
{ 
  return length;
}

char MyString::getChar(unsigned int position) const
{
	//Initializing variable to return
	char atPosition = 0;

	//pStr always points to the start of the array
	char *temp = pStr;

	//Look through the array for a match
	for (unsigned int i = 0; i <= (position-1); i++)
	{
		
		if (i == (position-1))
			atPosition = *temp;
		temp++;
	}

	return atPosition;
}


//UTILITY
void MyString::outputString() const
{
  //don't want to change pStr pointer!
  //it should always point to start of char array
  char *tmp = pStr;

  while(*tmp != '\0')
  {
    cout << *tmp;
    tmp++;
  }

}

//Here are the functions you created in class
// adapted for use in the MyString class

//Note: this function modifies MyString
void MyString::toUpper()
{
  //don't want to change pStr pointer!
  //it should always point to start of char array
  char *tmp = pStr;

  while(*tmp != '\0')
  {
    *tmp = toupper(*tmp);
    tmp++;
  }
}

//Nobody in class chose this (or nobody e-mailed me their solution)
// so here's an example implementation
// I threw this together fairly quickly, if you find
// an edge case and can break it please let me know!
bool MyString::findStr(const char* key) const
{
  //preserve key as pointer to start of string
  const char *tmpKey = key;

  //don't want to change pStr pointer!
  //it should always point to start of char array
  char *tmp = pStr;

  //find occurence of key's first char in tmp (i.e., pStr)
  while(*tmp != '\0')
  {
    //if we find an occurence of the first character
    // look for the full key starting here (at current tmp)
    char *here = tmp;

    //this loop will continue as long as the characters
    // in the portion of pStr we are looking at match
    // the characters in key
    while(*here == *tmpKey)
    {
      here++;
      tmpKey++;

      //if we get to the end of tmpKey
      // and still in the loop (meaning, all chars
      // were equal up to this point) then we have a match
      if(*tmpKey == '\0')
        return true;
    }

    //otherwise, increment tmp and keep looking
    tmp++;
  }

  return false;

}

unsigned int MyString::countVowels() const
{
  //don't want to change pStr pointer!
  //it should always point to start of char array
  char *tmp = pStr;

  int count = 0;

  while (*tmp != '\0')
  {
    if ((*tmp == 'a') || (*tmp == 'A'))
      count++;
    else if ((*tmp == 'e') || (*tmp == 'E'))
      count++;
    else if ((*tmp == 'i') || (*tmp == 'I'))
      count++;
    else if ((*tmp == 'o') || (*tmp == 'O'))
      count++;
    else if ((*tmp == 'u') || (*tmp == 'U'))
      count++;
    tmp++;
  }

  return count;
}

void MyString::copyToSpace(char* dest) const
{
  //don't want to change pStr pointer!
  //it should always point to start of char array
  char *tmp = pStr;

  //probably not the most efficient,
  // but we already have a function to make sure
  // we have a space, so let's use that :)
  if(findStr(" "))
  {
    while(*tmp != ' ')
    {
      *dest = *tmp;
      tmp++;
      dest++;
    }

  }

  *dest = '\0';
}



void MyString::resize(unsigned int size)
{
	//pStr always point to the start of the string
	char *temp = pStr;
	//Create dynamic array with the appropriate size
	char *resized = new char[size];
	char blank = ' ';
	
	if (size < length)
	{
		copy(resized, temp, size);
		pStr = resized;
	}

	else if (size > length)
	{

		copy(resized, temp, length);
		pStr = resized;

		while (*resized != '\0')
		{
			resized++;
		}

		for (unsigned int j = length; j < (size); j++)
		{
			*resized = ' ';
			resized++;
		}
		*resized = '\0';
	}

	length = size;
	
	resized = NULL;
	temp = NULL;

}


void MyString::addChar(char element, unsigned int position)
{
	char *temp = pStr;

	if (position > length)
	{
		//Make the cstring bigger.
		resize(position);
		//Through debugging, this sets temp to point to the start of pStr again.
		temp = pStr;
		//Rotate through the array. The spot before the null terminating character is the control.
		for (unsigned int i = 0; i < (position - 1); i++)
		{
			//If we hit the spot before the null terminating character, we replace the char.
			if (i == (position - 2))
				*temp = element;
			temp++;
		}

		//Increased the size of the string: Make sure to have a null terminating character.
		*temp = '\0';
	}

	else if (position == length)
	{
		//Length - 1 is the control for the loop because it accounts for the null terminating character
		for (unsigned int i = 0; i < (length - 1); i++)
		{
			//The position is -2, because we account for the null terminating character.
			if (i == (length - 2))
				*temp = element;
			temp++;
		}
		
	}

	else if (position < length && position >= 0)
	{
		//Because position is less than length, we add one to position in the loop to account
		//for the null terminating character
		for (unsigned int i = 0; i < (position); i++)
		{
			if (i == (position - 1))
				*temp = element;
			temp++;
		}

	}

	temp = NULL;
}

//Created this as a constant function for safety
bool MyString::isPalindrome() const
{
	char *tempOne = pStr;
	char *tempTwo = pStr;
	unsigned int counter = 0;
	while (*tempTwo != '\0')
	{
		tempTwo++;
		counter++;
	}

	tempTwo--;

	//While the beginning is less or equal to the end
	while (tempOne <= tempTwo)
	{
		//For loop rotates through the cstring
		for (int i = 0; i < (counter); i++)
		{
			if (*tempOne == *tempTwo || *tempOne == tolower(*tempTwo) || *tempOne == toupper(*tempTwo))
			{
				tempOne++;
				tempTwo--;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}



void MyString::copy(char *one, char* two, unsigned int size)
{
	char *tempOne = one;
	char *tempTwo = two;

	for (unsigned int i = 0; i < (size - 1); i++)
	{
		*tempOne = *tempTwo;
		tempOne++;
		tempTwo++;
	}

	//Check if there's a null terminating character for safety
	if (*tempOne != '\0')
		*tempOne = '\0';

}

void MyString::deepCopy(const MyString& original)
{

	length = original.length;
	pStr = new char[length];
	char *temp = original.pStr;
	char *tempTwo = pStr;

	copy(tempTwo, temp, length);

	temp = NULL;
	tempTwo = NULL;
}

