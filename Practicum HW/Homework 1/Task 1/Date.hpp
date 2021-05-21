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

#pragma once

class Date {
	int day;
	int month;
	int year;
	const int MONTHS_IN_YEAR = 12;
	// contains how many days each month has depending of the year (leap or no)
	int daysInMonths[13];
public:
	// Constructors
	Date();
	Date(int day, int month, int year);

	// Methods
	void initializeArray();
	bool isLeapYear() const;
	int daysToXmas();
	int daysToNewYear();
	bool isLetterThen(Date& date2) const;
	void addDays(int n);
	void removeDays(int n);
	int passedDaysSinceTheStartOfYear();
	int daysToEvent(Date& date2);
	void printDate() const;
};