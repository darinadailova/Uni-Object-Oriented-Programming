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

#include "Weapon.hpp"

Weapon::Weapon() {
	// in the beginning of the game the player gets a dagger with min hit damage 5 and max hit damage 15
	// later on he can change the weapon
	initializeWeaponInventory();
	initializehitDamageOfWeapons();
	handletype = weaponInventory[4].first;
	weaponType = weaponInventory[4].second;
	hitDamage = hitDamageOfWeapons[4];
}

Weapon::Weapon(const HandleType& newHandleType, const WeaponType& newWeaponType) {
	initializehitDamageOfWeapons();
	initializeWeaponInventory();
	weaponType = newWeaponType;
	if (newWeaponType == WeaponType::dagger) handletype = HandleType::oneHanded;
	else if (newWeaponType == WeaponType::staff) handletype = HandleType::twoHanded;
	else handletype = newHandleType;

	setHitDamage();
}

Weapon::Weapon(const Weapon& rhs) {
	initializehitDamageOfWeapons();
	initializeWeaponInventory();
	this->handletype = rhs.handletype;
	this->weaponType = rhs.weaponType;
	this->hitDamage = rhs.hitDamage;
	this->effects = rhs.effects;
}

Weapon& Weapon::operator=(const Weapon& rhs) {
	if (this != &rhs) {
		this->handletype = rhs.handletype;
		this->weaponType = rhs.weaponType;
		this->hitDamage = rhs.hitDamage;
		this->effects = rhs.effects;
	}
	
	return *this;
}

int Weapon::getSlots() const {
	if (handletype == HandleType::oneHanded) return 1;
	return 2;
}

double Weapon::getWeaponScore() const {
	double WeaponScore = 0;
	WeaponScore = (double)(hitDamage.first + hitDamage.second) / 2;
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		WeaponScore += effects[i].second;
	}

	if (handletype == HandleType::oneHanded) {
		WeaponScore *= 0.75;
	}
	else {
		WeaponScore *= 1.5;
	}

	return WeaponScore;
}

HandleType Weapon::getHandleType() const { return handletype; }

WeaponType Weapon::getWeaponType() const { return weaponType; }

void Weapon::setWeaponType(const WeaponType& newType) {
	weaponType = newType;
	if (newType == WeaponType::staff) {
		handletype = HandleType::twoHanded;
		hitDamage = hitDamageOfWeapons[7];
		return;
	}
	// if the weapon can be used with 1h and 2h, by default we will set it as 1h
	// later on the player can change that
	handletype = HandleType::oneHanded;
	// we have to chnage the hit damage too
	setHitDamage();
}

void Weapon::setHandleType(const HandleType& newType) {
	if (weaponType == WeaponType::dagger || weaponType == WeaponType::staff) {
		std::cout << "You can't change the handle type of this weapon!\n";
		return;
	}

	handletype = newType;
	// when we change the handle type, the hit damage changes too
	setHitDamage();
}

void Weapon::setHitDamage() {
	int index = -1;
	for (int i = 0; i < NUMBER_OF_WEAPONS; i++) {
		if (handletype == weaponInventory[i].first && weaponType == weaponInventory[i].second) {
			index = i;
		}
	}

	if (index == -1) {
		std::cout << "À weapon with such parameters does not exist and we cannot set the hit damage!\n";
	}
	else {
		hitDamage = hitDamageOfWeapons[index];
	}
}

void Weapon::addEffect(std::string newName, double newPower) {
	if (newPower < 0) {
		std::cout << "The power can only be positive number!\n";
		return;
	}

	int size = effects.size();
	bool flag = false;
	for (int i = 0; i < size; i++) {
		if (effects[i].first == newName) {
			effects[i].second = newPower;
			flag = true;
			break;
		}
	}

	if (!flag) {
		effects.push_back(std::make_pair(newName, newPower));
	}
}

void Weapon::removeEffect(std::string name) {
	int index = -1;
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		if (effects[i].first == name) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		effects.erase(effects.begin() + index);
	}
	else {
		std::cout << "Effect not found\n";
	}
}

void Weapon::changePower(std::string name, double newPower) {
	if (newPower < 0) {
		std::cout << "The power can only be positive number!\n"; 
		return;
	}

	bool flag = false;
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		if (effects[i].first == name) {
			effects[i].second = newPower;
			flag = true;
			break;
		}
	}
	
	if (!flag) std::cout << "This effect doesn't exist\n";
}

std::ostream& Weapon::print(std::ostream& out) {
	out << "Weapon\nHandle type: ";
	if (handletype == HandleType::oneHanded) out << "one handed\n";
	else out << "two handed\n";

	out << "Weapon type: ";
	if (weaponType == WeaponType::axe) out << "axe\n";
	else if (weaponType == WeaponType::dagger) out << "dagger\n";
	else if (weaponType == WeaponType::mace) out << "mace\n";
	else if (weaponType == WeaponType::staff) out << "staff\n";
	else out << "sword\n";
	out << "hit damage:\n" << "min: " << hitDamage.first << '\n' << "max: " << hitDamage.second << '\n';
	out << "Efects:\n";
	for (int i = 0; i < effects.size(); i++) {
		out << "Name: " << effects[i].first << " power: " << effects[i].second << '\n';
	}
	out << '\n';

	return out;
}

void Weapon::initializeWeaponInventory() {
	weaponInventory[0] = std::make_pair(HandleType::oneHanded, WeaponType::axe);
	weaponInventory[1] = std::make_pair(HandleType::twoHanded, WeaponType::axe);
	weaponInventory[2] = std::make_pair(HandleType::oneHanded, WeaponType::sword);
	weaponInventory[3] = std::make_pair(HandleType::twoHanded, WeaponType::sword);
	weaponInventory[4] = std::make_pair(HandleType::oneHanded, WeaponType::dagger);
	weaponInventory[5] = std::make_pair(HandleType::oneHanded, WeaponType::mace);
	weaponInventory[6] = std::make_pair(HandleType::twoHanded, WeaponType::mace);
	weaponInventory[7] = std::make_pair(HandleType::twoHanded, WeaponType::staff);
}

void Weapon::initializehitDamageOfWeapons() {
	hitDamageOfWeapons[0] = std::make_pair(10, 20);
	hitDamageOfWeapons[1] = std::make_pair(15, 30);
	hitDamageOfWeapons[2] = std::make_pair(40, 80);
	hitDamageOfWeapons[3] = std::make_pair(60, 100);
	hitDamageOfWeapons[4] = std::make_pair(5, 15);
	hitDamageOfWeapons[5] = std::make_pair(100, 120);
	hitDamageOfWeapons[6] = std::make_pair(120, 160);
	hitDamageOfWeapons[7] = std::make_pair(200, 250);
}