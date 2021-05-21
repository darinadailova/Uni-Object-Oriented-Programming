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
#include "Deck.hpp"

class Duelist {
	const char* name;
	Deck deck;
public:
	Duelist();
	Duelist(const char name[]);
	void addMonsterInDeck();
	void addMagiccardInDeck();
	void changeMonsterCardInDeck(int index, MonsterCard card);
	void changeMagicCardInDeck(int index, MagicCard card);
	void countOfMonsters() const;
	void countOfMagicCards() const;
	void print() const;
};