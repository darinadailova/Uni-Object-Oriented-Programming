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

#include "Deck.hpp"

Deck::Deck(const std::string& newName) : name(newName) {
}

Deck::Deck(const Deck& rhs) {
	this->name = rhs.name;
	this->deckMonsters = rhs.deckMonsters;
	this->deckMagicCards = rhs.deckMagicCards;
	this->deckPendulumCards = rhs.deckPendulumCards;
}

Deck& Deck::operator=(const Deck& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->deckMonsters = rhs.deckMonsters;
		this->deckMagicCards = rhs.deckMagicCards;
		this->deckPendulumCards = rhs.deckPendulumCards;
	}

	return *this;
}

unsigned int Deck::getMonsterCardsCount() const { 
	return deckMonsters.size();
}

unsigned int Deck::getMagicCardsCount() const { 
	return deckMagicCards.size();
}

unsigned int Deck::getPendulumCardsCount() const { 
	return deckPendulumCards.size();
}

std::string Deck::getDeckName() const {
	return name;
}

void Deck::setDeckName(const std::string& newName) {
	name = newName;
}

MonsterCard Deck::getMonsterCard(const int& index) const {
	return deckMonsters[index];
}

MagicCard Deck::getMagicCard(const int& index) const {
	return deckMagicCards[index];
}

PendulumCard Deck::getPendulumCard(const int& index) const {
	return deckPendulumCards[index];
}

void Deck::addMonsterCard(const MonsterCard& card) { 
	deckMonsters.push_back(card);
}

void Deck::addMagicCard(const MagicCard& card) { 
	deckMagicCards.push_back(card); 
}

void Deck::addPendulumCard(const PendulumCard& card) {
	deckPendulumCards.push_back(card);
}

void Deck::setMonster(const unsigned int& index, const MonsterCard& card) {
	deckMonsters[index] = card; 
}

void Deck::setMagicCard(const unsigned int& index, const MagicCard& card) { 
	deckMagicCards[index] = card;
}

void Deck::setPendulumCard(const unsigned int& index, const PendulumCard& card) { 
	deckPendulumCards[index] = card;
}

void Deck::clearDeck() {
	deckMonsters.clear();
	deckMagicCards.clear();
	deckPendulumCards.clear();
}