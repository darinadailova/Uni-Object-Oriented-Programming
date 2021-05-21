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

#include "Deck.hpp"
#include <iostream>

Deck::Deck() : monsterCardsCount(0), magicCardsCount(0) {
}

int Deck::getCountOfMagicCards() const { return magicCardsCount; }

int Deck::getCountOfMonsterCards() const { return monsterCardsCount; }

MonsterCard Deck::getMonsterCard(int index) const { return monsterCards[index]; }

MagicCard Deck::getMagicCard(int index) const { return magicCards[index]; }

void Deck::addMagicCard() {
	bool flag = false;
	for (int i = 0; i < 20; i++) {
		if (magicCardsArray[i] == 0) {
			magicCards[i] = MagicCard();
			magicCardsCount++;
			flag = true;
			magicCardsArray[i] = 1;
			break;
		}
	}

	if (!flag) {
		std::cout << "The deck is full\n";
	}
}

void Deck::addMonsterCard() {
	bool flag = false;
	for (int i = 0; i < 20; i++) {
		if (monsterCardsArray[i] == 0) {
			monsterCards[i] = MonsterCard();
			monsterCardsCount++;
			flag = true;
			monsterCardsArray[i] = 1;
			break;
		}
	}

	if (!flag) {
		std::cout << "The deck is full\n";
	}
}

void Deck::changeMagicCard(int index, MagicCard card) {
	magicCardsArray[index] = 1;
	magicCards[index] = card;
	magicCardsCount++;
}

void Deck::changeMonsterCard(int index, MonsterCard card) {
	monsterCardsArray[index] = 1;
	monsterCards[index] = card;
	monsterCardsCount++;
}


void Deck::print() const {
	std::cout << "MONSTER CARDS\n";
	for (int i = 0; i < 20; i++) {
		monsterCards[i].print();
	}
	
	std::cout << "\nMAGIC CARDS\n";
	for (int i = 0; i < 20; i++) {
		magicCards[i].print();
	}
}
