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
#include "MagicCard.hpp"
#include<iostream>

MagicCard::MagicCard(std::string name, std::string effect, unsigned int rarity, CardType type)
	:Card(name, effect, rarity), type(type) {}

MagicCard& MagicCard::operator=(const MagicCard& rhs)
{
	if (this != &rhs)
	{
		name = "";
		effect = "";

		Card::setName(rhs.getName());
		Card::setEffect(rhs.getEffect());
		Card::setRarity(rhs.getRarity());
		setType(rhs.getType());
	}

	return *this;
}

MagicCard::MagicCard(const MagicCard& other)
{
	Card::setName(other.getName());
	Card::setEffect(other.getEffect());
	Card::setRarity(other.getRarity());
	setType(other.getType());
}

CardType MagicCard::getType() const
{
	return type;
}

void MagicCard::setType(const CardType value)
{
	this->type = value;
}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

std::ostream& operator<<(std::ostream& out, const MagicCard& m)
{
	out << m.name << '|' << m.effect << '|' << m.rarity << '|' << m.type << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, MagicCard& m)
{
	char delimeter;
	getline(in, m.name, '|');
	getline(in, m.effect, '|');
	in >> m.rarity >> delimeter >> m.type;
	in.ignore(1, '\n');

	return in;
}

std::ostream& operator<<(std::ostream& out, const CardType& t)
{
	switch (t)
	{
	case CardType::TRAP:
		out << "TRAP";
		return out;
		break;
	case CardType::BUFF:
		out << "BUFF";
		return out;
		break;
	case CardType::SPELL:
		out << "SPELL";
		return out;
		break;
	default:
		break;
	}
}

std::istream& operator>>(std::istream& in, CardType& t)
{
	std::string type;
	in >> type;
	if (type == "BUFF")
	{
		t = CardType::BUFF;
		return in;
	}
	if (type == "SPELL")
	{
		t = CardType::SPELL;
		return in;
	}
	if (type == "TRAP")
	{
		t = CardType::TRAP;
		return in;
	}
	return in;
}
