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
#include "deck.hpp"

class Duelist
{
	char* name;
	Deck deck;

public:
	Duelist();
	Duelist(const char*);
	~Duelist();
	void addMagicCardInDeck(MagicCard);
	void addMonsterCardInDeck(MonsterCard);
	void changeMagicCardInDeck(int, MagicCard);
	void changeMonsterCardInDeck(int, MonsterCard);

	const char* getName() const;
	void setName(const char*);
	Deck getDeck() const;
	void setDeck(const Deck);
};