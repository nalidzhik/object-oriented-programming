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
#include <iostream>
#include "deck.hpp"
#include "magicCard.hpp"
#include "monsterCard.hpp"
#include "Utils.hpp"


Deck::Deck()
{
}

Deck& Deck::operator=(const Deck& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 20; i++)
		{
			this->magicCards[i] = other.magicCards[i];
			this->monsterCards[i] = other.monsterCards[i];
		}
		this->magicCardsCount = other.magicCardsCount;
		this->monsterCardsCount = other.monsterCardsCount;
	}

	return *this;
}

Deck::Deck(const Deck& other)
{
	for (size_t i = 0; i < 20; i++)
	{
		this->magicCards[i] = other.magicCards[i];
		this->monsterCards[i] = other.monsterCards[i];
	}
	this->magicCardsCount = other.magicCardsCount;
	this->monsterCardsCount = other.monsterCardsCount;
}

int Deck::getMagicCardCount()
{
	return magicCardsCount;
}

int Deck::getMonsterCardCount()
{
	return monsterCardsCount;
}

void Deck::addMagicCard(MagicCard card)
{
	this->magicCards[this->magicCardsCount] = card;
	this->magicCardsCount += 1;
}

void Deck::addMonsterCard(MonsterCard card)
{
	this->monsterCards[this->magicCardsCount] = card;
	this->monsterCardsCount += 1;
}

void Deck::changeMagicCard(int index, const char* name, const char* effect, MagicCardType type)
{
	MagicCard card = this->magicCards[index];

	card.setName(name);
	card.setEffect(effect);
	card.setType(type);

	this->magicCards[index] = card;
}

void Deck::changeMonsterCard(int index, const char* name, int attackPoints, int protectPoints)
{
	MonsterCard card = this->monsterCards[index];

	card.setName(name);
	card.setAttackingPoints(attackPoints);
	card.setProtectivePoints(protectPoints);

	this->monsterCards[index] = card;
}

MagicCard* Deck::getMagicCards()
{
	return this->magicCards;
}

MonsterCard* Deck::getMonsterCards()
{
	return this->monsterCards;
}

