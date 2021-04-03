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
#include <iostream>
#include "Dates.hpp"

using namespace std;

int main()
{

	Date d1;
	d1.print();
	cout << endl;

	Date d2 = Date(31, 3, 2014);
	d2.print();
	Date d3 = Date(31, 8, 2019);
	cout << endl;
	cout << "result" << " " << d3.isLeapYear();
	cout << endl;
	cout << d3.daysToXmas() << endl;
	cout << d2.isLaterThen(d3) << endl;
	cout << d2.daysToHoliday(d3) << endl;
	d2.addDays(1);
	d2.print();
	cout << endl;
	d3.removeDays(45);
	d3.print();

	return 0;
}
