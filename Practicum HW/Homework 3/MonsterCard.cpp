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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const std::string& newName, const std::string& newEffect, 
	const unsigned int& newAttackPoints, const unsigned int& newDefencePoint) 
	: Card(newName, newEffect), attackPoints(newAttackPoints), defencePoints(newDefencePoint) {
}

MonsterCard::MonsterCard(const MonsterCard& rhs) {
	this->setName(rhs.getName());
	this->setEffect(rhs.getEffect());
	this->attackPoints = rhs.attackPoints;
	this->defencePoints = rhs.defencePoints;
}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs) {
	if (this != &rhs) {
		this->setName(rhs.getName());
		this->setEffect(rhs.getEffect());
		this->attackPoints = rhs.attackPoints;
		this->defencePoints = rhs.defencePoints;
	}
	
	return *this;
}

void MonsterCard::setAttackPoints(const unsigned int& newAttackPoints) { 
	attackPoints = newAttackPoints; 
}

void MonsterCard::setDefencePoints(const unsigned int& newDefencePoints) {
	defencePoints = newDefencePoints; 
}

unsigned int MonsterCard::getAttackPoints() const { 
	return attackPoints; 
}

unsigned int MonsterCard::getDefencePoints() const { 
	return defencePoints; 
}