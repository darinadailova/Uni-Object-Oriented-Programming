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

	outFile << deck.getDeckName() << '|' << deck.getMonsterCardsCount() << '|' << deck.getMagicCardsCount() << '|' << deck.getPendulumCardsCount() << '\n';
	
	for (unsigned int i = 0; i < deck.getMonsterCardsCount(); i++) {
		MonsterCard temp = deck.getMonsterCard(i);
		outFile << temp.getName() << '|' << temp.getEffect() << '|' << temp.getAttackPoints() << '|' << temp.getDefencePoints() << '\n';
	}

	for (unsigned int i = 0; i < deck.getMagicCardsCount(); i++) {
		MagicCard temp2 = deck.getMagicCard(i);
		outFile << temp2.getName() << '|' << temp2.getEffect() << '|';

		CardType type = temp2.getMagicCardType();
		if (type == CardType::BUFF) outFile << "BUFF";
		else if (type == CardType::SPELL) outFile << "SPELL";
		else if (type == CardType::TRAP) outFile << "TRAP";
		else outFile << "DEFAULT";
		outFile << '\n';
	}

	for (unsigned int i = 0; i < deck.getPendulumCardsCount(); i++) {
		PendulumCard temp3 = deck.getPendulumCard(i);
		outFile << temp3.getName() << '|' << temp3.getEffect() << '|' << temp3.getAttackPoints() << '|' << temp3.getDefencePoints();
		outFile << '|' << temp3.getPendulumScale() << '|';

		CardType type = temp3.getMagicCardType();
		if (type == CardType::BUFF) outFile << "BUFF";
		else if (type == CardType::SPELL) outFile << "SPELL";
		else if (type == CardType::TRAP) outFile << "TRAP";
		else outFile << "DEFAULT";
		outFile << '\n';
	}

	outFile.close();
	return true;
}

bool Duelist::loadDeck(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile.is_open()) return false;

	deck.clearDeck();
	std::string line;
	int monsterCount = 0, magicCardCount = 0, pendulumCardCount = 0;
	for (int i = 1; std::getline(inFile, line);) {
		int find1 = -1, find2 = -1;
		std::string lineSubstring, lineSubstring2;

		if (i == 1) {
			find1 = line.find('|');
			deck.setDeckName(line.substr(0, find1));

			lineSubstring = line.substr(find1 + 1, line.size() - 1);
			find2 = lineSubstring.find('|');
			lineSubstring2 = lineSubstring.substr(0, find2);
			monsterCount = std::stoi(lineSubstring2);

			lineSubstring2 = lineSubstring.substr(find2 + 1, lineSubstring.size() - 1);
			find1 = lineSubstring2.find('|');
			lineSubstring = lineSubstring2.substr(0, find1);
			magicCardCount = std::stoi(lineSubstring);

			lineSubstring = lineSubstring2.substr(find1 + 1, lineSubstring2.size() - 1);
			pendulumCardCount = std::stoi(lineSubstring);
			i++;
			continue;
		}
		
		bool flag = false;
		while (i <= monsterCount + 1) {
			MonsterCard monster;
			find1 = line.find('|');
			monster.setName(line.substr(0, find1));

			lineSubstring = line.substr(find1 + 1, line.size() - 1);
			find2 = lineSubstring.find('|');
			monster.setEffect(lineSubstring.substr(0, find2));

			lineSubstring2 = lineSubstring.substr(find2 + 1, lineSubstring.size() - 1);
			find1 = lineSubstring2.find('|');
			lineSubstring = lineSubstring2.substr(0, find1);
			monster.setAttackPoints(std::stoi(lineSubstring));

			lineSubstring = lineSubstring2.substr(find1 + 1, lineSubstring2.size() - 1);
			monster.setDefencePoints(std::stoi(lineSubstring));

			deck.addMonsterCard(monster);
			i++;
			flag = true;
			break;
		}

		if (flag) continue;

		while (i <= magicCardCount + 1 + monsterCount) {
			MagicCard magicCard;
			find1 = line.find('|');
			magicCard.setName(line.substr(0, find1));

			lineSubstring = line.substr(find1 + 1, line.size() - 1);
			find2 = lineSubstring.find('|');
			magicCard.setEffect(lineSubstring.substr(0, find2));

			lineSubstring2 = lineSubstring.substr(find2 + 1, line.size() - 1);
			if (lineSubstring2 == "TRAP") magicCard.setMagicCardType(CardType::TRAP);
			else if (lineSubstring2 == "SPELL") magicCard.setMagicCardType(CardType::SPELL);
			else if (lineSubstring2 == "BUFF") magicCard.setMagicCardType(CardType::BUFF);
			else magicCard.setMagicCardType(CardType::DEFAULT);

			deck.addMagicCard(magicCard);
			i++;
			flag = true;
			break;
		}

		if (flag) continue;

		while (i <= magicCardCount + monsterCount + pendulumCardCount + 1) {
			PendulumCard card;
			find1 = line.find('|');
			card.setName(line.substr(0, find1));

			lineSubstring = line.substr(find1 + 1, line.size() - 1);
			find2 = lineSubstring.find('|');
			card.setEffect(lineSubstring.substr(0, find2));

			lineSubstring2 = lineSubstring.substr(find2 + 1, lineSubstring.size() - 1);
			find1 = lineSubstring2.find('|');
			lineSubstring = lineSubstring2.substr(0, find1);
			card.setAttackPoints(std::stoi(lineSubstring));

			lineSubstring = lineSubstring2.substr(find1 + 1, lineSubstring2.size() - 1);
			find1 = lineSubstring.find('|');
			lineSubstring2 = lineSubstring.substr(0, find1);
			card.setDefencePoints(std::stoi(lineSubstring2));

			lineSubstring2 = lineSubstring.substr(find1 + 1, lineSubstring.size());
			find1 = lineSubstring2.find('|');
			lineSubstring = lineSubstring2.substr(0, find1);
			card.setPendulumScale(std::stoi(lineSubstring));

			lineSubstring = lineSubstring2.substr(find1 + 1, lineSubstring2.size() - 1);
			if (lineSubstring == "TRAP") card.setMagicCardType(CardType::TRAP);
			else if (lineSubstring == "SPELL") card.setMagicCardType(CardType::SPELL);
			else if (lineSubstring == "BUFF") card.setMagicCardType(CardType::BUFF);
			else card.setMagicCardType(CardType::DEFAULT);

			deck.addPendulumCard(card);
			i++;
			flag = true;
			break;
		}

		if (flag) continue;
	}
	
	inFile.close();
	return true;
}

void Duelist::setDuelistName(const std::string& newName) {
	name = newName;
}

std::string Duelist::getDuelistName() const {
	return name;
}

void Duelist::setDeck(const Deck& newDeck) {
	deck = newDeck;
}