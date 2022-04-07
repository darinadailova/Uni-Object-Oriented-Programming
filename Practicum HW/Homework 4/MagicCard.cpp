/**
* Solution to homework assignment 4
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

void MagicCard::setAllPrivateMembers(const MagicCard& rhs) {
	this->setName(rhs.getName());
	this->setEffect(rhs.getEffect());
	this->setRarity(rhs.getRarity());
	this->magicCardType = rhs.magicCardType;
}

MagicCard::MagicCard(const std::string& newName, const std::string& newEffect, unsigned int newRarity, const CardType& newType)
	: Card(newName, newEffect, newRarity), magicCardType(newType) {
}

MagicCard::MagicCard(const MagicCard& rhs) {
	setAllPrivateMembers(rhs);
}

MagicCard& MagicCard::operator=(const MagicCard& rhs) {
	if (this != &rhs) {
		setAllPrivateMembers(rhs);
	}

	return *this;
}

void MagicCard::setMagicCardType(const CardType& newType) {
	magicCardType = newType;
}

CardType MagicCard::getMagicCardType() const {
	return magicCardType;
}

Card* MagicCard::clone() const {
	return new MagicCard(*this);
}