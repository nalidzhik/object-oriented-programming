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
#pragma once
#include"monsterCard.hpp"
#include"magicCard.hpp"
#include<string>

class PendulumCard : virtual public MonsterCard, virtual public MagicCard
{
	unsigned int pendulumScale;

public:
	PendulumCard() = default;
	PendulumCard(const std::string, const std::string, unsigned int, unsigned int, unsigned int, CardType);

	unsigned int getPendulumScale() const;
	void setPendulumScales(unsigned int);

	friend std::ostream& operator<<(std::ostream&, const PendulumCard&);
	friend std::istream& operator>>(std::istream&, PendulumCard&);
};