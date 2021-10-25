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
#include "Card.hpp"
#include<string>

class MonsterCard :virtual public Card
{
protected:
	unsigned int attackingPoints;
	unsigned int protectivePoints;

public:
	MonsterCard(std::string name = "", std::string effect = "", unsigned int rarity = 0, unsigned int attackingPoints = 0, unsigned int protectivePoints = 0);
	MonsterCard& operator=(const MonsterCard& other);
	MonsterCard(const MonsterCard& other);
	unsigned int getAttackingPoints() const;
	void setAttackingPoints(unsigned int);
	unsigned int getProtectivePoints() const;
	void setProtectivePoints(unsigned int);

	Card* clone() const;

	friend std::ostream& operator<<(std::ostream&, const MonsterCard&);
	friend std::istream& operator>>(std::istream&, MonsterCard&);

};