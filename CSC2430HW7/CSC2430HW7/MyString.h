//Aaron Dingler
//CSC2430
//2-28-15
//Interface for simple MyString class
// this can form the basis for your HW7
// or you can use your own

#ifndef _MYSTRING_
#define _MYSTRING_

#include <iostream>
#include <cstdlib>

using namespace std;

class MyString
{
  public:

    //Default constructor creates an empty
    //c-string and sets length to 0
    MyString();

    //Default constructor creates a string based on parameters
    //Parameters: const char* to copy chars from, length of string (unsigned int)
    MyString(const char*, unsigned int);

	//Copy Constructor - copies all private data members into a new MyString
	//Takes another MyString as a parameter, using const for safety.
	MyString(const MyString&);

    //Destructor
    ~MyString();

    //ACCESSORS

    //Accessor to return length of the string
    //Parameters: none
    //Returns: the length of the string (an unsigned int)
    unsigned int getLength() const;





	char getChar(unsigned int) const;

    //UTILITY

    //Utility function to output the string element by element
    //Parameters: none:
    //Returns: nothing
    //Effects: prints the C-string to the screen
    void outputString() const;

    //Here are the functions you created in class
    // adapted for use in the MyString class

    //Converts this MyString object to upper-case letters
    void toUpper();

    //Finds occurence of parameter this MyString object
    //Parameters: the C-string to search for (const char*)
    //Returns: true if found, false otherwise
    bool findStr(const char*) const;

    //Count # of vowels in this MyString object
    //Parameters: none
    //Returns: the # of vowels in this MyString object (unsigned int)
    // Note: we aren't counting Y or y
    unsigned int countVowels() const;

    //Copy string up to the first occurence of a space into parameter
    //(this is a generic version of the "first name" function you developed)
    //Parameters: char* to store substring
    //Returns: nothing
    //Effects: the char* passed in will contain the characters from this MyString object
    // up to the first space (if \0 reached before space is found, will copy nothing!)
    void copyToSpace(char*) const;



	void resize(unsigned int);




	void addChar(char, unsigned int);

	bool isPalindrome() const;

  private:
    //A character array
    char *pStr;

    //Length of character array
    unsigned int length;



	void copy(char*, char*, unsigned int);



	void deepCopy(const MyString&);
};

#endif
