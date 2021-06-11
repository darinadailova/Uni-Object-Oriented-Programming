#pragma once
#include <iostream>

template <typename T>

class Matrix {
	const int DEFAULT_ROWS = 2;
	const int  DEFAULT_COLUMS = 2;
	
	unsigned int rows;
	unsigned int colums;
	T** matrix;
	
public:
	Matrix();
	Matrix(const unsigned int& rows, const unsigned int& colums);
	Matrix(const Matrix& rhs);
	Matrix& operator=(const Matrix& rhs);
	~Matrix();

	void setAt(unsigned int x, unsigned int y, T element);
	T getAt(unsigned int x, unsigned int y);
	void transpose();

	void deleteMatrix();
	void createMatrix(const unsigned int& rows, const unsigned int& colums);
	void printMatrix() const;
};

template<typename T>
Matrix<T>::Matrix() {
	this->rows = DEFAULT_ROWS;
	this->colums = DEFAULT_COLUMS;
	this->createMatrix(DEFAULT_ROWS, DEFAULT_COLUMS);
}

template<typename T>
Matrix<T>::Matrix(const unsigned int& rows, const unsigned int& colums) {
	this->rows = rows;
	this->colums = colums;
	this->createMatrix(rows, colums);
}

template<typename T>
Matrix<T>::Matrix(const Matrix& rhs) {
	this->rows = rhs.rows;
	this->colums = rhs.colums;
	this->createMatrix(this->rows, this->colums);
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < colums; j++) {
			this->matrix[i][j] = rhs.matrix[i][j];
		}
	}
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& rhs) {
	if (this != &rhs) {
		this->deleteMatrix();
		this->rows = rhs.rows;
		this->colums = rhs.colums;
		this->createMatrix(this->rows, this->colums);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < colums; j++) {
				this->matrix[i][j] = rhs.matrix[i][j];
			}
		}
	}
}

template<typename T>
Matrix<T>::~Matrix() {
	this->deleteMatrix();
}

template<typename T>
void Matrix<T>::setAt(unsigned int x, unsigned int y, T element) {
	this->matrix[x - 1][y - 1] = element;
}

template<typename T>
T Matrix<T>::getAt(unsigned int x, unsigned int y) {
	return this->matrix[x - 1][y - 1];
}

template<typename T>
void Matrix<T>::transpose() {
	Matrix temp(*this);
	this->deleteMatrix();
	this->rows = temp.colums;
	this->colums = temp.rows;
	this->createMatrix(this->rows, this->colums);
	for (unsigned int i = 0; i < this->rows; i++) {
		for (unsigned int j = 0; j < this->colums; j++) {
			this->matrix[i][j] = temp.getAt(j + 1, i + 1);
		}
	}
}

template<typename T>
void Matrix<T>::deleteMatrix() {
	for (unsigned int i = 0; i < this->rows; i++) {
		delete[] this->matrix[i];
	}

	delete[] this->matrix;
}

template<typename T>
void Matrix<T>::createMatrix(const unsigned int& rows, const unsigned int& colums) {
	this->matrix = new int* [rows];
	for (unsigned int i = 0; i < rows; i++) {
		this->matrix[i] = new int[colums];
	}

	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < colums; j++) {
			this->matrix[i][j] = 0;
		}
	}
}

template<typename T>
void Matrix<T>::printMatrix() const {
	for (unsigned int i = 0; i < this->rows; i++) {
		for (unsigned int j = 0; j < this->colums; j++) {
			std::cout << this->matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}