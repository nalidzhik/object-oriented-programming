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
#include <string>

class Card
{
protected:
	std::string name;
	std::string effect;
	unsigned int rarity;

public:
	Card(const std::string name = "", const std::string effect = "", unsigned int rarity = 0);

	const std::string getName() const;
	void setName(std::string);
	const std::string getEffect() const;
	void setEffect(std::string);
	unsigned int getRarity() const;
	void setRarity(unsigned int);

	bool operator>(const Card& rhs) const;
	bool operator<(const Card& rhs) const;

	virtual Card* clone() const = 0;

};