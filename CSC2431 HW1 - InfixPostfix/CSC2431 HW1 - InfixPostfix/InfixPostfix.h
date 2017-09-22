//Nate Kaldor
//CSC2431
//HW1 - 4 20 15
//Infix to Postfix converter

#ifndef _InfixPostfix_
#define _InfixPostfix_

#include <string>
#include <iostream>
#include <iomanip>


using namespace std;


class InfixPostfix
{
public:


	InfixPostfix(string);


	bool getInfix();


	void showInfix();


	void showPostfix();





private:

	
	string infx;


	string pfx;

	//Convert from infix to postfix
	bool convertToPostfix();

	//Determines precedence between two operators
	bool precedence(char op1, char op2);



};
#endif