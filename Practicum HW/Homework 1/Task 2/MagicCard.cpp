/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Darina Dailova
* @idnumber 62583
* @task 2
* @compiler VC
*/

#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "Functions.hpp"
#include <iostream>

MagicCard::MagicCard() : name(""), effect(""), type(spell) {
}

MagicCard::MagicCard(const char name[], const char effect[], Type type) {
	stringcpy(this->name, name);
	stringcpy(this->effect, effect);
	this->type = type;
}

MagicCard MagicCard::getMagicCard() const
{
	return MagicCard(name, effect, type);
}

void MagicCard::setMagicCard(MagicCard card) {
	stringcpy(name, card.name);
	stringcpy(effect, card.effect);
	type = card.type;
}

void MagicCard::print() const {
	std::cout << "Magic card\n";
	std::cout << "Name: " << name << '\n';
	std::cout << "Effect: " << effect << '\n';
	std::cout << "Type: ";
	if (type == 0) { std::cout << "spell"; }
	else if (type == 1) { std::cout << "buff"; }
	else { std::cout << "trap"; }
	std::cout << '\n';
}
