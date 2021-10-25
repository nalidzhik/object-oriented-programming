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
#include<string>

enum CardType {
	trap,
	buff,
	spell
};

class MagicCard
{
private:
	std::string name;
	std::string effect;
	CardType type;

public:
	MagicCard();
	MagicCard(const std::string, const std::string, CardType);
	MagicCard& operator=(const MagicCard& other);
	MagicCard(const MagicCard& other);
	const std::string getName() const;
	void setName(const std::string);
	const std::string getEffect() const;
	void setEffect(const std::string);
	CardType getType() const;
	void setType(const CardType);

	friend std::ostream& operator<<(std::ostream&, const MagicCard&);
	friend std::istream& operator>>(std::istream&, MagicCard&);
};