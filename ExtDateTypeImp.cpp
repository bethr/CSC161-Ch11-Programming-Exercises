/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017
*/

// Implementation file for ExtDateType class

#include <iostream>
#include <string>
#include "DateType.h"
#include "ExtDateType.h"

using namespace std;

string extDateType::longStringMonths[] = { "January", "February", "March", "April", "May", "June",
							"July", "August", "September", "October", "November", "December" };

void extDateType::printLongDate()
{
	cout << extendedMonth << " " << getDay() << ", " << getYear();
}

// print in "Month YYYY" format
void extDateType::printLongMonthYear()
{
	cout << "     " << extendedMonth << " " << getYear();
}


void extDateType::setDate(int month, int day, int year)
{
	DateType::setDate(month, day, year);

	extendedMonth = longStringMonths[month - 1];
}

void extDateType::setMonth(int month)
{
	DateType::setMonth(month);
	extendedMonth = longStringMonths[month - 1];
}


// default constructor
extDateType::extDateType()
{
	extendedMonth = "January";
}

// constructor with parameters
extDateType::extDateType(int month, int day, int year)
	: DateType(month, day, year)
{
	extendedMonth = longStringMonths[month - 1];
}

//destructor 
extDateType::~extDateType()
{
}


