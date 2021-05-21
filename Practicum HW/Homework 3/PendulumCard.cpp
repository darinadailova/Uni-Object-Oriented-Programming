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

#include "PendulumCard.hpp"

PendulumCard::PendulumCard(const std::string& name, const std::string& effect, const unsigned int& attackPoints, 
	const unsigned int& defencePoints, const CardType& type, const unsigned int& scale) 
	: Card(name, effect), MonsterCard(name, effect, attackPoints, defencePoints), MagicCard(name, effect, type), pendulumScale(scale) {
}

PendulumCard::PendulumCard(const PendulumCard& rhs) {
	this->setName(rhs.getName());
	this->setEffect(rhs.getEffect());
	this->setAttackPoints(rhs.getAttackPoints());
	this->setDefencePoints(rhs.getDefencePoints());
	this->setMagicCardType(rhs.getMagicCardType());
	this->pendulumScale = rhs.pendulumScale;
}

PendulumCard& PendulumCard::operator=(const PendulumCard& rhs) {
	if (this != &rhs) {
		this->setName(rhs.getName());
		this->setEffect(rhs.getEffect());
		this->setAttackPoints(rhs.getAttackPoints());
		this->setDefencePoints(rhs.getDefencePoints());
		this->setMagicCardType(rhs.getMagicCardType());
		this->pendulumScale = rhs.pendulumScale;
	}

	return *this;
	
}

void PendulumCard::setPendulumScale(const unsigned int& scale) {
	pendulumScale = scale;
}

unsigned int PendulumCard::getPendulumScale() const { 
	return pendulumScale;
}