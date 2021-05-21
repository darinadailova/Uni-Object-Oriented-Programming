#pragma once
#include "Deck.hpp"
#include <fstream>

class Duelist {
	std::string name;
	Deck deck;
public:
	Duelist(const std::string& newName = "");
	Duelist(const std::string& newName, const Deck& newDeck);
	Duelist(const Duelist& rhs);
	Duelist& operator=(const Duelist& rhs);

	Deck& getDeck();
	bool saveDeck(const std::string& fileName) const;
	bool loadDeck(const std::string& filename);

	void setDuelistName(const std::string& newName);
	std::string getDuelistName() const;
	void setDeck(const Deck& newDeck);
};