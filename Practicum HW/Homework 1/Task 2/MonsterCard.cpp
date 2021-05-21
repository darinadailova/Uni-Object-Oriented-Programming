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

#include "MonsterCard.hpp"
#include "Functions.hpp"
#include <iostream>

MonsterCard::MonsterCard() : name(""), attackPoints(0), defencePoints(0) {
}

MonsterCard::MonsterCard(const char name[], int attackPoints, int defencePoints) {
    stringcpy(this->name, name);
    this->attackPoints = attackPoints;
    this->defencePoints = defencePoints;
}

MonsterCard MonsterCard::getMonster() const {
    return MonsterCard(name, attackPoints, defencePoints);
}

void MonsterCard::setMonster(MonsterCard newCard) {
    stringcpy(name, newCard.name);
    attackPoints = newCard.attackPoints;
    defencePoints = newCard.defencePoints;
}

void MonsterCard::print() const {
    std::cout << "Monster card\n";
    std::cout << "Name: " << name << '\n';
    std::cout << "Attack points: " << attackPoints << '\n';
    std::cout << "Defence points: " << defencePoints << '\n';
}