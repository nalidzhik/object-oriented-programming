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

class MonsterCard
{
private:
	std::string name;
	std::string effect;
	unsigned int attackingPoints;
	unsigned int protectivePoints;

public:
	MonsterCard();
	MonsterCard(const std::string, const std::string, unsigned int, unsigned int);
	MonsterCard& operator=(const MonsterCard& other);
	MonsterCard(const MonsterCard& other);
	const std::string getName() const;
	void setName(std::string);
	const std::string getEffect() const;
	void setEffect(std::string);
	unsigned int getAttackingPoints() const;
	void setAttackingPoints(unsigned int);
	unsigned int getProtectivePoints() const;
	void setProtectivePoints(unsigned int);

	friend std::ostream& operator<<(std::ostream&, const MonsterCard&);
	friend std::istream& operator>>(std::istream&, MonsterCard&);
};