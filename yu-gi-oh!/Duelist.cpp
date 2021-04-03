#include <iostream>
#include "Duelist.hpp"
#include "Utils.hpp"
#include "magicCard.hpp"
#include "monsterCard.hpp"


Duelist::Duelist() : Duelist("")
{
	this->name = NULL;
}

Duelist::Duelist(const char* name)
{
	this->name = NULL;

	setName(name);
}

Duelist::~Duelist()
{
	delete[] name;
}

void Duelist::addMagicCardInDeck(MagicCard card)
{
	this->deck.addMagicCard(card);
}

void Duelist::addMonsterCardInDeck(MonsterCard card)
{
	this->deck.addMonsterCard(card);
}

void Duelist::changeMagicCardInDeck(int index, MagicCard card)
{
	this->deck.changeMagicCard(index, card.getName(), card.getEffect(), card.getType());
}

void Duelist::changeMonsterCardInDeck(int index, MonsterCard card)
{
	this->deck.changeMonsterCard(index, card.getName(), card.getAttackingPoints(), card.getProtectivePoints());
}

const char* Duelist::getName() const
{
	return name;
}

void Duelist::setName(const char* value)
{
	AllocateAndCopy(name, value);
}

Deck Duelist::getDeck() const
{
	return deck;
}

void Duelist::setDeck(const Deck value)
{
	this->deck = value;
}
