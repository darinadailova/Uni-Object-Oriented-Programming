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

#include "Money.hpp"

Money::Money() : money(0) {
}

Money::Money(const unsigned int& n) : money(n) {
}

Money::Money(const Money& rhs) {
    this->money = rhs.money;
}

Money& Money::operator=(const Money& rhs) {
    if (this != &rhs) {
        this->money = rhs.money;
    }
    
    return *this;
}

int Money::getGold() const { return money / 100; }

int Money::getSilver() const { return money % 100; }

void Money::setMoney(const unsigned int& n) { money += n; }

int Money::getMoney() const { return money; }

void Money::addSilver(const unsigned int& n) { money += n; }

void Money::addGold(const unsigned int& n) { money += n * 100; }

int Money::getSlots() const { return 0; }

std::ostream& Money::print(std::ostream& out) {
    out << "Gold: " << getGold() << '\n';
    out << "Silver: " << getSilver() << '\n';

    return out;
}
