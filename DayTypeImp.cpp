/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017
*/

// Implementation file for DayType class

#include <iostream>
#include <string>

#include "dayType.h"

using namespace std;


string dayType::daysOfWeek[7] = { "Sun", "Mon", "Tue","Wed", "Thu", "Fri","Sat" };
 
void dayType::printDayType() const
{
	cout << dayOfWeek;
}

// **** setters ****
void dayType::setDay(string day)
{
	dayOfWeek = day;
}
// **** getters *****
string dayType::getDay() const
{
	return dayOfWeek;
}

// **** constructors 
// default constructor
// set to "Sun" for day of week 0
dayType::dayType()
{
	dayOfWeek = "Sun";
}

// **** constructor with parameters
// set dayOfWeek as day passed as string 
dayType::dayType(string day)
{
	dayOfWeek = day;
}

//destructor 
dayType::~dayType()
{
}

