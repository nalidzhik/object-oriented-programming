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
#pragma once
#include"monsterCard.hpp"
#include"magicCard.hpp"
#include<string>

class PendulumCard : public MonsterCard, public MagicCard
{
	unsigned int pendulumScale;

public:
	PendulumCard() = default;
	PendulumCard(std::string, std::string, unsigned int, unsigned int, unsigned int, unsigned int, CardType);

	unsigned int getPendulumScale() const;
	void setPendulumScales(unsigned int);

	friend std::ostream& operator<<(std::ostream&, const PendulumCard&);
	friend std::istream& operator>>(std::istream&, PendulumCard&);

	Card* clone() const;
};