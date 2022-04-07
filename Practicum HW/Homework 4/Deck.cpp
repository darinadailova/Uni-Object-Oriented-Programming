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

#include "Deck.hpp"

Deck::Deck(const std::string& newName) : name(newName) {
}

Deck::Deck(const Deck& rhs) {
	this->name = rhs.name;
	for (auto card : rhs.cards) {
		this->cards.push_back(card->clone());
	}
}

Deck& Deck::operator=(const Deck& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		for (auto x : this->cards) {
			delete x;
		}

		this->cards.clear();

		for (auto card : rhs.cards) {
			this->cards.push_back(card->clone());
		}
	}

	return *this;
}

Deck::~Deck() {
	for (auto x : this->cards) {
		delete x;
	}
}

unsigned int Deck::getMonsterCardsCount() const {
	unsigned int count = 0;

	for (auto card : cards) {
		MonsterCard* monster = dynamic_cast<MonsterCard*>(card);
		PendulumCard* card2 = dynamic_cast<PendulumCard*>(card);
		if (monster && !card2) {
			count++;
		}
	}

	return count;
}

unsigned int Deck::getMagicCardsCount() const {
	unsigned int count = 0;

	for (auto card : cards) {
		MagicCard* cardPtr = dynamic_cast<MagicCard*>(card);
		PendulumCard* card3 = dynamic_cast<PendulumCard*>(card);
		if (cardPtr && !card3) {
			count++;
		}
	}

	return count;	
}

unsigned int Deck::getPendulumCardsCount() const {
	return (getCardsCount() - (getMagicCardsCount() + getMonsterCardsCount()));
}

unsigned int Deck::getCardsCount() const {
	return cards.size();
}

void Deck::addCard(Card* newCard) {
	cards.push_back(newCard->clone());
}

void Deck::changeCard(size_t index, Card* newCard) {
	if (findCardType(newCard) == findCardType(cards[index])) {
		delete cards[index];
		cards[index] = newCard->clone();
	}
	else {
		std::cout << "Card types doesn't match\n";
	}
}

void Deck::Deck::clearDeck() {
	for (auto card : cards) {
		delete card;
	}

	cards.clear();
}

void Deck::shuffle() {
	unsigned int seed = 0;
	std::default_random_engine eng;
	std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

std::string Deck::getDeckName() const {
	return name;
}

void Deck::setDeckName(const std::string& newName) {
	name = newName;
}

std::string Deck::findCardType(Card* card) const {
	PendulumCard* card3 = dynamic_cast<PendulumCard*>(card);
	if (card3) {
		return "PendulumCard";
	}

	MonsterCard* card1 = dynamic_cast<MonsterCard*>(card);
	if (card1) {
		return "Monster Card";
	}

	MagicCard* card2 = dynamic_cast<MagicCard*>(card);
	if (card2) {
		return "Magic card";
	}
}

std::ostream& operator<<(std::ostream& out, const Deck& obj) {
	for (auto x : obj.cards) {
		PendulumCard* card1 = dynamic_cast<PendulumCard*>(x);
		MonsterCard* card2 = dynamic_cast<MonsterCard*>(x);
		if (card2 && !card1) {
			out << card2->getName() << '|' << card2->getEffect() << '|' << card2->getRarity() << '|';
			out << card2->getAttackPoints() << '|' << card2->getDefencePoints() << '\n';
		}
	}

	for (auto y : obj.cards) {
		PendulumCard* card3 = dynamic_cast<PendulumCard*>(y);
		MagicCard* card4 = dynamic_cast<MagicCard*>(y);
		if (card4 && !card3) {
			out << card4->getName() << '|' << card4->getEffect() << '|' << card4->getRarity() << '|';

			if (card4->getMagicCardType() == CardType::BUFF) out << "BUFF";
			else if (card4->getMagicCardType() == CardType::SPELL) out << "SPELL";
			else if (card4->getMagicCardType() == CardType::TRAP) out << "TRAP";
			else out << "DEFAULT";
			out << '\n';
		}
	}

	for (auto z : obj.cards) {
		PendulumCard* card5 = dynamic_cast<PendulumCard*>(z);
		if (card5) {
			out << card5->getName() << '|' << card5->getEffect() << '|' << card5->getRarity() << '|';
			out << card5->getAttackPoints() << '|' << card5->getDefencePoints() << '|';
			out << card5->getPendulumScale() << '|';
			if (card5->getMagicCardType() == CardType::BUFF) out << "BUFF";
			else if (card5->getMagicCardType() == CardType::SPELL) out << "SPELL";
			else if (card5->getMagicCardType() == CardType::TRAP) out << "TRAP";
			else out << "DEFAULT";
			out << '\n';
		}
	}

	return out;
}

std::istream& operator>>(std::istream& in, Deck& obj) {
	obj.clearDeck();
	std::string line;
	for (int i = 0; std::getline(in, line); i++) {
		size_t count = std::count(line.begin(), line.end(), '|');
		int find = 0;
		std::string line2;

		if (count == 4) {
			MonsterCard card;
			find = line.find('|');
			card.setName(line.substr(0, find));

			line2 = line.substr(find + 1, line.size());
			find = line2.find('|');
			card.setEffect(line2.substr(0, find));

			line = line2.substr(find + 1, line2.size());
			find = line.find('|');
			card.setRarity(std::stoi(line.substr(0, find)));

			line2 = line.substr(find + 1, line.size());
			find = line2.find('|');
			card.setAttackPoints(std::stoi(line2.substr(0, find)));

			line = line2.substr(find + 1, line2.size());
			find = line.find('|');
			card.setDefencePoints(std::stoi(line.substr(0, find)));

			obj.addCard(&card);
			continue;
		}

		if (count == 3) {
			MagicCard card2;
			find = line.find('|');
			card2.setName(line.substr(0, find));

			std::string line2 = line.substr(find + 1, line.size());
			find = line2.find('|');
			card2.setEffect(line2.substr(0, find));

			line = line2.substr(find + 1, line2.size());
			find = line.find('|');
			card2.setRarity(std::stoi(line.substr(0, find)));

			line2 = line.substr(find + 1, line.size());
			if (line2 == "TRAP") card2.setMagicCardType(CardType::TRAP);
			else if (line2 == "SPELL") card2.setMagicCardType(CardType::SPELL);
			else if (line2 == "BUFF") card2.setMagicCardType(CardType::BUFF);
			else card2.setMagicCardType(CardType::DEFAULT);

			obj.addCard(&card2);
			continue;
		}

		if (count == 6) {
			PendulumCard card3;
			find = line.find('|');
			card3.setName(line.substr(0, find));

			line2 = line.substr(find + 1, line.size());
			find = line2.find('|');
			card3.setEffect(line2.substr(0, find));

			line = line2.substr(find + 1, line2.size());
			find = line.find('|');
			card3.setRarity(std::stoi(line.substr(0, find)));

			line2 = line.substr(find + 1, line.size());
			find = line2.find('|');
			card3.setAttackPoints(std::stoi(line2.substr(0, find)));

			line = line2.substr(find + 1, line2.size());
			find = line.find('|');
			card3.setDefencePoints(std::stoi(line.substr(0, find)));

			line2 = line.substr(find + 1, line.size());
			find = line2.find('|');
			card3.setPendulumScale(std::stoi(line2.substr(0, find)));

			line = line2.substr(find + 1, line2.size());
			if (line == "TRAP") card3.setMagicCardType(CardType::TRAP);
			else if (line == "SPELL") card3.setMagicCardType(CardType::SPELL);
			else if (line == "BUFF") card3.setMagicCardType(CardType::BUFF);
			else card3.setMagicCardType(CardType::DEFAULT);

			obj.addCard(&card3);
			continue;
		}

	}

	return in;
}