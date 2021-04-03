#include "drink.hpp"
#include <cstring>

Drink::Drink()
{
	this->name = NULL;
	this->calories = 0;
	this->quantity = 0;
	this->price = 0;
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) : calories(init_calories), price(init_price), quantity(init_quantity)
{
	int nameLength = strlen(init_name);
	name = new char[nameLength + 1];
	strcpy_s(name, nameLength + 1, init_name);
}

Drink::Drink(const Drink& copyFrom)
{
	int nameLength = strlen(copyFrom.name);
	name = new char[nameLength + 1];
	strcpy_s(name, nameLength + 1, copyFrom.name);
	price = copyFrom.price;
	quantity = copyFrom.quantity;
	calories = copyFrom.calories;
}

Drink::~Drink()
{
	delete[] name;
}

Drink& Drink::operator=(const Drink& rhs)
{
	if (this != &rhs)
	{
		delete[] name;
		int nameLength = strlen(rhs.name);
		name = new char[nameLength + 1];
		strcpy_s(name, nameLength + 1, rhs.name);
		price = rhs.price;
		quantity = rhs.quantity;
		calories = rhs.calories;
	}

	return *this;
}

const char* Drink::get_name() const
{
	return name;
}

int Drink::get_calories() const
{
	return this->calories;
}

double Drink::get_quantity() const
{
	return this->quantity;
}

double Drink::get_price() const
{
	return this->price;
}

void Drink::set_name(const char* new_name)
{
	int nameLength = strlen(new_name);
	if (nameLength > 0)
	{
		delete[] name;
		name = new char[nameLength + 1];
		strcpy_s(name, nameLength + 1, new_name);
	}
}
