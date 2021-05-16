#include "Person.hpp"

void Person::copyRhs(const Person& rhs) {
	for (Pet* pet : rhs.pets) {
		this->pets.push_back(pet->copy());
	}
}

void Person::deleteVec() {
	for (Pet* pet : pets) {
		delete pet;
	}
}

Person::Person(const Person& rhs) {
	copyRhs(rhs);
}

Person& Person::operator=(const Person& rhs) {
	if (this != &rhs) {
		deleteVec();
		copyRhs(rhs);
	}
	
	return *this;
}

Person::~Person() {
	deleteVec();
}

void Person::adopt(Pet* pet) {
	pets.push_back(pet->copy());
}

void Person::feedEmALl() {
	for (Pet* pet : pets) {
		pet->feed();
	}
}

void Person::petEmAll() const {
	for (Pet* pet : pets) {
		pet->pet();
	}
}

void Person::walkAllDogs() {
	for (Pet* pet : pets) {
		Dog* dog = dynamic_cast<Dog*>(pet);
		if (dog) {
			dog->walk();
		}
	}
}