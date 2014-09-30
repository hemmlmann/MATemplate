#include <iostream>
#include "matrix.h"

//a little demo <(^_°)>

int main() {
	
	Matrix<float> lolMatrix(4, 3);
	Matrix<float> lolMatrix2(3, 3);
	lolMatrix.rand(0.0,1.0);
	lolMatrix2.rand(0.0, 1.0);
	std::cout << "Rows: " << lolMatrix.rows() << " | Columns: " << lolMatrix.cols() << std::endl;
	lolMatrix.print();

	Matrix<float> lolMatrix3 = lolMatrix*lolMatrix2;
	lolMatrix3.print();

	getchar();

	Matrix<float> roflMatrix = lolMatrix.trans();
	std::cout << "Rows: " << roflMatrix.rows() << " | Columns: " << roflMatrix.cols() << std::endl;
	roflMatrix.zero().print();
	roflMatrix.print();

	getchar();

	return 42;
}