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
#pragma once
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
#include "PendulumCard.hpp"
#include "Card.hpp"
#include<fstream>
#include<vector>

class Deck
{
private:
	std::string name;
	std::vector <Card*> cards;
	unsigned int cardsCount = 0;
	unsigned int magicCardsCount = 0;
	unsigned int monsterCardsCount = 0;
	unsigned int pendulumCardsCount = 0;

public:
	Deck() = default;
	Deck& operator=(const Deck&);
	Deck(const Deck&);
	~Deck();

	unsigned int getCardsCount() const;
	unsigned int getMagicCardsCount() const;
	unsigned int getMonsterCardsCount() const;
	unsigned int getPendulumCardsCount() const;
	void addCard(Card*);
	void changeCard(int, Card*);
	void removeDeck();
	void shuffle();

	const std::string getDeckName() const;
	void setDeckName(std::string);
	std::vector<Card*> getCards() const;

	friend std::ostream& operator<<(std::ostream&, const Deck&);
	friend std::istream& operator>>(std::istream&, Deck&);
};