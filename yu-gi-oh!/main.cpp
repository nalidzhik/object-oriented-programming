#include <iostream>
#include "magicCard.hpp"
#include "monsterCard.hpp"
#include "deck.hpp"
#include "duelist.hpp"
using namespace std;

int main()
{
	//Deck d;

	//MagicCard m("name", "spell", spell);
	//d.addMagicCard(m);
	//cout << d.getMagicCardCount();
	//cout << endl;


	//d.changeMagicCard(0, "name2", "spell2", spell);

	//MagicCard card = d.getMagicCards()[0];
	//cout << "card=" << card.getName() << ", " << card.getEffect() << ", " << card.getType() << endl;

	MagicCard m("name", "spell", spell);
	cout << "card=" << m.getName() << ", " << m.getEffect() << ", " << m.getType() << endl;

	Deck d;
	d.addMagicCard(m);

	d.changeMagicCard(0, "name2", "spell2", spell);

	MagicCard card1 = d.getMagicCards()[0];
	cout << "card1=" << card1.getName() << ", " << card1.getEffect() << ", " << card1.getType() << endl;

	MonsterCard y("monster", 32, 12);
	cout << "card2=" << y.getName() << ", " << y.getAttackingPoints() << ", " << y.getProtectivePoints() << endl;
	Deck f;
	f.addMonsterCard(y);

	f.changeMonsterCard(0, "name2", 2, 16);

	MonsterCard card2= f.getMonsterCards()[0];
	cout << "card2=" << card2.getName() << ", " << card2.getAttackingPoints() << ", " << card2.getProtectivePoints() << endl;

	Duelist player1("Seto Kaiba");
	///Changes the 2-nd monster card in the Monster deck to“Dark Magician”
	MonsterCard darkMagician("Dark Magician", 2500, 2100);
	player1.addMonsterCardInDeck(darkMagician);

	MonsterCard darkMagicianGirl("Dark Magician Girl", 2000, 1700);

	player1.changeMonsterCardInDeck(0, darkMagicianGirl);
	cout << "player1=" << player1.getName() << endl;
	Deck player1Deck = player1.getDeck();
	for (size_t i = 0; i < player1Deck.getMonsterCardCount(); i++)
	{
		MonsterCard c = player1Deck.getMonsterCards()[0];
		cout << "card=" << c.getName() << ", " << c.getAttackingPoints() << ", " << c.getProtectivePoints() << endl;
	}

	return 0;
}