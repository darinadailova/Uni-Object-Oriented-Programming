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
#include "PendulumCard.hpp"
#include <vector>
#include <algorithm>
#include <random>

class Deck {
	std::string name;
	std::vector<Card*> cards;
public:
	Deck(const std::string& newName = "");
	Deck(const Deck& rhs);
	Deck& operator=(const Deck& rhs);
	~Deck();

	unsigned int getMonsterCardsCount() const;
	unsigned int getMagicCardsCount() const;
	unsigned int getPendulumCardsCount() const;
	unsigned int getCardsCount() const;

	void addCard(Card* newCard);
	void changeCard(size_t index, Card* newCard);
	void clearDeck();
	void shuffle();

	std::string getDeckName() const;
	void setDeckName(const std::string& newName);

	std::string findCardType(Card* card) const;

	friend std::ostream& operator<<(std::ostream& out, const Deck& obj);
	friend std::istream& operator>>(std::istream& in, Deck& obj);
	friend class Duelist;
};