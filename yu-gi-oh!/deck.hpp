/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Nazife Alidzhik
* @idnumber 62598
* @task 2
* @compiler VC
*/
#pragma once
#include "magicCard.hpp"
#include "monsterCard.hpp"

class Deck
{
	MonsterCard monsterCards[20];
	MagicCard magicCards[20];
	int magicCardsCount = 0;
	int monsterCardsCount = 0;

public:
	Deck();
	Deck& operator=(const Deck& other);
	Deck(const Deck& other);
	int getMagicCardCount();
	int getMonsterCardCount();
	void addMagicCard(MagicCard);
	void addMonsterCard(MonsterCard);
	void changeMagicCard(int, const char*, const char*, MagicCardType);
	void changeMonsterCard(int, const char*, int, int);

	MagicCard* getMagicCards();
	MonsterCard* getMonsterCards();

};