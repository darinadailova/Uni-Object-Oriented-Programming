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
#include "Deck.hpp"
#include <fstream>
#include <iostream>

class Duelist {
	std::string name;
	Deck deck;
public:
	Duelist(const std::string& newName = "");
	Duelist(const std::string& newName, const Deck& newDeck);
	Duelist(const Duelist& rhs);
	Duelist& operator=(const Duelist& rhs);

	Deck& getDeck();
	bool saveDeck(const std::string& fileName) const;
	bool loadDeck(const std::string& fileName);
	void duel(const Duelist& otherPlayer) const;

	void setDuelistName(const std::string& newName);
	std::string getDuelistName() const;
};