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

enum Type { spell, buff, trap};

class MagicCard {
	char name[26];
	char effect[101];
	Type type;
public:
	MagicCard();
	MagicCard(const char name[], const char effect[], Type type);
	MagicCard getMagicCard() const;
	void setMagicCard(MagicCard card);
	void print() const;
};