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
#include "deck.hpp"

Deck::Deck(std::string name, std::vector<MonsterCard> monster, std::vector<MagicCard> magic, std::vector<PendulumCard> pendulum)
{
	this->name = name;
	this->pendulumCards = pendulum;
	this->magicCards = magic;
	this->monsterCards = monster;
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->magicCards = rhs.magicCards;
		this->monsterCards = rhs.monsterCards;
		this->pendulumCards = rhs.pendulumCards;
		this->monsterCardsCount = rhs.monsterCardsCount;
		this->magicCardsCount = rhs.magicCardsCount;
		this->pendulumCardsCount = rhs.pendulumCardsCount;
	}

	return *this;
}

Deck::Deck(const Deck& other)
{
	this->name = other.name;
	this->magicCards = other.magicCards;
	this->monsterCards = other.monsterCards;
	this->pendulumCards = other.pendulumCards;
	this->monsterCardsCount = other.monsterCardsCount;
	this->magicCardsCount = other.magicCardsCount;
	this->pendulumCardsCount = other.pendulumCardsCount;
}
unsigned int Deck::getMagicCardCount()const
{
	return this->magicCardsCount;
}

unsigned int Deck::getMonsterCardCount() const
{
	return this->monsterCardsCount;
}

unsigned int Deck::getPendulumCardCount() const
{
	return this->pendulumCardsCount;
}

void Deck::addMagicCard(MagicCard card)
{
	magicCards.push_back(card);
	this->magicCardsCount += 1;
}

void Deck::addMonsterCard(MonsterCard card)
{
	monsterCards.push_back(card);
	this->monsterCardsCount += 1;
}

void Deck::addPendulumCard(PendulumCard card)
{
	pendulumCards.push_back(card);
	this->pendulumCardsCount += 1;
}

void Deck::changeMagicCard(unsigned int index, MagicCard card)
{
	for (int i = 0; i < magicCards.size(); i++)
	{
		if (i == index)
		{
			magicCards.at(i) = card;
			break;
		}
	}
}

void Deck::changeMonsterCard(unsigned int index, MonsterCard card)
{
	for (int i = 0; i < monsterCards.size(); i++)
	{
		if (i == index)
		{
			monsterCards.at(i) = card;
			break;
		}
	}
}

void Deck::changePendulumCard(unsigned int index, PendulumCard card)
{
	for (int i = 0; i < pendulumCards.size(); i++)
	{
		if (i == index)
		{
			pendulumCards.at(i) = card;
			break;
		}
	}
}

void Deck::removeDeck()
{
	magicCards.clear();
	monsterCards.clear();
	pendulumCards.clear();
	this->name = "";
	this->magicCardsCount = 0;
	this->monsterCardsCount = 0;
	this->pendulumCardsCount = 0;
}

const std::string Deck::getDeckName() const
{
	return this->name;
}

void Deck::setDeckName(std::string value)
{
	this->name = value;
}

std::vector<MagicCard>  Deck::getMagicCards() const
{
	return this->magicCards;
}

std::vector<MonsterCard> Deck::getMonsterCards() const
{
	return this->monsterCards;
}

std::vector<PendulumCard>  Deck::getPendulumCards() const
{
	return this->pendulumCards;
}

std::ostream& operator<<(std::ostream& out, const Deck& d)
{
	out << d.name << '|' << d.monsterCardsCount << '|' << d.magicCardsCount << '|' << d.pendulumCardsCount << std::endl;
	for (int i = 0; i < d.monsterCardsCount; i++)
	{
		out << d.monsterCards[i] << std::endl;
	}
	for (int i = 0; i < d.magicCardsCount; i++)
	{
		out << d.magicCards[i] << std::endl;
	}
	for (int i = 0; i < d.pendulumCardsCount; i++)
	{
		out << d.pendulumCards[i] << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Deck& d)
{
	char delimeter = '|';

	std::string name;
	std::string monsterCardsCountAsString;
	std::string magicCardsCountAsString;
	std::string pendulumCardsCountAsString;

	std::getline(in, name, delimeter);
	std::getline(in, monsterCardsCountAsString, delimeter);
	std::getline(in, magicCardsCountAsString, delimeter);
	std::getline(in, pendulumCardsCountAsString);

	d.setDeckName(name);
	d.monsterCardsCount = stoi(monsterCardsCountAsString);
	d.magicCardsCount = stoi(magicCardsCountAsString);
	d.pendulumCardsCount = stoi(pendulumCardsCountAsString);

	for (int i = 0; i < d.monsterCardsCount; i++)
	{
		MonsterCard card;
		in >> card;
		d.monsterCards.push_back(card);
	}
	for (int i = 0; i < d.magicCardsCount; i++)
	{
		MagicCard card;
		in >> card;
		d.magicCards.push_back(card);
	}
	for (int i = 0; i < d.pendulumCardsCount; i++)
	{
		PendulumCard card;
		in >> card;
		d.pendulumCards.push_back(card);
	}
	return in;
}
