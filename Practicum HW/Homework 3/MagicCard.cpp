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

#include "MagicCard.hpp"

MagicCard::MagicCard(const std::string& newName, const std::string& newEffect, const CardType& newType) 
	: Card(newName, newEffect), magicCardType(newType) {
}

MagicCard::MagicCard(const MagicCard& rhs) {
	this->setName(rhs.getName());
	this->setEffect(rhs.getEffect());
	this->magicCardType = rhs.magicCardType;
}

MagicCard& MagicCard::operator=(const MagicCard& rhs) {
	if (this != &rhs) {
		this->setName(rhs.getName());
		this->setEffect(rhs.getEffect());
		this->magicCardType = rhs.magicCardType;
	}
	
	return *this;
}

void MagicCard::setMagicCardType(const CardType& newType) { 
	magicCardType = newType; 
}

CardType MagicCard::getMagicCardType() const {
	return magicCardType; 
}