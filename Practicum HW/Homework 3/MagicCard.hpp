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

#pragma once
#include "Card.hpp"

enum class CardType {
	TRAP,
	BUFF,
	SPELL,
	DEFAULT
};

class MagicCard : virtual public Card {
	CardType magicCardType;
public:
	MagicCard(const std::string& newName = "", const std::string& newEffect = "", const CardType& newType = CardType::DEFAULT);
	MagicCard(const MagicCard& rhs);
	MagicCard& operator=(const MagicCard& rhs);

	void setMagicCardType(const CardType& newType);
	CardType getMagicCardType() const;
};