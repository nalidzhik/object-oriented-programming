#include "VendingMachine.hpp"
#include "drink.hpp"

VendingMachine::VendingMachine()
{
	this->drinks = new Drink[10]; // At first I gave 10 places for drinks and then the dynamic array will resize one by one by adding more drinks in the machine
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
	if (this != &from)
	{
		drinks = new Drink[from.drinksCount];
		for (size_t i = 0; i < drinksCount; i++)
		{
			this->drinks[i] = from.drinks[i];
		}
		this->drinksCount = from.drinksCount;
		this->moneyInMachine = from.moneyInMachine;
	}
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (this != &from)
	{
		for (size_t i = 0; i < from.drinksCount; i++)
		{
			this->drinks[i] = from.drinks[i];
		}
		this->drinksCount = from.drinksCount;
		this->moneyInMachine = from.moneyInMachine;
	}

	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	for (int i = 0;i < drinksCount;i++)
	{
		if (compare(this->drinks[i].get_name(), to_add.get_name()) == 0)
		{
			return false;
		}
	}

	Drink* resizedDrinks = new Drink[sizeOfVending += 1];

	for (int i = 0;i < drinksCount;i++)
	{
		resizedDrinks[i] = drinks[i];
	}

	delete[] drinks;
	drinks = resizedDrinks;
	sizeOfVending += 1;
	drinks[drinksCount] = to_add;
	this->drinksCount += 1;

	return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	for (int i = 0;i < drinksCount;i++)
	{
		if (compare(this->drinks[i].get_name(), drink_name) == 0 && this->drinks[i].get_price() <= money)
		{
			this->moneyInMachine += money;
			for (int j = i;j < drinksCount - 1;j++)
			{
				drinks[j] = drinks[j + 1];
			}
			drinksCount -= 1;

			return 0;
		}
		if (compare(this->drinks[i].get_name(), drink_name) == 0 && this->drinks[i].get_price() > money)
		{
			this->moneyInMachine += money;
			return 1;
		}
	}
	return 2;
}

double VendingMachine::get_income() const
{
	return this->moneyInMachine;
}

int VendingMachine::compare(const char* p1, const char* p2)
{
	const unsigned char* s1 = (const unsigned char*)p1;
	const unsigned char* s2 = (const unsigned char*)p2;
	unsigned char c1, c2;
	do
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0')
			return c1 - c2;
	} while (c1 == c2);
	return c1 - c2;
}

VendingMachine::~VendingMachine()
{
	delete[] drinks;
}
