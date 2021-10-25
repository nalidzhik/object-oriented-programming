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
#include "Deck.hpp"
#include <iostream>

class Duelist
{
private:
	std::string name;
	Deck deck;

public:
	Duelist() = default;
	Duelist(const std::string);
	Duelist& operator=(const Duelist&);
	Duelist(const Duelist&);
	const std::string getName() const;
	void setName(const std::string);
	Deck& getDeck() const;
	bool saveDeck(const char*) const;
	bool loadDeck(const char*) const;
	void duel(Duelist&);

	friend std::istream& operator>>(std::istream&, Duelist&);
	friend std::ostream& operator<<(std::ostream&, const Duelist&);
};

static void duel(Duelist& playerOne, Duelist& playerTwo)
{
	playerOne.duel(playerTwo);
}