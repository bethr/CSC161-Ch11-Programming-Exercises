/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017
*/

// Implementation file for calendarType class

#include <iomanip>
#include "calendarType.h"

//defaults constructor to January 1500
calendarType::calendarType()
{
	setMonth(1);
	setYear(1500);
}

//constructor with parameters
calendarType::calendarType(int month, int year)
{
	setMonth(month);
	setYear(year);
}

//destructor
calendarType::~calendarType()
{
}

//******* setters ********
void calendarType::setMonth(int month)
{
	extDateForCalendar.setMonth(month);
}

void calendarType::setYear(int year)
{
	extDateForCalendar.setYear(year);
}

//********* getters *******
int calendarType::getMonth()
{
	return extDateForCalendar.getMonth();
}

int calendarType::getYear()
{
	return extDateForCalendar.getYear();
}

//******** other functions ******

void calendarType::printCalendar()
{
	// build calendar heading
	// output ex.  "December 2017" 
	cout << "\n";
	extDateForCalendar.printLongMonthYear();
	cout << "\n\n ";

	//build output line with days of the week 
	// output ex. "Sun Mon Tue Wed Thu Fri Sat"
	// dayType day = firstDayOfMonth();
	int day = firstDayOfMonth();
	int i; 
	for (i = 0; i < 8; i++)
	{
		cout << setw(7) << FirstDayOfMonth.daysOfWeek[i];
	}
	cout << "\n";

	//find starting day of week for month and pad calendar
	//with blanks before first day 
	int j = 0;
	i = 0; 

	//check if this is our first starting day of month
	//find starting day for numerical display of days 
	//while ((day.getDay() != firstDay.daysOfWeek[i]))
	while (day != i)
	{
		j++; i++; 
		cout << setw(7) << " ";
	}

	//starting with day 1, build numerical display of days of month
	i = 1; 
	while (i < extDateForCalendar.numberDaysInMonth(getMonth(), getYear())+1)
		{
			//build each week 
			while ((j < 7) && i < (extDateForCalendar.numberDaysInMonth(getMonth(), getYear())+1))
			{
				cout << setw(7) << i; 
				i++; j++; 
			}
			j = 0; 
			cout << "\n";
		}
	
	cout << "\n\n";

}

// find starting day of week using Tomohiko Sakamoto's algorithm 
// i = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
// returns 0 = Sunday, 1 = Monday, etc. 
// also store string day of week in dayType object 
//
int calendarType::firstDayOfMonth()
{
	dayType day;
	int i;
	int y = getYear();
 
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= getMonth() < 3;
	i = (y + y / 4 - y / 100 + y / 400 + t[getMonth() - 1] + 1) % 7;
	
	//store 
	day.setDay(FirstDayOfMonth.daysOfWeek[i]);
	 
	return i;
}

