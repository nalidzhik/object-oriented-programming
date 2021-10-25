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
#include "Deck.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "PendulumCard.hpp"
#include "Card.hpp"


Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs) {
		for (auto x : cards) {
			delete x;
		}
		cards.clear();

		for (auto x : rhs.cards) {
			cards.push_back(x->clone());
		}
		this->name = rhs.name;
		this->cardsCount = rhs.cardsCount;
		this->monsterCardsCount = rhs.monsterCardsCount;
		this->magicCardsCount = rhs.magicCardsCount;
		this->pendulumCardsCount = rhs.pendulumCardsCount;
	}
	return *this;
}

Deck::Deck(const Deck& other)
{
	this->name = other.name;
	for (auto x : other.cards) {
		cards.push_back(x->clone());
	}
	this->cardsCount = other.cardsCount;
	this->monsterCardsCount = other.monsterCardsCount;
	this->magicCardsCount = other.magicCardsCount;
	this->pendulumCardsCount = other.pendulumCardsCount;
}

Deck::~Deck()
{
	removeDeck();
}

void Deck::addCard(Card* card)
{
	PendulumCard* castToPendulumCard = dynamic_cast<PendulumCard*>(card);
	if (castToPendulumCard != nullptr)
	{
		cards.push_back(card);
		pendulumCardsCount += 1;
		cardsCount += 1;
		return;
	}

	MagicCard* castToMagicCard = dynamic_cast<MagicCard*>(card);
	if (castToMagicCard != nullptr)
	{
		Card* tmp = new MagicCard(*castToMagicCard);
		cards.push_back(tmp);
		magicCardsCount += 1;
		cardsCount += 1;
		return;
	}

	MonsterCard* castToMonsterCard = dynamic_cast<MonsterCard*>(card);
	if (castToMonsterCard != nullptr)
	{
		Card* tmp = new MonsterCard(*castToMonsterCard);
		cards.push_back(tmp);
		monsterCardsCount += 1;
		cardsCount += 1;
		return;
	}
}

void Deck::changeCard(int index, Card* card)
{
	if (index < 0)
	{
		return;
	}
	if ((unsigned)index > cards.size())
	{
		addCard(card);
		return;
	}

	PendulumCard* pendulumCardPtr = dynamic_cast<PendulumCard*>(cards[index]);
	if (pendulumCardPtr)
	{
		cards.at(index) = card;
		return;
	}
	MagicCard* magicCardPtr = dynamic_cast<MagicCard*>(cards[index]);
	if (magicCardPtr)
	{
		cards.at(index) = card;
		return;
	}
	MonsterCard* monsterCardPtr = dynamic_cast<MonsterCard*>(cards[index]);
	if (monsterCardPtr)
	{
		cards.at(index) = card;
		return;
	}

}

void Deck::removeDeck()
{
	cards.clear();
	for (auto x : cards)
	{
		delete x;
	}
	this->name = "";
	this->magicCardsCount = 0;
	this->monsterCardsCount = 0;
	this->pendulumCardsCount = 0;
}

unsigned int Deck::getCardsCount() const
{
	return this->cardsCount;
}

unsigned int Deck::getMagicCardsCount() const
{
	return this->magicCardsCount;
}

unsigned int Deck::getMonsterCardsCount() const
{
	return this->monsterCardsCount;
}

unsigned int Deck::getPendulumCardsCount() const
{
	return this->pendulumCardsCount;
}

void Deck::shuffle()
{
	srand(time(NULL));
	std::random_shuffle(cards.begin(), cards.end());
}

const std::string Deck::getDeckName() const
{
	return this->name;
}

void Deck::setDeckName(std::string value)
{
	this->name = value;
}

std::vector<Card*> Deck::getCards() const
{
	return this->cards;
}

std::ostream& operator<<(std::ostream& out, const Deck& d)
{
	out << d.name << '|' << d.cardsCount << '|' << d.monsterCardsCount << '|' << d.magicCardsCount << '|' << d.pendulumCardsCount << std::endl;

	for (int i = 0; i < d.cards.size(); i++)
	{
		PendulumCard* pendulumCardPtr = dynamic_cast<PendulumCard*>(d.cards[i]);
		MonsterCard* monsterCardPtr = dynamic_cast<MonsterCard*>(d.cards[i]);
		if (monsterCardPtr && !pendulumCardPtr)
		{
			out << *monsterCardPtr;
		}
	}
	for (int i = 0; i < d.cards.size(); i++)
	{
		PendulumCard* pendulumCardPtr = dynamic_cast<PendulumCard*>(d.cards[i]);
		MagicCard* magicCardPtr = dynamic_cast<MagicCard*>(d.cards[i]);
		if (magicCardPtr && !pendulumCardPtr)
		{
			out << *magicCardPtr;
		}
	}
	for (int i = 0; i < d.cards.size(); i++)
	{
		PendulumCard* pendulumCardPtr = dynamic_cast<PendulumCard*>(d.cards[i]);

		if (pendulumCardPtr)
		{
			out << *pendulumCardPtr;
		}
	}
	return out;
}

std::istream& operator>>(std::istream& in, Deck& d)
{
	char delimeter = '|';
	d.removeDeck();
	std::getline(in, d.name, delimeter);
	in >> d.cardsCount >> delimeter >> d.monsterCardsCount >> delimeter >> d.magicCardsCount >> delimeter >> d.pendulumCardsCount;
	in.ignore(1, '\n');

	PendulumCard pendulum;
	MagicCard magic;
	MonsterCard monster;
	for (int i = 0; i < d.monsterCardsCount; i++)
	{
		in >> monster;
		d.cards.push_back(monster.clone());
	}
	for (int i = 0; i < d.magicCardsCount; i++)
	{
		in >> magic;
		d.cards.push_back(magic.clone());
	}
	for (int i = 0; i < d.pendulumCardsCount; i++)
	{
		in >> pendulum;
		d.cards.push_back(pendulum.clone());
	}
	return in;
}
