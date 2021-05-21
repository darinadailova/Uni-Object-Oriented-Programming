/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Darina Dailova
* @idnumber 62583
* @task 1
* @compiler VC
*/

#include "Card.hpp"

Card::Card(const std::string& newName, const std::string& newEffect) : name(newName), effect(newEffect) {
}

Card::Card(const Card& rhs) {
	this->name = rhs.name;
	this->effect = rhs.effect;
}

Card& Card::operator=(const Card& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->effect = rhs.effect;
	}
	
	return *this;
}

void Card::setName(const std::string& newName) { 
	name = newName;
}

void Card::setEffect(const std::string& newEffect) { 
	effect = newEffect;
}

std::string Card::getName() const { 
	return name; 
}

std::string Card::getEffect() const {
	return effect; 
}
