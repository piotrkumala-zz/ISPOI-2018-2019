#pragma once
#include<iostream>
void printMatrices(int matrixData1[] , int matrixData2[] , int matrixData3[] ){
	CleverMatrix matrix1(matrixData1, 3);
	CleverMatrix matrix2(matrixData2, 3);
	const CleverMatrix matrix3(matrixData3, 2);
	matrix1.print();
	matrix2.print();
	matrix3.print();
}

void createSymmetricMatrices(int matrixData1[] , int matrixData2[] , int matrixData3[] ){
	std::string type = "nonsymmetric";
	CleverMatrix matrix1(matrixData1, 3, type);
	type = "symmetric";
	CleverMatrix matrix2(matrixData2, 3, type);
	CleverMatrix matrix3(matrixData3, 2, type);
}

void accessMatrix(int matrixData1[] , int matrixData2[] , int matrixData3[] ){
	CleverMatrix matrix1(matrixData1, 3);
	CleverMatrix matrix2(matrixData3, 2);

	int row=1;
	int col=2;
	matrix1(row,col) = 2;
	matrix2(row,col) = 3; 
}

void multiplyMatrices(int matrixData1[] , int matrixData2[] , int matrixData3[] ){
	
    CleverMatrix matrix1(matrixData1, 3);
	CleverMatrix matrix2(matrixData2, 3);
	const CleverMatrix matrix3(matrixData3, 2);

	CleverMatrix prod1 =  matrix1 * matrix2;
	prod1.print();
	CleverMatrix prod2 =  matrix1 * matrix3;
	prod2.print();
    
}