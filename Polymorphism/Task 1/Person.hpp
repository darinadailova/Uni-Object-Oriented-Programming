#pragma once
#include <vector>
#include "Dog.hpp"

class Person {
	std::vector<Pet*> pets;

	void copyRhs(const Person& rhs);
	void deleteVec();
public:
	Person() = default;
	Person(const Person& rhs);
	Person& operator=(const Person& rhs);
	~Person();

	void adopt(Pet* pet);
	void feedEmALl();
	void petEmAll() const;
	void walkAllDogs();
};