/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Nazife Alidzhik
* @idnumber 62598
* @task 2
* @compiler VC
*/
#pragma once

class MonsterCard
{
private:
	char* name;
	int attackingPoints;
	int protectivePoints;

public:
	MonsterCard();
	MonsterCard(const char*, int, int);
	MonsterCard& operator=(const MonsterCard& other);
	MonsterCard(const MonsterCard& other);
	~MonsterCard();
	const char* getName() const;
	void setName(const char*);
	int getAttackingPoints() const;
	void setAttackingPoints(int);
	int getProtectivePoints() const;
	void setProtectivePoints(int);
};
