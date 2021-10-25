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
#include "MonsterCard.hpp"
#include <iostream>

MonsterCard::MonsterCard(std::string name, std::string effect, unsigned int rarity, unsigned int attackingPoints, unsigned int protectivePoints)
	:Card(name, effect, rarity), attackingPoints(attackingPoints), protectivePoints(protectivePoints) {}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->effect = rhs.effect;
		this->rarity = rhs.rarity;
		this->attackingPoints = rhs.attackingPoints;
		this->protectivePoints = rhs.protectivePoints;
	}

	return *this;
}

MonsterCard::MonsterCard(const MonsterCard& other)
{
	this->name = other.name;
	this->effect = other.effect;
	this->rarity = other.rarity;
	this->attackingPoints = other.attackingPoints;
	this->protectivePoints = other.protectivePoints;
}

unsigned int MonsterCard::getAttackingPoints() const
{
	return this->attackingPoints;
}

void MonsterCard::setAttackingPoints(unsigned int value)
{
	this->attackingPoints = value;
}

unsigned int MonsterCard::getProtectivePoints() const
{
	return this->protectivePoints;
}

void MonsterCard::setProtectivePoints(unsigned int value)
{
	this->protectivePoints = value;
}


Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}

std::ostream& operator<<(std::ostream& out, const MonsterCard& m)
{
	out << m.name << "|" << m.effect << '|' << m.rarity << '|' << m.attackingPoints << '|' << m.protectivePoints << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, MonsterCard& m)
{
	char delimeter;
	getline(in, m.name, '|');
	getline(in, m.effect, '|');
	in >> m.rarity >> delimeter >> m.attackingPoints >> delimeter >> m.protectivePoints;
	in.ignore(1, '\n');

	return in;
}
