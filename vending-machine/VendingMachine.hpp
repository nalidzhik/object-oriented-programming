#pragma once
#include "drink.hpp"

class VendingMachine {

public:

	VendingMachine();
	VendingMachine(const VendingMachine& from);
	VendingMachine& operator=(const VendingMachine& from);

	bool add_drink(const Drink& to_add);
	int buy_drink(const char* drink_name, const double money);

	double get_income() const;
	int compare(const char*, const char*);

	~VendingMachine();

private:

	Drink* drinks;
	int drinksCount = 0;
	double moneyInMachine = 0.0;
	int sizeOfVending = 0;
};