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

class MonsterCard {
	char name[26];
	int attackPoints;
	int defencePoints;
public:
	MonsterCard();
	MonsterCard(const char name[], int attackPoints, int defencePoints);
	MonsterCard getMonster() const;
	void setMonster(MonsterCard newCard);
	void print() const;
};