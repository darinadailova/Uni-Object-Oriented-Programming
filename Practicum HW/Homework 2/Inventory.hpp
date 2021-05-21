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
#include "Equipment.hpp"
#include "Backpack.hpp"
#include <vector>
#include <iostream>
// Inventory<Equipment<Armor>>
// Inventory<Backpack<Money>>
// Inventory<Backpack<Materials>>

// Inventory<Equipment<Weapon>>

template<class T>
class Inventory {
	std::vector<T>inventory;
	int slots;
public:
	Inventory();
	Inventory(const Inventory& rhs);
	Inventory& operator=(const Inventory& rhs);

	int getSlots() const;
	void addElement(const T& newElement);
	void removeElement(const int& index);

	bool operator==(const Inventory& rhs);
	bool operator!=(const Inventory& rhs);
	friend std::ostream& operator<<(std::ostream& out, Inventory<T> n) {
		int size = n.inventory.size();
		for (int i = 0; i < size; i++) {
			n.inventory[i].print(out);
		}

		return out;
	}
};

template<class T>
Inventory<T>::Inventory() : slots(0) {
}

template<class T>
Inventory<T>::Inventory(const Inventory& rhs) {
	this->inventory = rhs.inventory;
	this->slots = rhs.slots;
}

template<class T>
Inventory<T>& Inventory<T>::operator=(const Inventory& rhs) {
	if (this != &rhs) {
		this->inventory = rhs.inventory;
		this->slots = rhs.slots;
	}

	return *this;
}

template<class T>
int Inventory<T>::getSlots() const { return slots; }

template<class T>
bool Inventory<T>::operator==(const Inventory& rhs) {
	if (this->getSlots() == rhs.getSlots()) return true;
	return false;
}

template<class T>
bool Inventory<T>::operator!=(const Inventory& rhs) {
	if (operator==(rhs)) return false;
	return true;
}

template<class T>
void Inventory<T>::addElement(const T& newElement) {
	slots += newElement.getSlots();
	inventory.push_back(newElement);
}

template<class T>
void Inventory<T>::removeElement(const int& index) {
	if (index >= inventory.size()) {
		std::cout << "Invalid index\n";
	}
	slots -= inventory[index].getSlots();
	inventory.erase(inventory.begin() + index);
}
