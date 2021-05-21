/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Darina Dailova
* @idnumber 62583
* @task 1
* @compiler VC
*/

#pragma once
#include "Money.hpp"
#include "Materials.hpp"
#include <vector>

template <class T>
class Backpack {
	std::vector<T>backpack;
	int slots;
public:
	Backpack();
	bool isEmpty();
	bool isFull();
	void clearBackpack();
	void addElement(T newElement);
	int getSlots() const;
	void removeElement(const unsigned int& index);
	std::ostream& print(std::ostream& out);
};

template<class T>
Backpack<T>::Backpack() : slots(0) {
}

template<>
bool Backpack<Money>::isEmpty() {
	int size = backpack.size();
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (backpack[i].getSilver() != 0 || backpack[i].getGold() != 0) {
			flag = true;
			break;
		}
	}

	if (flag) return false;
	return true;
}

template<>
bool Backpack<Materials>::isEmpty() {
	if (slots == 0) return true;
	return false;
}

template<>
bool Backpack<Money>::isFull() {
	return false;
}

template<>
bool Backpack<Materials>::isFull() {
	if (slots == 16) return true;
	return false;
}

template<class T>
void Backpack<T>::clearBackpack() {
	slots = 0;
	backpack.clear();
}

template<class T>
int Backpack<T>::getSlots() const { return slots; }

template<class T>
void Backpack<T>::removeElement(const unsigned int& index) {
	backpack.erase(backpack.begin() + index);
}

template<>
void Backpack<Money>::addElement(Money newElement) {
	backpack.push_back(newElement);
}

template<>
void Backpack<Materials>::addElement(Materials newElement) {
	slots += newElement.getSlots();
	backpack.push_back(newElement);
}

template<class T>
std::ostream& Backpack<T>::print(std::ostream& out) {
	out << "Slots: " << slots << '\n';
	for (int i = 0; i < backpack.size(); i++) {
		backpack[i].print(out);
	}

	return out;
}