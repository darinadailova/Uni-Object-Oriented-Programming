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

#include "Duelist.hpp"
#include <iostream>

Duelist::Duelist() : name(nullptr) {
}

Duelist::Duelist(const char name[]) {
	this->name = name;
}

void Duelist::addMonsterInDeck() {
	deck.addMonsterCard();
}

void Duelist::addMagiccardInDeck() {
	deck.addMagicCard();
}

void Duelist::changeMonsterCardInDeck(int index, MonsterCard card) {
	deck.changeMonsterCard(index, card);
}

void Duelist::changeMagicCardInDeck(int index, MagicCard card) {
	deck.changeMagicCard(index, card);
}

void Duelist::countOfMonsters() const { deck.getCountOfMagicCards(); }

void Duelist::countOfMagicCards() const { deck.getCountOfMonsterCards(); }

void Duelist::print() const {
	deck.print();
}
