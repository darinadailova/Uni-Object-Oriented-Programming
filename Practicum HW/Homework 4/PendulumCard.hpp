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
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard {
	unsigned int pendulumScale;

	void setAllPrivateMembers(const PendulumCard& rhs);
public:
	PendulumCard(const std::string& name = "", const std::string& effect = "", unsigned int newRarity = 0, const unsigned int& attackPoints = 0,
		const unsigned int& defencePoints = 0, const CardType& type = CardType::DEFAULT, const unsigned int& scale = 1);
	PendulumCard(const PendulumCard& rhs);
	PendulumCard& operator=(const PendulumCard& rhs);

	void setPendulumScale(const unsigned int& scale);
	unsigned int getPendulumScale() const;

	virtual Card* clone() const override;
};