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
#include <string>
#include <iostream>

class Card {
	std::string name;
	std::string effect;
	unsigned int rarity;
public:
	Card(const std::string& newName = "", const std::string& newEffect = "", unsigned int newRarity = 0);
	Card(const Card& rhs);
	Card& operator=(const Card& rhs);

	void setName(const std::string& newName);
	void setEffect(const std::string& newEffect);
	void setRarity(unsigned int newRarity);

	std::string getName() const;
	std::string getEffect() const;
	unsigned int getRarity() const;

	bool operator>(const Card& rhs) const;
	bool operator<(const Card& rhs) const;

	virtual Card* clone() const = 0;
	virtual ~Card() = 0;
};