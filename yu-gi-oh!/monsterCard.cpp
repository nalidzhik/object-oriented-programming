#include "monsterCard.hpp"
#include <cstring>
#include "Utils.hpp"

MonsterCard::MonsterCard(const char* name, int attack, int protect)
{
	this->name = NULL;
	attackingPoints = 0;
	protectivePoints = 0;

	setName(name);
	this->attackingPoints = attack;
	this->protectivePoints = protect;
}

MonsterCard& MonsterCard::operator=(const MonsterCard& other)
{
	if (this != &other)
	{
		name = NULL;
		attackingPoints = 0;
		protectivePoints = 0;

		setName(other.getName());
		setAttackingPoints(other.getAttackingPoints());
		setProtectivePoints(other.getProtectivePoints());
	}

	return *this;
}

MonsterCard::MonsterCard(const MonsterCard& other)
{
	name = NULL;

	setName(other.getName());
	setAttackingPoints(other.getAttackingPoints());
	setProtectivePoints(other.getProtectivePoints());
}

MonsterCard::~MonsterCard()
{
	delete[] name;
}

MonsterCard::MonsterCard()
{
	this->name = NULL;
	attackingPoints = 0;
	protectivePoints = 0;
}

const char* MonsterCard::getName() const
{
	return name;
}

void MonsterCard::setName(const char* value)
{
	AllocateAndCopy(name, value);
}

int MonsterCard::getAttackingPoints() const
{
	return attackingPoints;
}

void MonsterCard::setAttackingPoints(int attackPoint)
{
	this->attackingPoints = attackPoint;
}

int MonsterCard::getProtectivePoints() const
{
	return protectivePoints;
}

void MonsterCard::setProtectivePoints(int protectPoint)
{
	this->protectivePoints = protectPoint;
}
