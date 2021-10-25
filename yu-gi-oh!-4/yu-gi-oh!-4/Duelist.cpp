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
#include "Duelist.hpp"
#include <iostream>
#include<fstream>

Duelist::Duelist(const std::string name)
{
	this->name = name;
}

Duelist& Duelist::operator=(const Duelist& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->deck = rhs.deck;
	}

	return *this;
}

Duelist::Duelist(const Duelist& other)
{
	this->name = other.name;
	this->deck = other.deck;
}

const std::string Duelist::getName() const
{
	return this->name;
}

void Duelist::setName(const std::string value)
{
	this->name = value;
}

Deck& Duelist::getDeck() const
{
	Deck* deckPtr = (Deck*)&deck;
	return *deckPtr;
}

bool Duelist::saveDeck(const char* filename) const
{
	std::ofstream outFile(filename);
	if (!outFile.is_open())
	{
		return false;
	}
	outFile << getDeck();
	if (outFile.fail())
	{
		outFile.close();
		return false;
	}
	return true;
}

bool Duelist::loadDeck(const char* filename) const
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		return false;
	}
	else
	{
		inFile >> getDeck();
		inFile.close();
		return true;
	}
	return false;
}

void Duelist::duel(Duelist& playerTwo)
{
	int pointsOfTheCurrentPlayer = 0;
	int pointsOfPlayerTwo = 0;
	if (deck.getCardsCount() != playerTwo.deck.getCardsCount())
	{
		std::cout << "Cards count of players in deck are not equal! The duel cannot be conducted! ";
		return;
	}
	deck.shuffle();
	playerTwo.deck.shuffle();
	for (int i = 0; i < deck.getCardsCount(); i++)
	{
		if (*deck.getCards().at(i) > *playerTwo.deck.getCards().at(i))
		{
			pointsOfTheCurrentPlayer += 1;
		}
		else if (*deck.getCards().at(i) < *playerTwo.deck.getCards().at(i))
		{
			pointsOfPlayerTwo += 1;
		}
	}
	if (pointsOfPlayerTwo > pointsOfTheCurrentPlayer)
	{
		std::cout << playerTwo.name << " won the duel!";
	}
	else if (pointsOfPlayerTwo == pointsOfTheCurrentPlayer)
	{
		std::cout << "The duel finished with equality!";
	}
	else
	{
		std::cout << this->name << " won the duel!";
	}
}

std::istream& operator>>(std::istream& in, Duelist& d)
{
	char discard;
	in >> d.name >> discard >> d.deck;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Duelist& d)
{
	out << d.name << d.deck << '\n';

	return out;
}

