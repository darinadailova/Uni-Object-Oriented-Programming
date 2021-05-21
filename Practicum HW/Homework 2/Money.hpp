/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Darina Dailova
* @idnumber 62583
* @task 1
* @compiler VC
*/

#pragma once
#include <iostream>

class Money {
	unsigned int money;
public:
	Money();
	Money(const unsigned int& n);
	Money(const Money& rhs);
	Money& operator=(const Money& rhs);
	int getGold() const;
	int getSilver() const;
	int getMoney() const;
	void addSilver(const unsigned int& n);
	void addGold(const unsigned int& n);
	void setMoney(const unsigned int& n);
	int getSlots() const;
	std::ostream& print(std::ostream& out);
};