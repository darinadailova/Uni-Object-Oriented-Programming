/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Darina Dailova
* @idnumber 62583
* @task 1
* @compiler VC
*/

#include "Date.hpp"
#include <iostream>

Date::Date() : day(1), month(1), year(2000) {
	initializeArray();
}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
	initializeArray();
}

void Date::initializeArray() {
	daysInMonths[0] = 0;

	for (int i = 1; i <= MONTHS_IN_YEAR; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
			daysInMonths[i] = 31;
		}
		if (i == 4 || i == 6 || i == 9 || i == 11) {
			daysInMonths[i] = 30;
		}
	}

	if (isLeapYear()) {
		daysInMonths[2] = 29;
	}
	else {
		daysInMonths[2] = 28;
	}
}

bool Date::isLeapYear() const {
	if (year % 4 != 0) {
		return false;
	}
	else {
		if (year % 100 == 0 && year % 400 != 0) {
			return false;
		}
		else {
			return true;
		}
	}
}

int Date::daysToXmas() {
	int count = 0;

	if (month == 12 && day <= 25) { return 25 - day; }
	// if christmas has already passed this year
	if (month == 12 && day > 25) {
		count += daysToNewYear();
		year++;
		if (isLeapYear()) { count += 366 - 6; }
		else { count += 365 - 6; }
		year--;
		return count;
	}

	for (int i = 1; i <= MONTHS_IN_YEAR; i++) {
		if (i == month) { count += daysInMonths[i] - day; }
		else if (i > month && i != 12) { count += daysInMonths[i]; }
		if (i == 12) { count += 25; }
	}

	return count;
}

int Date::daysToNewYear() {
	int count = 0;
	for (int i = 1; i <= 12; i++) {
		if (month == i) {
			count += daysInMonths[i] - day;
		}
		else if (i > month) {
			count += daysInMonths[i];
		}
	}

	return count;
}

bool Date::isLetterThen(Date& date2) const {
	if (year > date2.year) {
		return false;
	}

	if (year == date2.year) {
		if (month > date2.month) {
			return false;
		}
		else if (month == date2.month) {
			if (day >= date2.day) {
				return false;
			}
			else {
				return true;
			}
		}
	}

	return true;
}

void Date::addDays(int n) {
	while (daysToNewYear() < n) {
		n -= daysToNewYear();
		year++;
		day = 1;
		month = 1;
	}

	for (int i = 0; i < n; i++) {
		if (day < daysInMonths[month]) {
			day++;
		}
		else {
			day = 1;
			month++;
		}
	}

}

void Date::removeDays(int n) {
	while (passedDaysSinceTheStartOfYear() <= n) {
		n -= passedDaysSinceTheStartOfYear();
		year--;
		day = 31;
		month = 12;
	}

	for (int i = 0; i < n; i++) {
		if (day == 1) {
			month--;
			day = daysInMonths[month];
		}
		else {
			day--;
		}
	}

}


int Date::passedDaysSinceTheStartOfYear() {
	int count = 0;
	for (int i = month; i > 0; i--) {
		if (i == month) {
			count += day;
		}
		else {
			count += daysInMonths[i];
		}
	}

	return count;
}

int Date::daysToEvent(Date& date2) {
	int count = 0;
	int yearCopy = year;
	int monthCopy = month;
	int dayCopy = day;

	while (year != date2.year) {
		count += daysToNewYear();
		day = 1;
		month = 1;
		year++;
	}

	if (isLeapYear()) { 
		daysInMonths[2] = 29; 
	}
	else {
		daysInMonths[2] = 28;
	}

	for (int i = 1; i < date2.month; i++) {
		count += daysInMonths[i];
	}
	count += date2.day;
	year = yearCopy;
	month = monthCopy;
	day = dayCopy;

	return count;
}

void Date::printDate() const {
	if (day < 10) { std::cout << '0' << day; }
	else { std::cout << day; }

	if (month < 10) { std::cout << ".0" << month; }
	else { std::cout << '.' << month; }

	std::cout << '.' << year << '\n';
}