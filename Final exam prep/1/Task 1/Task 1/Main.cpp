#include <iostream>
#include "Matrix.hpp"

int main() {
	Matrix<int> test1(2, 2);
	test1.setAt(1, 1, 5);
	test1.setAt(1, 2, 3);
	test1.setAt(2, 1, 4);
	test1.setAt(2, 2, 1);
	test1.printMatrix();
	/*
	(5,3)
	(4,1)
	*/
	test1.transpose();
	test1.printMatrix();
	/*
	(5,4)
	(3,1)
	*/
	std::cout << test1.getAt(1, 2); //4

	return 0;
}