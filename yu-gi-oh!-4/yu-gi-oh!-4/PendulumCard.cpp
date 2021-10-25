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
#include "PendulumCard.hpp"
#include <iostream>

PendulumCard::PendulumCard(std::string _name, std::string _effect, unsigned int _rarity, unsigned int _attackingPoints, unsigned int _protectivePoints, unsigned int _pendulumScale, CardType _type)
	:MonsterCard(_name, _effect, _rarity, _attackingPoints, _protectivePoints), MagicCard(_name, _effect, _rarity, _type), Card(_name, _effect, _rarity)
{
	if (_pendulumScale >= 1 && _pendulumScale <= 13)
	{
		this->pendulumScale = _pendulumScale;
	}
}

unsigned int PendulumCard::getPendulumScale() const
{
	return this->pendulumScale;;
}

void PendulumCard::setPendulumScales(unsigned int value)
{
	if (value > 0 && value < 14)
	{
		this->pendulumScale = value;
	}
}

Card* PendulumCard::clone() const
{
	return new PendulumCard(*this);
}

std::ostream& operator<<(std::ostream& out, const PendulumCard& p)
{
	out << p.name << "|" << p.effect << "|" << p.rarity << "|" << p.attackingPoints << "|" << p.protectivePoints << "|";
	out << p.pendulumScale << "|" << p.type << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, PendulumCard& p)
{
	char delimeter;
	getline(in, p.name, '|');
	getline(in, p.effect, '|');
	in >> p.rarity >> delimeter >> p.attackingPoints >> delimeter >> p.protectivePoints >> delimeter >> p.pendulumScale >> delimeter >> p.type;
	in.ignore(1, '\n');
	return in;
}
