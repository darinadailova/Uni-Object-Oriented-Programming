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

#include "Card.hpp"

Card::Card(const std::string& newName, const std::string& newEffect, unsigned int newRarity)
    : name(newName), effect(newEffect), rarity(newRarity) {
}

Card::Card(const Card& rhs) {
    this->name = rhs.name;
    this->effect = rhs.effect;
    this->rarity = rhs.rarity;
}

Card& Card::operator=(const Card& rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->effect = rhs.effect;
        this->rarity = rhs.rarity;
    }

    return *this;
}

void Card::setName(const std::string& newName) {
    name = newName;
}

void Card::setEffect(const std::string& newEffect) {
    effect = newEffect;
}

void Card::setRarity(unsigned int newRarity) {
    rarity = newRarity;
}


std::string Card::getName() const {
    return name;
}

std::string Card::getEffect() const {
    return effect;
}

unsigned int Card::getRarity() const {
    return rarity;
}

bool Card::operator>(const Card& rhs) const {
    return rarity > rhs.rarity;
}

bool Card::operator<(const Card& rhs) const {
    return rarity < rhs.rarity;
}

Card::~Card() {
}