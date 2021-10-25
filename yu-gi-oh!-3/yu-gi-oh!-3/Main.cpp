/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Nazife Alidzhik
* @idnumber 62598
* @task 1
* @compiler VC
*/
#include <iostream>
#include "magicCard.hpp"
#include "monsterCard.hpp"
#include "deck.hpp"
#include "duelist.hpp"
#include "pendulumCard.hpp"

using namespace std;

int main()
{
	MagicCard m("name", "spell", spell);
	MagicCard le("hei", "pff", buff);
	cout << "card=" << m.getName() << ", " << m.getEffect() << ", " << m.getType() << endl;
	Deck d;
	d.addMagicCard(m);
	d.changeMagicCard(0, le);

	MagicCard card1 = d.getMagicCards()[0];
	cout << "card1=" << card1.getName() << ", " << card1.getEffect() << ", " << card1.getType() << endl;
	Duelist player1("Seto Kaiba");

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", spell);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", trap);
	cout << cylinder << endl;
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap MagicCards", 1200, 600, 8, spell);
	PendulumCard timegazer2("Timegazer Magician", "Your opponent cannot activate Trap MagicCards", 1200, 600, 8, spell);
	cout << timegazer << endl;
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckName("Magician Deck");
	firstDuelist.getDeck().addMonsterCard(dragon);
	firstDuelist.getDeck().addMagicCard(swords);
	firstDuelist.getDeck().addMonsterCard(magician);
	firstDuelist.getDeck().addMagicCard(cylinder);
	firstDuelist.getDeck().addPendulumCard(timegazer);
	firstDuelist.getDeck().addPendulumCard(timegazer2);
	cout << firstDuelist.getDeck();

	bool istrue = firstDuelist.saveDeck("magician_deck.txt"); // exist
	cout << "is true: " << istrue << endl;
	bool istrue1 = firstDuelist.saveDeck("magic_deck.txt"); // not exist
	cout << "is true1: " << istrue << endl;
	bool isloaded = firstDuelist.loadDeck("magician_deck.txt");
	cout << "is loaded deck: " << isloaded << endl;
	MagicCard box("Mystic Box", "Destroy one monster.", CardType::spell);
	firstDuelist.getDeck().changeMagicCard(1, box);
	cout << firstDuelist.getDeck();
	Duelist secondDuelist("Iva Ivanova");
	secondDuelist.getDeck().setDeckName("Iva Ivanova's deck");
	secondDuelist.getDeck().addMagicCard(swords);
	secondDuelist.getDeck().addMonsterCard(magician);
	secondDuelist.getDeck().addMagicCard(cylinder);
	secondDuelist.getDeck().addPendulumCard(timegazer);
	secondDuelist.getDeck().addPendulumCard(timegazer2);
	secondDuelist.saveDeck("magician_deck2.txt");

	Duelist thirdDuelist("Petur Petrov");
	cout << "Petur Petrov's deck" << endl;
	thirdDuelist.loadDeck("magician_deck2.txt");
	cout << thirdDuelist.getDeck();

	return 0;
}