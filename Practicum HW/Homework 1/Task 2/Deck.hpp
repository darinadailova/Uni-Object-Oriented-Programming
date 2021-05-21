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

#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class Deck {
	MonsterCard monsterCards[20];
	MagicCard magicCards[20];
	int monsterCardsCount;
	int magicCardsCount;
	// If the value is 1 - there is a card at that index. If the value is 0 - there isn't a card at that index
	int magicCardsArray[20] = { 0 }; // to keep track of the magic cards
	int monsterCardsArray[20] = { 0 };// to keep track of the monster cards
public:
	Deck();
	int getCountOfMagicCards() const;
	int getCountOfMonsterCards() const;
	MonsterCard getMonsterCard(int index) const;
	MagicCard getMagicCard(int index) const;
	void addMagicCard();
	void addMonsterCard();
	void changeMagicCard(int index, MagicCard card);
	void changeMonsterCard(int index, MonsterCard card);
	// Prints all cards in the deck
	void print() const;
};