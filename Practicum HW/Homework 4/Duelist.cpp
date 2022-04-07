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

#include "Duelist.hpp"

Duelist::Duelist(const std::string& newName) : name(newName) {
}

Duelist::Duelist(const std::string& newName, const Deck& newDeck) : name(newName), deck(newDeck) {
}

Duelist::Duelist(const Duelist& rhs) {
	this->name = rhs.name;
	this->deck = rhs.deck;
}

Duelist& Duelist::operator=(const Duelist& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->deck = rhs.deck;
	}

	return *this;
}

Deck& Duelist::getDeck() {
	return deck;
}

bool Duelist::saveDeck(const std::string& fileName) const {
	std::ofstream outFile(fileName, std::ios::out);
	if (!outFile.is_open()) return false;

	outFile << deck.getDeckName() << '|' << deck.getCardsCount() << '|' << deck.getMonsterCardsCount() << '|';
	outFile	<< deck.getMagicCardsCount() << '|' << deck.getPendulumCardsCount() << '\n';
	outFile << deck;

	return true;
}

bool Duelist::loadDeck(const std::string& fileName) {
	std::ifstream inFile(fileName);
	if (!inFile.is_open()) return false;

	deck.clearDeck();
	
	std::string line;
	std::getline(inFile, line);
	int find = line.find('|');
	deck.setDeckName(line.substr(0, find));

	inFile >> deck;

	return true;
}

void Duelist::duel(const Duelist& otherPlayer) const {
	if (deck.getCardsCount() != otherPlayer.deck.getCardsCount()) {
		std::cout << "The duel couldn't take place :(\n";
	}
	
	size_t pointsForPlayer1 = 0, pointsForPlayer2 = 0;
	for (unsigned int i = 0; i < deck.getCardsCount(); i++) {
		if (deck.cards[i]->getRarity() == otherPlayer.deck.cards[i]->getRarity()) {
			continue;
		}

		if (deck.cards[i]->operator<(*otherPlayer.deck.cards[i])) {
			pointsForPlayer2++;
		} 
		else {
			pointsForPlayer1++;
		}
	}

	if (pointsForPlayer1 == pointsForPlayer2) {
		std::cout << "Tie\n";
	}
	else if (pointsForPlayer1 > pointsForPlayer2) {
		std::cout << "Congratulations you win!\n";
	}
	else {
		std::cout << "Better luck next time\n";
	}
}

void Duelist::setDuelistName(const std::string& newName) {
	name = newName;
}

std::string Duelist::getDuelistName() const {
	return name;
}