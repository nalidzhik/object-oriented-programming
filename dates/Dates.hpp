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

class Date
{
private:

	int day;
	int month;
	int year;

public:

	Date();
	Date(int, int, int);

	~Date() {}

	void addDays(int n);
	void removeDays(int n);
	bool isLeapYear();
	int daysToXmas();
	int daysToNewYear();
	int daysToHoliday(Date date);
	bool isLaterThen(Date date);

	void setDays(int);
	int getDays() const;
	void setMonths(int);
	int getMonths() const;
	void setYears(int);
	int getYears() const;
	void print() const;
};