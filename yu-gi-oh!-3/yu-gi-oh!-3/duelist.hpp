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
#include "deck.hpp"
#include<iostream>

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

	friend std::istream& operator>>(std::istream&, Duelist&);
	friend std::ostream& operator<<(std::ostream&, const Duelist&);
};