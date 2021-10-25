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
#pragma once
#include "magicCard.hpp"
#include "monsterCard.hpp"
#include"pendulumCard.hpp"
#include<fstream>
#include<vector>

class Deck
{
private:
	std::string name;
	std::vector <MonsterCard> monsterCards;
	std::vector <MagicCard> magicCards;
	std::vector <PendulumCard> pendulumCards;
	unsigned int magicCardsCount = 0;
	unsigned int monsterCardsCount = 0;
	unsigned int pendulumCardsCount = 0;

public:
	Deck() = default;
	Deck(std::string, std::vector <MonsterCard>, std::vector <MagicCard>, std::vector <PendulumCard>);
	Deck& operator=(const Deck&);
	Deck(const Deck&);
	unsigned int getMagicCardCount() const;
	unsigned int getMonsterCardCount() const;
	unsigned int getPendulumCardCount() const;
	void addMagicCard(MagicCard);
	void addMonsterCard(MonsterCard);
	void addPendulumCard(PendulumCard);
	void changeMagicCard(unsigned int, MagicCard);
	void changeMonsterCard(unsigned int, MonsterCard);
	void changePendulumCard(unsigned int, PendulumCard);
	void removeDeck();

	const std::string getDeckName() const;
	void setDeckName(std::string);
	std::vector<MagicCard> getMagicCards() const;
	std::vector<MonsterCard> getMonsterCards() const;
	std::vector<PendulumCard> getPendulumCards() const;

	friend std::ostream& operator<<(std::ostream&, const Deck&);
	friend std::istream& operator>>(std::istream&, Deck&);
};