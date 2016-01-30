#include < math.h >
#include < stdlib.h >

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int max(int a, int b)
{
	if (a>b) return(a); else return (b);
}

int min(int a, int b)
{
	if (a>b) return(b); else return (a);
}

class Date
{
public:
	Date();
	Date(int mn, int day, int yr);  // constructor
	void display();                   // function to display date
	int GetMonth();
	void SetMonth(int mn);
	~Date();
private:
	int month, day, year;
	int DaysSoFar();
};

// constructor definition
Date::Date()
{
	month = day = year = 1;
}

Date::Date(int mn, int dy, int yr)
{
	static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	month = max(1, mn);
	month = min(month, 12);

	day = max(1, dy);
	day = min(day, length[month]);

	year = max(1, yr);
}

void Date::display()
{
	static char *name[] = { "nothing", "January", "February", "March", "April",
		"May", "June", "July", "August", "September", "October",
		"November", "December" };

	cout << "\n" << name[month] << " " << day << "," << year << '\n';
	cout << "Days so far: " << DaysSoFar() << '\n';
}

Date::~Date()
{
	cout << "Thank You for using DateLine Services and have a nice date!\n";
}

int Date::DaysSoFar()
{
	int total = 0;
	static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 1; i < month; i++) total += length[i];
	total += day;
	return (total);
}

int Date::GetMonth()
{
	return month;
}

void Date::SetMonth(int mn)
{
	month = max(1, mn);
	month = min(month, 12);
}