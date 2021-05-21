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
#include "Weapon.hpp"
#include "Armor.hpp"
#include <vector>
#include <string>

template<class U>
U findMax(U a, U b);

template <class T>
class Equipment {
	std::vector<T>equipment;
	int slots;
public:
	Equipment();
	Equipment(const Equipment& rhs);
	Equipment& operator=(const Equipment & rhs);

	bool isEquipmentEmpty();
	bool isEquipmentFull();
	void eraseEquipment();
	void addElement(const T& newElement);
	void removeElement(const int& index);
	T bestEquipment();
	int getSlots() const;
	double calculateGearScore() const;
	double calculateWeaponScore() const;
	std::ostream& print(std::ostream& out);

	bool operator==(const Equipment& rhs);
	bool operator!=(const Equipment& rhs);
};

template<class T>
Equipment<T>::Equipment() : slots(0) {
}

template<class T>
Equipment<T>::Equipment(const Equipment& rhs) {
	this->slots = rhs.slots;
	this->equipment = rhs.equipment;
}

template<class T>
Equipment<T>& Equipment<T>::operator=(const Equipment& rhs) {
	if (this != &rhs) {
		this->slots = rhs.slots;
		this->equipment = rhs.equipment;
	}

	return *this;
}

template<class T>
inline bool Equipment<T>::isEquipmentEmpty() {
	if (slots == 0) return true;
	return false;
}

template<class T>
bool Equipment<T>::isEquipmentFull() {
	if (slots == 24) return true;
	return false;
}

template<class T>
void Equipment<T>::eraseEquipment() {
	slots = 0;
	equipment.clear();
}

template<class T>
void Equipment<T>::addElement(const T& newElement) {
	equipment.push_back(newElement);
	slots += newElement.getSlots();
}

template<class T>
void Equipment<T>::removeElement(const int& index) {
	slots -= equipment[index].getSlots();
	equipment.erase(equipment.begin() + index);
}

template<>
Weapon Equipment<Weapon>::bestEquipment() {
	int size = equipment.size();
	double max = -1;
	for (int i = 0; i < size; i++) {
		max = findMax(max, equipment[i].getWeaponScore());
	}

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (max == equipment[i].getWeaponScore()) {
			index = i;
			break;
		}
	}

	return equipment[index];
}

template<class T>
int Equipment<T>::getSlots() const { return slots; }

template<>
Armor Equipment<Armor>::bestEquipment() {
	int size = equipment.size();
	double max = -1;
	for (int i = 0; i < size; i++) {
		max = findMax(max, equipment[i].getGearscore());
	}

	int index = -1;
	for (int i = 0; i < size; i++) {
		if (max == equipment[i].getGearscore()) {
			index = i;
			break;
		}
	}

	return equipment[index];
}

template<>
double Equipment<Weapon>::calculateWeaponScore() const {
	double weaponScore = 0;
	int size = equipment.size();
	for (int i = 0; i < size; i++) {
		weaponScore += equipment[i].getWeaponScore();
	}

	return weaponScore;
}

template<class T>
std::ostream& Equipment<T>::print(std::ostream& out) {
	out << "SLots " << slots << '\n';
	for (int i = 0; i < equipment.size(); i++) {
		equipment[i].print(out);
	}

	return out;
}

template<>
double Equipment<Armor>::calculateGearScore() const {
	double gearScore = 0;
	int size = equipment.size();
	for (int i = 0; i < size; i++) {
		gearScore += equipment[i].getGearscore();
	}

	return gearScore;
}

template<>
bool Equipment<Weapon>::operator==(const Equipment& rhs) {
	if (this->calculateWeaponScore() == rhs.calculateWeaponScore()) return true;
	return false;
}

template<>
bool Equipment<Armor>::operator==(const Equipment& rhs) {
	if (this->calculateGearScore() == rhs.calculateGearScore()) return true;
	return false;
}

template<>
bool Equipment<Weapon>::operator!=(const Equipment& rhs) {
	if (this->calculateWeaponScore() != rhs.calculateWeaponScore()) return true;
	return false;
}

template<>
bool Equipment<Armor>::operator!=(const Equipment& rhs) {
	if (this->calculateGearScore() != rhs.calculateGearScore()) return true;
	return false;
}

template<class U>
U findMax(U a, U b) {
	if (a > b) return a;
	return b;
}