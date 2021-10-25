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
#include "monsterCard.hpp"
#include <string>
#include <iostream>

MonsterCard::MonsterCard(const std::string name, const std::string effect, unsigned int attack, unsigned  int protect)
{
	this->name = name;
	this->effect = effect;
	this->attackingPoints = attack;
	this->protectivePoints = protect;
}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->effect = rhs.effect;
		this->attackingPoints = rhs.attackingPoints;
		this->protectivePoints = rhs.protectivePoints;
	}

	return *this;
}

MonsterCard::MonsterCard(const MonsterCard& other)
{
	this->name = other.name;
	this->effect = other.effect;
	this->attackingPoints = other.attackingPoints;
	this->protectivePoints = other.protectivePoints;
}

MonsterCard::MonsterCard()
{
	this->name = "";
	this->effect = "";
	attackingPoints = 0;
	protectivePoints = 0;
}

const std::string MonsterCard::getName() const
{
	return this->name;
}

void MonsterCard::setName(const std::string value)
{
	this->name = value;
}

const std::string MonsterCard::getEffect() const
{
	return this->effect;
}

void MonsterCard::setEffect(std::string value)
{
	this->effect = value;
}

unsigned int MonsterCard::getAttackingPoints() const
{
	return this->attackingPoints;
}

void MonsterCard::setAttackingPoints(unsigned int attackPoint)
{
	this->attackingPoints = attackPoint;
}

unsigned int MonsterCard::getProtectivePoints() const
{
	return this->protectivePoints;
}

void MonsterCard::setProtectivePoints(unsigned int protectPoint)
{
	this->protectivePoints = protectPoint;
}

std::ostream& operator<<(std::ostream& out, const MonsterCard& m)
{
	out << m.name << "|" << m.effect << '|' << m.attackingPoints << '|' << m.protectivePoints;

	return out;
}

std::istream& operator>>(std::istream& in, MonsterCard& m)
{
	char delimeter = '|';
	std::string name;
	std::string effect;
	std::string attackPointsAsString;
	std::string defencePointsAsString;

	std::getline(in, name, delimeter);
	std::getline(in, effect, delimeter);
	std::getline(in, attackPointsAsString, delimeter);
	std::getline(in, defencePointsAsString);

	m.setName(name);
	m.setEffect(effect);
	m.attackingPoints = stoi(attackPointsAsString);
	m.protectivePoints = stoi(defencePointsAsString);

	return in;
}
