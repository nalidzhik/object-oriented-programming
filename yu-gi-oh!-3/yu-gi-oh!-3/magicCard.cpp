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
#include <cstring>
#include <iostream>
#include "magicCard.hpp"

MagicCard::MagicCard(const std::string name, const std::string effect, CardType type)
{
	this->name = name;
	this->effect = effect;
	this->type = type;
}

MagicCard::MagicCard() : MagicCard("", "", spell)
{
	this->name = "";
	this->effect = "";
}

MagicCard& MagicCard::operator=(const MagicCard& other)
{
	if (this != &other)
	{
		name = "";
		effect = "";

		setName(other.getName());
		setEffect(other.getEffect());
		setType(other.getType());
	}

	return *this;
}

MagicCard::MagicCard(const MagicCard& other)
{
	name = "";
	effect = "";

	setName(other.getName());
	setEffect(other.getEffect());
	setType(other.getType());
}


const std::string MagicCard::getName() const
{
	return name;
}

void MagicCard::setName(const std::string value)
{
	this->name = value;
}

const std::string MagicCard::getEffect() const
{
	return effect;
}

void MagicCard::setEffect(const std::string value)
{
	this->effect = value;
}

CardType MagicCard::getType() const
{
	return type;
}

void MagicCard::setType(const CardType value)
{
	this->type = value;
}

std::ostream& operator<<(std::ostream& out, const MagicCard& m)
{
	out << m.name << '|' << m.effect << '|' << m.type;

	return out;
}

std::istream& operator>>(std::istream& in, MagicCard& m)
{
	char delimeter = '|';
	std::string name;
	std::string effect;
	std::string typeAsString;

	std::getline(in, name, delimeter);
	std::getline(in, effect, delimeter);
	std::getline(in, typeAsString);

	switch (stoi(typeAsString))
	{
	case 0:
		m.type = trap;
		break;
	case 1:
		m.type = buff;
		break;
	case 2:
		m.type = spell;
		break;
	default:
		break;
	}

	m.setName(name);
	m.setEffect(effect);

	return in;
}