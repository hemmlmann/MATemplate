#include <iostream>
#include "matrix.h"

//a little demo <(^_°)>

int main() {
	
	Matrix<int> lolMatrix(4, 3);
	lolMatrix.rand();
	std::cout << "Rows: " << lolMatrix.rows() << " | Columns: " << lolMatrix.cols() << std::endl;
	lolMatrix.print();

	getchar();

	Matrix<int> roflMatrix = lolMatrix.trans();
	std::cout << "Rows: " << roflMatrix.rows() << " | Columns: " << roflMatrix.cols() << std::endl;
	roflMatrix.print();

	getchar();

	return 42;
}