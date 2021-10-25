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
#include "Card.hpp"
#include <iostream>


Card::Card(const std::string name, const std::string effect, unsigned int rarity)
	: name(name), effect(effect), rarity(rarity) {}

const std::string Card::getName() const
{
	return this->name;
}

void Card::setName(const std::string value)
{
	this->name = value;
}

const std::string Card::getEffect() const
{
	return this->effect;
}

void Card::setEffect(std::string value)
{
	this->effect = value;
}

unsigned int Card::getRarity() const
{
	return this->rarity;
}

void Card::setRarity(unsigned int value)
{
	this->rarity = value;;
}

bool Card::operator>(const Card& rhs) const
{
	return this->rarity > rhs.rarity;
}

bool Card::operator<(const Card& rhs) const
{
	return this->rarity < rhs.rarity;
}
