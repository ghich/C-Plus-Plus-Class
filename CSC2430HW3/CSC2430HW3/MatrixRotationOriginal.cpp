//MatrixRotation.cpp
//This initializes and loads the 2d arrays
//And acts to 'rotate' the tie fighters and x-wings.
#include <iostream>
#include "MatrixRotation.h"
using namespace std;

void initArray(charStarMatrix boxBox, int size)
{
	//For loop to rotate through the rows
	for (int i = 0; i < size; i++)
	{
		//For loop to rotate through the individual inputs in the rows and initialize them to " "
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

void printArray(charStarMatrix original, charStarMatrix transposed, int loopNumber)
{
	for (int printNumber = 0; printNumber < loopNumber; printNumber++)
	{
		for (int i = 0; i < loopNumber; i++)
		{
			for (int j = 0; j < loopNumber; j++)
			{
				cout << original[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		for (int k = 0; k < loopNumber; k++)
		{
			for (int l = 0;l < loopNumber; l++)
			{
				cout << transposed[k][l] << " ";
			}
			cout << endl;
		}
		cout << endl;
		printNumber++;
	}
}




void loadArray(charStarMatrix threeSquare, int size)
{
	for (int i = 0; i < size; i++)
	{
			cout << "Enter the chars for the next row in the matrix (separated by spaces)" << endl;
			cin >> threeSquare[i][0] >> threeSquare[i][1] >> threeSquare[i][2];

			if (threeSquare[i][0] == 'q' && threeSquare[i][1] == 'q' && threeSquare[i][2] == 'q')
			{
				cout << "Ending matrix input" << endl;
				break; //Break the loop
			}

			for (int j = 0; j < size; j++)
			{
				if (threeSquare[i][j] == 'b')
					threeSquare[i][j] = ' ';
			}
			
	}
	

	//Debug loop to test output
	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << threeSquare[i][j] << " ";
		}
		cout << endl;
	}*/
	
}


void transposeArray(const charStarMatrix original, int originalSize, charStarMatrix& transpose)
{
	for (int i = 0; i < originalSize; i++)
	{
		for (int j = 0; j < originalSize; j++)
		{
			//Checking if the input to be transposed is X-Wing or Tie Fighter
			if (original[i][2] == '/')
			{
				//X-Wing attack changed to cruise
				transpose[0][0] = ' ';
				transpose[0][1] = ' ';
				transpose[0][2] = '\0';
				transpose[1][0] = '=';
				transpose[1][1] = '0';
				transpose[1][2] = '=';
				transpose[2][0] = ' ';
				transpose[2][1] = ' ';
				transpose[2][2] = '\0';
			}
			//Otherwise, rotate the Tie Fighter
			else if (original[i][0] == '|')
			{
				transpose[0][0] = '|';
				transpose[0][1] = '|';
				transpose[0][2] = '|';
				transpose[1][0] = ' ';
				transpose[1][1] = '0';
				transpose[1][2] = ' ';
				transpose[2][0] = '|';
				transpose[2][1] = '|';
				transpose[2][2] = '|';
			}
		
		}

	}


}