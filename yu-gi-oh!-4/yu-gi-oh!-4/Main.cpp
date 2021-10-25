/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Nazife Alidzhik
* @idnumber 62598
* @task 4
* @compiler VC
*/
#include <iostream>
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"
#include "PendulumCard.hpp"

using namespace std;

int main()
{
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::BUFF);
	Duelist firstDuelist("Ivan Ivanov ");
	firstDuelist.getDeck().setDeckName("Magician Deck");
	cout << dragon;
	cout << swords;
	cout << timegazer << endl;
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&timegazer);
	cout << "First duelist with added cards:" << endl;
	cout << firstDuelist;

	MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
	firstDuelist.getDeck().changeCard(1, &box);
	MonsterCard magician2("Dark Magician 2", "The ultimate wizard 2.", 23, 2500, 2100);
	firstDuelist.getDeck().changeCard(2, &magician2);
	PendulumCard timegazer3("Timegazer Magician 3", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::BUFF);
	firstDuelist.getDeck().changeCard(4, &timegazer3);
	cout << "First duelist with changed cards:" << endl;
	cout << firstDuelist;

	firstDuelist.getDeck().shuffle();
	cout << "Shuffle one: ";
	cout << firstDuelist;
	firstDuelist.getDeck().shuffle();
	cout << "Shuffle two: ";
	cout << firstDuelist;

	Duelist secondDuelist("Gosho Goshev ");
	secondDuelist.loadDeck("magician_deck2.txt");
	cout << secondDuelist;
	secondDuelist.getDeck().addCard(&dragon);
	secondDuelist.getDeck().addCard(&swords);
	secondDuelist.getDeck().addCard(&magician);
	secondDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&timegazer);

	firstDuelist.saveDeck("magician_deck.txt");
	bool isSuccessful = firstDuelist.saveDeck("magician_deck.txt");
	cout << "Is successful saving deck: " << isSuccessful << endl;

	Duelist thirdDuelist("Petur Petrov ");
	bool isSuccessfulLoad = thirdDuelist.loadDeck("magician_deck2.txt");
	cout << "Is successful loading deck: " << isSuccessfulLoad << endl;
	cout << "Petur Petrov's deck" << endl;
	thirdDuelist.loadDeck("magician_deck2.txt");
	cout << thirdDuelist;

	Duelist fourthDuelist("Player One");
	Duelist fifthDuelist("Player Two ");
	fourthDuelist.getDeck().addCard(&dragon);
	fourthDuelist.getDeck().addCard(&swords);
	fourthDuelist.getDeck().addCard(&box);
	fifthDuelist.getDeck().addCard(&cylinder);
	fifthDuelist.getDeck().addCard(&magician);
	fifthDuelist.getDeck().addCard(&timegazer);
	cout << "The duel: ";
	fourthDuelist.duel(fifthDuelist);
	cout << endl;
	cout << "The duel with bonus method: (expected player one) : " << endl;
	duel(fourthDuelist, fifthDuelist);
	MonsterCard dragon1("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 23, 3000, 2500);
	MonsterCard magician1("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
	MagicCard swords1("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
	MagicCard cylinder1("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 123, CardType::TRAP);
	PendulumCard timegazer1("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::BUFF);
	PendulumCard timegazer2("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::BUFF);
	Duelist sixthDuelist("Petur");
	Duelist seventhDuelist("Pavlin");
	sixthDuelist.getDeck().addCard(&dragon1);
	sixthDuelist.getDeck().addCard(&swords1);
	sixthDuelist.getDeck().addCard(&timegazer1);
	seventhDuelist.getDeck().addCard(&magician1);
	seventhDuelist.getDeck().addCard(&cylinder1);
	seventhDuelist.getDeck().addCard(&timegazer2);
	cout << "The duel: (expected equality) : ";
	sixthDuelist.duel(seventhDuelist);
	cout << endl;
	cout << "The duel with bonus method: (expected equality) : ";
	duel(sixthDuelist, seventhDuelist);
	cout << endl;

	return 0;
}