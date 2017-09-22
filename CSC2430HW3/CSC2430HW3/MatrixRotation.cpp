//MatrixRotation.cpp
//This initializes and loads the 2d arrays
//And acts to 'rotate' the tie fighters and x-wings.
#include <iostream>
#include "MatrixRotation.h"
using namespace std;

void initArray(charStarMatrix boxBox, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			boxBox[i][j]=' ';
			//Debug line
			//cout << boxBox[i][j];
		}
		//Formatting for debug
		//cout << endl;
	}

}

void loadArray(charStarMatrix threeSquare, int size)
{
	cout << "Enter the chars for the first row (separated by spaces)" << endl;
	cin >> threeSquare[0][0] >> threeSquare[0][1] >> threeSquare[0][2];
	for (int i = 0; i < size; i++)
	{
		if (threeSquare[0][i] == 'b')
			threeSquare[0][i] = ' ';

			
			
	}	
	if (threeSquare[0][0] == 'q' || threeSquare[0][1] == 'q' || threeSquare[0][2] == 'q')
	{
		cout << "Quit code recognized...Exiting..." << endl;
		abort;
	}
	cout << endl;
	cout << "Enter the chars for the second row (separated by spaces)" << endl;
	cin >> threeSquare[1][0] >> threeSquare[1][1] >> threeSquare[1][2];
	for (int i = 0; i < size; i++)
	{
		if (threeSquare[1][i] == 'b')
			threeSquare[1][i] = ' ';
		if (threeSquare[1][MAX] == 'q', 'q', 'q')
			exit;
	}
	cout << endl;
	cout << "Enter the chars for the third row (separated by spaces)" << endl;
	cin >> threeSquare[2][0] >> threeSquare[2][1] >> threeSquare[2][2];
	for (int i = 0; i < size; i++)
	{
		if (threeSquare[2][i] == 'b')
			threeSquare[2][i] = ' ';
		if (threeSquare[2][MAX] == 'q', 'q', 'q')
			exit;
	}

	//Debug loop to test output
	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << threeSquare[i][j];
		}
		cout << endl;
	}*/
	
}