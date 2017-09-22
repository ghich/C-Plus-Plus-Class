//MatrixRotation - Rotates the tie fighter/x-wing in 2d array
#ifndef MATRIX_ROTATION
#define MATRIX_ROTATION

//Global constants for the matrices
const int MAX = 3;

typedef char charStarMatrix[MAX][MAX];

void initArray(charStarMatrix, int);

void loadArray(charStarMatrix, int);

void rotateArray(charStarMatrix, int);


#endif