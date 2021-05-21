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
#include <string>

class Card {
	std::string name;
	std::string effect;
public:
	Card(const std::string& newName = "", const std::string& newEffect = "");
	Card(const Card& rhs);
	Card& operator=(const Card& rhs);

	void setName(const std::string& newName);
	void setEffect(const std::string& newEffect);

	std::string getName() const;
	std::string getEffect() const;
};