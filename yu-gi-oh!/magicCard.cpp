#include <cstring>
#include <iostream>
#include "magicCard.hpp"
#include "Utils.hpp"

MagicCard::MagicCard(const char* name, const char* effect, MagicCardType type)
{
	this->name = NULL;
	this->effect = NULL;

	setName(name);
	setEffect(effect);
	this->type = type;
}

MagicCard::MagicCard() : MagicCard("", "", spell)
{
	this->name = NULL;
	this->effect = NULL;
}

MagicCard& MagicCard::operator=(const MagicCard& other)
{
	if (this != &other)
	{
		name = NULL;
		effect = NULL;

		setName(other.getName());
		setEffect(other.getEffect());
		setType(other.getType());
	}

	return *this;
}

MagicCard::MagicCard(const MagicCard& other)
{
	name = NULL;
	effect = NULL;

	setName(other.getName());
	setEffect(other.getEffect());
	setType(other.getType());
}

MagicCard::~MagicCard()
{
	delete[] name;
	delete[] effect;
}

const char* MagicCard::getName() const
{
	return name;
}

void MagicCard::setName(const char* value)
{
	AllocateAndCopy(name, value);
}

const char* MagicCard::getEffect() const
{
	return effect;
}

void MagicCard::setEffect(const char* value)
{
	AllocateAndCopy(effect, value);
}

MagicCardType MagicCard::getType() const
{
	return type;
}

void MagicCard::setType(const MagicCardType value)
{
	this->type = value;
}
