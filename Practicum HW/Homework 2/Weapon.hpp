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
#include <string>
#include <utility>
#include <vector>
#include <iostream>

enum class HandleType {
	oneHanded, // 1h
	twoHanded // 2h
};

enum class WeaponType {
	axe, // 1h/2h
	sword, // 1h/2h
	dagger, // 1h
	mace, // 1h/2h
	staff // 2h
};

class Weapon {
	HandleType handletype;
	WeaponType weaponType;
	std::pair<unsigned int, unsigned int>hitDamage;
	std::vector<std::pair<std::string, double>>effects;
	std::pair<HandleType, WeaponType> weaponInventory[8]; // array of all possible weapons
	std::pair<unsigned int, unsigned int>hitDamageOfWeapons[8]; // array of hit damages of all weapons
	const int NUMBER_OF_WEAPONS = 8;

	// these methods are private because we don't want the player to change them
	void initializeWeaponInventory();
	void initializehitDamageOfWeapons();
	void setHitDamage();
public:
	// constructors
	Weapon();
	Weapon(const HandleType& newHandleType, const WeaponType& newWeaponType);
	Weapon(const Weapon& rhs);
	Weapon& operator=(const Weapon& rhs);

	// getters
	int getSlots() const;
	double getWeaponScore() const;
	HandleType getHandleType() const;
	WeaponType getWeaponType() const;

	// setters
	void setWeaponType(const WeaponType& newType);
	void setHandleType(const HandleType& newType);

	void addEffect(std::string newName, double newPower);
	void removeEffect(std::string name);
	void changePower(std::string name, double newPower);
	std::ostream& print(std::ostream& out);
};