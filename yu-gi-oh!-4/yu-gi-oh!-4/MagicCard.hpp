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

enum CardType {
	TRAP,
	BUFF,
	SPELL,
	DEFAULT
};

class MagicCard :virtual public Card
{
protected:
	CardType type;

public:
	MagicCard(std::string name = "", std::string effect = "", unsigned int rarity = 0, CardType type = DEFAULT);
	MagicCard& operator=(const MagicCard& other);
	MagicCard(const MagicCard& other);
	CardType getType() const;
	void setType(const CardType);

	friend std::ostream& operator<<(std::ostream&, const MagicCard&);
	friend std::istream& operator>>(std::istream&, MagicCard&);

	Card* clone() const;
};

std::ostream& operator<<(std::ostream&, const CardType&);
std::istream& operator>>(std::istream&, CardType&);