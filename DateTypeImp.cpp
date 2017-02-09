/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017
*/

// Implementation file for DateType class

#include <iostream>
#include <iomanip>
#include "DateType.h"
using namespace std;


// default constructor, just initialize members to valid values

DateType::DateType()
{
	//variable to store the month
	dMonth = 1;   
	//variable to store the day
	dDay = 1;     
	//variable to store the year
	dYear = 1500; 
	

}

//Constructor with parameters
DateType::DateType(int month, int day, int year)
{ 
	//variable to store the month
	dMonth = month;  
	//variable to store the day
	dDay = day;     
	//variable to store the year
	dYear = year;  
	

}

//destructor 
DateType::~DateType()
{
}

// ******** setters *******
// only set new date if all numerical values valid 
void DateType::setDate(int month, int day, int year)
{
	if ((month > 0 && month < 13) && (day > 0 && day << 32) && (year > 1499 && year < 2018))
	{
		setMonth(month);
		setDay(day);
		setYear(year);
	}
}
void DateType::setDay(int day) 
{
	dDay = day;
}
void DateType::setMonth(int month) 
{
	dMonth = month;
}
void DateType::setYear(int year) 
{
	dYear = year;
}

// ***** getters ******

int DateType::getDay() const
{
	return dDay;
}
int DateType::getMonth() const
{
	return dMonth;
}
int DateType::getYear() const
{
	return dYear;
}


// ********* other member functions *******

//output the formatted date to the screen
void DateType::printDate() const
{
	cout << dMonth << "-" << dDay << "-" << dYear;
}

//determine from input year if this is a leap year
bool DateType::isLeapYear(int year) const
{
	if ((year % 4 == 0) && (year / 4 != 0))
		return true;
	else
		return false; 
}

//determine how many days in the month
int DateType::numberDaysInMonth(int month, int year) const
{
	if ((month == 9) || (month == 4) || (month == 6) || (month == 11))
	{
		return 30;
	}
	else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
	{
		return 31;
	}
	else 
	{
		bool leapYear = isLeapYear(year);
		if (leapYear) return 29;
		else return 28;
	}
}

//determine how many days of the year have passed
int DateType::numberDaysPassedInYear() const
{
	int i;
	int daysPassedInYear = 0; 
	for (i = getMonth()-1; i > 0; i-- )
	{
		daysPassedInYear += numberDaysInMonth(i, getYear()); 
	}
	// add days in this month that have already passed 
	daysPassedInYear += getDay(); 
	return daysPassedInYear; 
}


//determine how many days remaining in the year
int DateType::numberDaysRemainingInYear() const
{
	int i;
	int daysLeftInYear = 0; 
	for (i = getMonth(); i < 13; i++)
	{
		daysLeftInYear += numberDaysInMonth(i, getYear());
	}
	// subtract the days in this month that have already passed
	daysLeftInYear -= getDay();
	return daysLeftInYear;
}


//calculate new date by adding specific number of days
void DateType::incrementDateByNumberDays(int days)
{
	int currentYear = getYear();
	int currentMonth = getMonth();
	int currentDay = getDay();

	do
	{
		int i = numberDaysInMonth(currentMonth, currentYear);

		if (days <= i - currentDay) // less than difference between today and the end of the month? 
		{
			currentDay += days;
			days = 0;
		}
		else if (days <= numberDaysRemainingInYear())
		{
			days -= (i - currentDay +1);  // subtract the days of 1 month, or the remaining value of today from the end of this month
			currentDay = 1;
			currentMonth += 1; 

		}
		else
		{
			int j = (numberDaysRemainingInYear() + 1);
			days -= j; 
			currentDay = 1; 
			currentMonth = 1; 
			currentYear += 1; 
		}

	} while (days > 0); 

	// update object with new date 
	setDate(currentMonth, currentDay, currentYear); 

}

