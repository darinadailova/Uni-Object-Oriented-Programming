#include <iostream>
#include "Duelist.hpp"

int main() {
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, CardType::SPELL, 8);

	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckName("Magician Deck");
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&timegazer);
	
	firstDuelist.getDeck().shuffle();
	firstDuelist.saveDeck("magician_deck.txt");
	MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
	firstDuelist.getDeck().changeCard(1, &box);

	Duelist secondDuelist("Gosho Goshev");
	secondDuelist.getDeck().addCard(&dragon);
	secondDuelist.getDeck().addCard(&swords);
	secondDuelist.getDeck().addCard(&magician);
	secondDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&timegazer);

	secondDuelist.duel(firstDuelist);

	return 0;
}