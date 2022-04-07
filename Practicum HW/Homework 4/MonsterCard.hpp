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

#pragma once
#include "Card.hpp"

class MonsterCard : virtual public Card {
	unsigned int attackPoints;
	unsigned int defencePoints;

	void setAllPrivateMembers(const MonsterCard& rhs);

public:
	MonsterCard(const std::string& newName = "", const std::string& newEffect = "", unsigned int newRarity = 0,
		const unsigned int& newAttackPoints = 0, const unsigned int& newDefencePoint = 0);
	MonsterCard(const MonsterCard& rhs);
	MonsterCard& operator=(const MonsterCard& rhs);

	void setAttackPoints(const unsigned int& newAttackPoints);
	void setDefencePoints(const unsigned int& newDefencePoints);

	unsigned int getAttackPoints() const;
	unsigned int getDefencePoints() const;

	virtual Card* clone() const override;
};