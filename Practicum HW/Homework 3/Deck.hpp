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
#include "PendulumCard.hpp"
#include <vector>

class Deck {
	std::string name;
	std::vector<MonsterCard> deckMonsters;
	std::vector<MagicCard> deckMagicCards;
	std::vector<PendulumCard> deckPendulumCards;
public:
	Deck(const std::string& newName = "");
	Deck(const Deck& rhs);
	Deck& operator=(const Deck& rhs);

	unsigned int getMonsterCardsCount() const;
	unsigned int getMagicCardsCount() const;
	unsigned int getPendulumCardsCount() const;	

	void addMonsterCard(const MonsterCard& card);
	void addMagicCard(const MagicCard& card);
	void addPendulumCard(const PendulumCard& card);

	void setMonster(const unsigned int& index, const MonsterCard& card);
	void setMagicCard(const unsigned int& index, const MagicCard& card);
	void setPendulumCard(const unsigned int& index, const PendulumCard& card);

	void clearDeck();

	std::string getDeckName() const; 
	void setDeckName(const std::string& newName);
	MonsterCard getMonsterCard(const int& index) const;
	MagicCard getMagicCard(const int& index) const;
	PendulumCard getPendulumCard(const int& index) const;
};