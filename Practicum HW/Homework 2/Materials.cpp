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

#include "Materials.hpp"

Materials::Materials() : herbsCount(0), oresCount(0), clothCount(0), essenceCount(0) {
}

Materials::Materials(const Materials& rhs) {
	this->herbsCount = rhs.herbsCount;
	this->oresCount = rhs.oresCount;
	this->clothCount = rhs.clothCount;
	this->essenceCount = rhs.essenceCount;
}

Materials& Materials::operator=(const Materials& rhs) {
	if (this != &rhs) {
		this->herbsCount = rhs.herbsCount;
		this->oresCount = rhs.oresCount;
		this->clothCount = rhs.clothCount;
		this->essenceCount = rhs.essenceCount;
	}
	
	return *this;
}

int Materials::getSlots() const {
	int slots = 0;
	slots += essenceCount / 10 + (essenceCount % 10 == 0 ? 0 : 1);
	slots += herbsCount / 20 + (herbsCount % 20 == 0 ? 0 : 1);
	slots += oresCount / 20 + (oresCount % 20 == 0 ? 0 : 1);
	slots += clothCount / 20 + (clothCount % 20 == 0 ? 0 : 1);

	return slots;
}

int Materials::getHerbsCount() const { return herbsCount; }

int Materials::getOresCount() const { return oresCount; }

int Materials::getClothCount() const { return clothCount; }

int Materials::getEssenceCount() const { return essenceCount; }

void Materials::setHerbsCount(const int& n) {
	if (n < 0 && std::abs(n) > herbsCount) {
		herbsCount = 0;
		return;
	}

	herbsCount += n;
}

void Materials::setOresCount(const int& n) {
	if (n < 0 && std::abs(n) > oresCount) {
		oresCount = 0;
		return;
	}

	oresCount += n;
}

void Materials::setClothCount(const int& n) {
	if (n < 0 && std::abs(n) > clothCount) {
		clothCount = 0;
		return;
	}

	clothCount += n;
}

void Materials::setEssenceCount(const int& n) { // -20  10
	if (n < 0 && std::abs(n) > essenceCount) {
		essenceCount = 0;
		return;
	}

	essenceCount += n;
}

std::ostream& Materials::print(std::ostream& out) {
	out << "Herbs: " << herbsCount << '\n';
	out << "Ores: " << oresCount << '\n';
	out << "Cloth: " << clothCount << '\n';
	out << "Essence: " << essenceCount << '\n';

	return out;
}
