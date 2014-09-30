#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <valarray>
#include <random>

//------------------------- M a t r i x -------------------------
template <typename T>
class Matrix {
public:
	//Some constructor(s)...
	Matrix(int M, int N) {
		for (int i = 0; i < M; i++) { content.push_back(std::valarray<T>(N)); }
		m_rows = M;
		m_cols = N;
	}

	//Some operators...
	Matrix operator+(const Matrix& rhs) {
		if (this->rows() == rhs.rows() && this->cols() == rhs.cols()) {
			Matrix<T> retMat(rows(), cols());
			for (int i = 0; i < rows(); i++) {
				retMat.content[i] = this->content[i] + rhs.content[i];
			}
			return retMat;
		}
		else { throw Matrix_Dimension_Mismatch(); std::cout << "Could not add... Matrix dimension mismatch!\nError Code: :(" << std::endl; }
	}

	Matrix operator-(const Matrix& rhs) {
		if (this->rows() == rhs.rows() && this->cols() == rhs.cols()) {
			Matrix<T> retMat(rows(), cols());
			for (int i = 0; i < rows(); i++) {
				retMat.content[i] = this->content[i] - rhs.content[i];
			}
			return retMat;
		}
		else { throw Matrix_Dimension_Mismatch(); std::cout << "Could not subtract... Matrix dimension mismatch!\nError Code: :(" << std::endl; }
	}

	Matrix operator*(const Matrix& rhs) {
		if (this->cols() == rhs.rows()) {
			Matrix<T> retMat(this->rows(), rhs.cols());
			for (unsigned int i = 0; i < retMat.rows(); i++) {
				for (unsigned int j = 0; j < retMat.cols(); j++) {
					retMat.content[i][j] = (this->content[i] * rhs.getCol(j)).sum();
				}			
			}
			return retMat;
		}
		else { throw Matrix_Dimension_Mismatch(); std::cout << "Could not multiply... Matrix dimension mismatch!\nError Code: D:" << std::endl; }
	}

	Matrix operator==(const Matrix& rhs) {	//returns a boolean matrix containing ones at indices with equal value
		if (this->rows() == rhs.rows() && this->cols() == rhs.cols()) {
			Matrix<T> retMat(rows(), cols());
			for (unsigned int i = 0; i < rows(); i++) {
				for (unsigned int j = 0; j < cols(); j++) {
					if (this->at(i, j) == rhs.at(i, j)) { retMat.set(i, j, 1); }
					else { retMat.set(i, j, 0); }
				}
			}
			return retMat;
		}
		else { throw Matrix_Dimension_Mismatch(); std::cout << "Could not compare... Matrix dimension mismatch!\nError Code: :/" << std::endl; }
	}


	//Some functions...
	Matrix zero() {	//"zeros out" the matrix
		Matrix<T> retMat(this->rows(), this->cols());
		for (auto matIt : retMat.content) { matIt = std::valarray<T>(T{}, rows()); }
		return retMat;
	}

	void rand(int min, int max) {	//initializes the matrix with random values
		std::mt19937 rand;
		for (unsigned int i = 0; i < rows(); i++) {
			for (unsigned int j = 0; j < cols(); j++) { content[i][j] = min + ((rand() / static_cast<T>(rand.max()) * (max-min))); }
		}
	}

	Matrix id() {	//returns the identity matrix for any given square matrix
		if (this->rows() == this->cols()) {
			Matrix<T> retMat(rows(), cols());
			for (unsigned int i = 0; i < rows(); i++) {
				for (unsigned int j = 0; j < cols(); j++) {
					if (i == j) { retMat.set(i, j, 1); }
					else { retMat.set(i, j, 0); }
				}
			}
			return retMat;
		}
		else { throw Matrix_Not_Square();  std::cout << "Matrix is not square!\nError Code: :O" << std::endl; }
	}

	Matrix trans() {	//returns the transposed matrix
		Matrix<T> retMat(cols(), rows());
		for (unsigned int i = 0; i < retMat.rows(); i++) {
			for (unsigned int j = 0; j < retMat.cols(); j++) {
				retMat.set(i, j, (this->at(j, i)));
			}
		}
		return retMat;
	}

	void print() {	//prints a matrix most trivially...atm...
		for (unsigned int i = 0; i < rows(); i++) {
			for (unsigned int j = 0; j < cols(); j++) {
				std::cout << content[i][j] << "  ";
			}
			std::cout << "\n";
		}
		std::cout << std::endl;
	}

	Matrix addRow(std::valarray<T> newRow) {
		if (newRow.size() == this->cols()) {
			Matrix<T> retMat = this;
			retMat.content.push_back(newRow);
			retMat.m_rows += 1;
		}
	}

	Matrix addCol(std::valarray<T> newCol) {
		//to be done some fine day...
	}

	std::valarray<T> getRow(int i) const {
		if (i < rows()) { return content[i]; }
		else {
			//do some exception(al) handling
		}
	}

	std::valarray<T> getCol(int j) const {
		if (j < cols()) {
			std::valarray<T> retArr(cols());
			for (unsigned int k = 0; k < cols(); k++) {
				retArr[k] = content[j][k];
			}
			return retArr;
		}
		else {
			//also handle this exceptionally
		}
	}

	T at(unsigned int n, unsigned int m) const
	{
		if (n < rows() && m < cols()) { return content[n][m]; }
		else { throw std::out_of_range("out of range"); }
	}

	void set(unsigned int n, unsigned int m, T val) {
		if (n < rows() && m < cols()) { content[n][m] = val; }
		else { throw std::out_of_range("out of range");}
	}

	unsigned int rows() const { return m_rows; }
	unsigned int cols() const { return m_cols; }

private:
	unsigned int m_rows;
	unsigned int m_cols;
	std::vector<std::valarray<T>> content;
};



//----------------- E x c e p t i o n   H a n d l i n g -----------------
//not implemented yet!

struct Matrix_Dimension_Mismatch
{
	Matrix_Dimension_Mismatch(){};
};
struct Matrix_Not_Square
{
	Matrix_Not_Square(){};
};

#endif //MATRIX_H