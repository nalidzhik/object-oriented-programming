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
#include "Dates.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Date::Date() : Date(1, 1, 2000)
{
}

Date::Date(int d, int m, int y)
{

	setDays(d);
	setMonths(m);
	setYears(y);

}

void Date::addDays(int n)
{
	int MaxDayInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int nMaxDays(MaxDayInMonth[month] + (month == 2 && isLeapYear() ? 1 : 0));
	int nYear(year);
	int nMonth(month);
	int nDays(day + n);

	while (nDays > nMaxDays)
	{
		nDays -= nMaxDays;
		++nMonth;

		if (nMonth > 12) {
			nMonth = 1;
			++nYear;
		}

		nMaxDays = MaxDayInMonth[nMonth] + (nMonth == 2 && isLeapYear() ? 1 : 0);
	}

	this->day = nDays;
	this->month = nMonth;
	this->year = nYear;
}


void Date::removeDays(int n)
{
	int MaxDayInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int nYear(year);
	int nMonth(month);
	int nDays(day + n);

	if (0 < (day - n))
	{
		this->day = day - n;
		this->month = nMonth;
		this->year = nYear;
	}
	else
	{
		int nDays(n);
		nDays -= day;
		int nMonth(month - 1);
		if (nMonth < 1) {
			nMonth = 12; // December
			--nYear;     // Previous year
		}

		int nDaysInMonth = MaxDayInMonth[nMonth] + (nMonth == 2 && isLeapYear() ? 1 : 0);

		while (nDays >= 0)
		{
			nDays -= nDaysInMonth;
			if (nDays > 0)
			{
				--nMonth;
				if (nMonth < 1)
				{
					nMonth = 12;
					--nYear;
				}
			}

			nDaysInMonth = MaxDayInMonth[nMonth] + (nMonth == 2 && isLeapYear() ? 1 : 0);
		}

		this->day = (0 < nDays ? nDays : -nDays);
		this->month = nMonth;
		this->year = nYear;
	}
}

bool Date::isLeapYear()
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

int Date::daysToXmas()
{
	int MaxDayInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int xMasDay = 25;
	int months(month);
	int days(day);

	int zeroStarterMonth = months - 1;
	if (zeroStarterMonth < 11)
	{
		if (day <= MaxDayInMonth[zeroStarterMonth])
		{
			int daysSummation = abs(day - MaxDayInMonth[zeroStarterMonth]);

			for (int i = zeroStarterMonth + 1; i < 11; i++)
			{
				daysSummation += MaxDayInMonth[i];
			}

			daysSummation = daysSummation + xMasDay;
			return daysSummation;
		}

	}
	else if (zeroStarterMonth == 11)
	{

		if (day <= MaxDayInMonth[zeroStarterMonth])
		{
			if (day <= xMasDay)
			{
				return xMasDay - day;
			}
			else
			{
				int daySummation = abs(day - MaxDayInMonth[zeroStarterMonth]);
				for (int i = 0; i < 11; i++)
				{
					daySummation += MaxDayInMonth[i];
				}
				daySummation += xMasDay;
				return daySummation;
			}
		}
	}
}

int Date::daysToNewYear()
{
	int MaxDayInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int newYearEve = 32; // 31 + 1 (01.01.....) add first January as day
	int months(month);
	int days(day);

	int zeroStarterMonth = months - 1;
	if (zeroStarterMonth < 11)
	{
		if (day <= MaxDayInMonth[zeroStarterMonth])
		{
			int daysSummation = abs(day - MaxDayInMonth[zeroStarterMonth]);

			for (int i = zeroStarterMonth + 1; i < 11; i++)
			{
				daysSummation += MaxDayInMonth[i];
			}

			daysSummation = daysSummation + newYearEve;
			return daysSummation;
		}

	}
	else if (zeroStarterMonth == 11)
	{

		if (day <= MaxDayInMonth[zeroStarterMonth])
		{
			if (day <= newYearEve)
			{
				return newYearEve - day;
			}
			else
			{
				int daySummation = abs(day - MaxDayInMonth[zeroStarterMonth]);
				for (int i = 0; i < 11; i++)
				{
					daySummation += MaxDayInMonth[i];
				}
				daySummation += newYearEve;
				return daySummation;
			}
		}
	}
}

int Date::daysToHoliday(Date date)
{
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int currentYear(year);
	int currentMonth(month);
	int CurrentDay(day);

	int years = date.getYears();
	int months = date.getMonths();
	int days = date.getDays();

	long int n1 = years * 365 + days;
	for (int i = 0; i < months - 1; i++)
		n1 += monthDays[i];

	n1 += isLeapYear();

	long int n2 = currentYear * 365 + CurrentDay;
	for (int i = 0; i < currentMonth - 1; i++)
		n2 += monthDays[i];
	n2 += isLeapYear();

	return abs(n2 - n1);
}

bool Date::isLaterThen(Date date)
{
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int currentYear(year);
	int currentMonth(month);
	int CurrentDay(day);

	int years = date.getYears();
	int months = date.getMonths();
	int days = date.getDays();

	long int n1 = years * 365 + days;
	for (int i = 0; i < months - 1; i++)
		n1 += monthDays[i];

	n1 += isLeapYear();

	long int n2 = currentYear * 365 + CurrentDay;
	for (int i = 0; i < currentMonth - 1; i++)
		n2 += monthDays[i];
	n2 += isLeapYear();

	if (n1 > n2)
	{
		return true;
	}
	return false;

}

void Date::setDays(int d)
{
	if (d >= 1 && d <= 31)
	{
		this->day = d;
	}
}

int Date::getDays() const
{
	return day;
}

void Date::setMonths(int m)
{
	if (m >= 1 && m <= 12)
	{
		this->month = m;
	}
}

int Date::getMonths() const
{
	return month;
}

void Date::setYears(int y)
{
	this->year = y;
}

int Date::getYears() const
{
	return year;
}

void Date::print() const
{
	cout << setfill('0') << setw(2) << getDays() << '.' << setw(2) << getMonths() << '.' << setw(4) << getYears();
}
