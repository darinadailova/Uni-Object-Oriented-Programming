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

#include "Armor.hpp"

void Armor::initializeArmorDefence() {
	// initialize an array that contains defence point of armors
	armorDefence[0] = 50; // for cloth armor
	armorDefence[1] = 80; // for leather armor
	armorDefence[2] = 30; // for mail armor
}

Armor::Armor() {
	// in the beginning of the game the player gets mail armor with 30 points defence
	// later on he can change it
	initializeArmorDefence();
	type = TypeArmor::mail;
	setDefence();
}

Armor::Armor(const TypeArmor& newType) {
	initializeArmorDefence();
	type = newType;
	setDefence();
}

Armor::Armor(const Armor& rhs) {
	initializeArmorDefence();
	this->type = rhs.type;
	this->defence = rhs.defence;
	this->effects = rhs.effects;
}

Armor& Armor::operator=(const Armor& rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		this->defence = rhs.defence;
		this->effects = rhs.effects;
	}

	return *this;
}

TypeArmor Armor::getType() const { return type; }

double Armor::getGearscore() const {
	double gearscore = 0;
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		gearscore += effects[i].second;
	}

	return gearscore;
}

int Armor::getSlots() const { return 1; }

void Armor::addEffect(const std::string& name, const double& power) {
	if (power < 0) {
		std::cout << "The power can be only positive numeber!\n";
		return;
	}

	int size = effects.size();
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (name == effects[i].first) {
			effects[i].second = power;
			flag = true;
			break;
		}
	}

	if (!flag) {
		effects.push_back(std::make_pair(name, power));
	}
}

void Armor::removeEffect(const std::string& name) {
	int size = effects.size();
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (effects[i].first == name) {
			index = i;
			break;
		}
	}

	if (index != -1) effects.erase(effects.begin() + index);
}

int Armor::getDefence() const { return defence; }

void Armor::setArmor(const TypeArmor& newType) {
	type = newType;
	// when the player changes armor, the defence points change too
	setDefence();
}

void Armor::changeEffectPower(const std::string& name, const double& power) {
	if (power < 0) {
		std::cout << "The power can be only positive numeber!\n";
		return;
	}

	int size = effects.size();
	for (int i = 0; i < size; i++) {
		if (effects[i].first == name) {
			effects[i].second = power;
			return;
		}
	}

	std::cout << "Effect not found\n";
}

void Armor::setDefence() {
	if (type == TypeArmor::cloth) defence = armorDefence[0];
	else if (type == TypeArmor::leather) defence = armorDefence[1];
	else defence = armorDefence[2];
}

std::ostream& Armor::print(std::ostream& out) {
	out << "Armor type: ";
	if (type == TypeArmor::cloth) out << "cloth\n";
	else if (type == TypeArmor::leather) out << "leather\n";
	else out << "mail\n";
	out << "defence: " << defence << '\n';
	out << "Effects: \n";
	for (int i = 0; i < effects.size(); i++) {
		out << "name: " << effects[i].first << '\n' << "power: " << effects[i].second << '\n';
	}
	out << '\n';

	return out;
}