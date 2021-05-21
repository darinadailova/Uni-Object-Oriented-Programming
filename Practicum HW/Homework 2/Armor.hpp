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
#include <vector>
#include <string>
#include <iostream>

enum class TypeArmor {
	cloth, 
	leather, 
	mail
};

class Armor {
	TypeArmor type;
	int defence;
	std::vector<std::pair<std::string, double>>effects;
	int armorDefence[3]; // array of the defence point of armors

	// thse methods are private because we don't want the player to change
	void initializeArmorDefence();
	void setDefence();
public:
	// constructors
	Armor();
	Armor(const TypeArmor& newType);
	Armor(const Armor& rhs);
	Armor& operator=(const Armor& rhs);

	// getters
	TypeArmor getType() const;
	double getGearscore() const;
	int getSlots() const;
	int getDefence() const;

	// setters
	void setArmor(const TypeArmor& newType);

	void addEffect(const std::string& name, const double& power);
	void removeEffect(const std::string& name);
	void changeEffectPower(const std::string& name, const double& newPower);
	std::ostream& print(std::ostream& out);
};

