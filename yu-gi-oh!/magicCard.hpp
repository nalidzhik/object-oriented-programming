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

enum MagicCardType {
	trap,
	buff,
	spell
};

class MagicCard
{
	char* name;
	char* effect;
	MagicCardType type;

public:
	MagicCard();
	MagicCard(const char*, const char*, MagicCardType);
	MagicCard& operator=(const MagicCard& other);
	MagicCard(const MagicCard& other);
	~MagicCard();
	const char* getName() const;
	void setName(const char*);
	const char* getEffect() const;
	void setEffect(const char*);
	MagicCardType getType() const;
	void setType(const MagicCardType);
};
