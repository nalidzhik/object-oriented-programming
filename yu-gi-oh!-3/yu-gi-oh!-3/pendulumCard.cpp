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
#include"pendulumCard.hpp"
#include<iostream>

PendulumCard::PendulumCard(const std::string _name, const std::string _effect, unsigned int _attack, unsigned int _protect, unsigned int _pendulumScale, CardType _type) : MonsterCard(_name, _effect, _attack, _protect), MagicCard(_name, _effect, _type)
{
	if (_pendulumScale >= 1 && _pendulumScale <= 13)
	{
		this->pendulumScale = _pendulumScale;
	}
}

unsigned int PendulumCard::getPendulumScale() const
{
	return this->pendulumScale;
}

void PendulumCard::setPendulumScales(unsigned int value)
{
	this->pendulumScale = value;
}

std::ostream& operator<<(std::ostream& out, const PendulumCard& p)
{
	out << p.MonsterCard::getName() << "|" << p.MonsterCard::getEffect() << "|" << p.MonsterCard::getAttackingPoints() << "|" << p.MonsterCard::getProtectivePoints() << "|";
	out << p.pendulumScale << "|" << p.getType();

	return out;
}

std::istream& operator>>(std::istream& in, PendulumCard& p)
{
	char delimeter = '|';
	std::string name;
	std::string effect;
	std::string attackPointsAsString;
	std::string defencePointsAsString;
	std::string pendulumScaleAsString;;
	std::string typeAsString;

	std::getline(in, name, delimeter);
	std::getline(in, effect, delimeter);
	std::getline(in, attackPointsAsString, delimeter);
	std::getline(in, defencePointsAsString, delimeter);
	std::getline(in, pendulumScaleAsString, delimeter);
	std::getline(in, typeAsString);
	switch (stoi(typeAsString))
	{
	case 0:
		p.MagicCard::setType(trap);
		break;
	case 1:
		p.MagicCard::setType(buff);
		break;
	case 2:
		p.MagicCard::setType(spell);
		break;
	default:
		break;
	}
	p.MonsterCard::setName(name);
	p.MonsterCard::setEffect(effect);
	p.MonsterCard::setAttackingPoints(stoi(attackPointsAsString));
	p.MonsterCard::setProtectivePoints(stoi(defencePointsAsString));
	p.pendulumScale = stoi(pendulumScaleAsString);

	return in;
}
