#include<iostream>
#include "drink.hpp"
#include "VendingMachine.hpp"

using namespace std;

int main()
{
	Drink cola("cola", 2.5, 32, 1.2);
	Drink fanta("fanta", 1.0, 36, 1.2);
	Drink cola1("cola", 4.0, 320, 3.8);
	Drink sprite("sprite", 2.3, 32, 1.0);

	VendingMachine e;

	cout << "Day 1" << endl;

	cout << "Add cola: " << e.add_drink(cola) << endl;
	cout << "Try to add another cola " << e.add_drink(cola1) << endl;
	cout << "Add sprite: " << e.add_drink(sprite) << endl;
	cout << "Add fanta: " << e.add_drink(fanta) << endl;
	cout << "Buy drink fanta:";
	cout << e.buy_drink("fanta", 8.4) << endl;
	cout << "Buy drink tea:";
	cout << e.buy_drink("tea", 1.4) << endl;
	cout << "Money in the vending machine now: " << e.get_income() << endl;
	cout << endl;

	cout << "Day 2" << endl;

	Drink coffee("coffee", 0.25, 23, 1.5);
	Drink milkShake("milkShake", 1.0, 678, 8.9);
	Drink honeyMilkShake("honeyMilkShake", 1.3, 789, 9.7);
	Drink juice("juice", 2.3, 329, 2.8);
	Drink coffeee("coffee", 1.3, 90, 0.9);

	cout << "Add coffee: " << e.add_drink(coffee) << endl;
	cout << "Try to add another coffee: " << e.add_drink(coffeee) << endl;
	cout << "Add milkShake: " << e.add_drink(milkShake) << endl;
	cout << "Add honeyMilkShake: " << e.add_drink(honeyMilkShake) << endl;
	cout << "Add juice: " << e.add_drink(juice) << endl;
	cout << "Buy drink milkShake:";
	cout << e.buy_drink("milkShake", 9) << endl;
	cout << "Buy drink honeyMilkShake:";
	cout << e.buy_drink("honeyMilkShake", 1.4) << endl;
	cout << "Buy drink milkShake:";
	cout << e.buy_drink("milkShake", 10) << endl;
	cout << "Money in the vending machine now: " << e.get_income() << endl;
	cout << endl;

	cout << "Day 3" << endl;

	cout << "Money in the vending machine now: " << e.get_income() << endl;

	Drink pepsi("pepsi", 0.25, 23, 1.5);
	Drink water("water", 1.0, 678, 0.8);
	Drink chocolateMilk("chocolateMilk", 1.3, 789, 9.7);

	cout << "Add pepsi: " << e.add_drink(pepsi) << endl;
	cout << "Try to add another coffee: " << e.add_drink(coffeee) << endl;
	cout << "Add water: " << e.add_drink(water) << endl;
	cout << "Add chocolateMilk: " << e.add_drink(chocolateMilk) << endl;
	cout << "Buy drink water:";
	cout << e.buy_drink("water", 9) << endl;
	cout << "Buy drink chocolateMilk:";
	cout << e.buy_drink("chocolateMilk", 1.4) << endl;
	cout << "Buy drink milkShake:";
	cout << e.buy_drink("milkShake", 10) << endl;

	cout << "Money in the vending machine now: " << e.get_income() << endl;
	cout << endl;

	return 0;
}