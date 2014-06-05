#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template<typename T>
class Matrix {
public:

	Matrix() : M{ 0 }, N{ 0 }, items{ 0 };

	Matrix operator+(const Matrix& op2Mat) {
		if (this->rows() == op2Mat.rows() && this->cols() == op2Mat.cols()) {
			Matrix<T> retMat;	//create return matrix
			for (int i = 0; i < N*M; i++) {
				retMat.items.push_back(this->items.at(i) += op2Mat.items.at(i));
			}
			return retMat;
		}
		else {
			std::cout << "Could not add... Matrix dimension mismatch!\nError Code: :(" << std::endl;
		}
	}
	Matrix operator-(const Matrix& op2Mat) {
		if (this->rows() == op2Mat.rows() && this->cols() == op2Mat.cols()) {
			Matrix<T> retMat;
			for (int i = 0; i < N*M; i++) {
				retMat.items.push_back(this->items.at(i) -= op2Mat.items.at(i));
			}
			return retMat;
		}
		else {
			std::cout << "Could not subtract... Matrix dimension mismatch!\nError Code: :/" << std::endl;
		}
	}
	Matrix operator*(const Matrix& op2Mat){
		if (this->cols() == op2Mat.rows()) {
			Matrix<T> retMat;
			for (int i = 0; i < N*M; i++) {
				retMat.items.push_back([&]{for (int k = 0; k < this->cols(); k++){ this->at(i*cols() + k)*(op2Mat.at(i + k*op2Mat.cols()) }}));
			}
		}
		else {
			std::cout << "Could not multpily... Matrix dimension mismatch!\nError Code: D:" << std::endl;
		}
	}

	//returns a boolean matrix. contains ones at indices with equal value
	Matrix operator==(const Matrix& op2Mat){

	}

	void trans() {

	}

	void inv() {

	}

	void const display(){

	}
	T const at(int i){ return items.at(i); }

	void setRows(int rows) { M = rows; }
	void setCols(int cols) { N = cols; }

	int const rows(){ return M; }
	int const cols(){ return N; }

private:
	int M; //# of rows
	int N; //# of cols
	std::vector<T> items;
};

#endif //MATRIX_H