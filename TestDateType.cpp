/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017

This program:
1) Uses class dateType to facilitate manipulation of dates.
2) Tests member function setDate of class dateType to validate dates before storing in member variables.
3) Tests member function isLeapYear of class dateType to check whether year is leap year. 
4) Tests member function numberDaysInMonth of class dateType to return number of days in month.
5) Tests member function numberDaysPassedInYear of class dateType to return number of days passed in year.
6) Tests member function numberDaysRemainingInYear of class dateType to return number of days remaining in year.
7) Tests member function incrementDateByNumberDays of clas dateType to calculate a new date by incrementing a specific number of days.
8) Uses class extDateType to store the month in string form ??? member function
9) Uses class dayType to store the first day of the month in string form, (i.e. Mon, Tue, Wed, etc.) 
10) Uses class calendarType and tests member function printCalendar to print a calendar for any month starting January 1, 1500. 

*/

// Test file for DateType class 
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
#include "DateType.h"
#include "dayType.h"
#include "extDateType.h"
#include "calendarType.h"
using namespace std;



int main()
{
	// DateType dateType;
	// DateType();
	// DateType dateType(1, 1, 1500);
	// dateType.printDate();

	int inputMonth = 1;                           
	int inputDay = 1;                             
	int inputYear = 1500;                            

	extDateType extDateType(inputMonth, inputDay, inputYear);
	


	// initialize placeholders for input 
	string inputString = "";
	string inputString2 = "";
	int inputInteger = 0;
	int inputInteger2 = 0;


	// output the default constructor data to the screen 
	// demonstrate default constructor
	cout << "Demonstrate creation of object by default constructor with parameters." << endl;

	//output the contents of dateType to the screen 
	cout << "\nPrint as numeric date:" << endl;
	extDateType.printDate();

	//output the contents of dateType to the screen 
	cout << "\n\nPrint as long format date: " << endl;
	extDateType.printLongDate();
	cout << endl;

	// solicit user to input a new date to test the input of 
	// dates validation 

	cout << "\n\nDemonstrate setDate with parameters input validation...";
	
	do {
		cout << "\nPlease enter new month (1-12): ";
		cin >> inputMonth;

		cout << "Please enter new day (1-31): ";
		cin >> inputDay;

		cout << "Please enter new year (1500-current): ";
		cin >> inputYear;

		//set all input information into object
		extDateType.setDate(inputMonth, inputDay, inputYear);

		cout << "\nDate only updates if all fields pass validation (done in DateTypeImp) " << endl;

		// output the formatted date to the screen 
		cout << "    Current date is set to : ";
		extDateType.printDate();


		// demonstrate test for leap year. 
		bool isLeapYear = extDateType.isLeapYear(inputYear);  		
		if (isLeapYear) cout << "\n\nIt's leap year!!" << endl;
		else cout << "\n\nIt's not leap year. :( " << endl;

		// demonstrate test of other functions
		cout << "\nnumberDaysInMonth: " << extDateType.numberDaysInMonth(extDateType.getMonth(), extDateType.getYear());
		cout << "\nnumberDaysPassedInYear: " << extDateType.numberDaysPassedInYear();
		cout << "\nnumberDaysRemainingInYear: " << extDateType.numberDaysRemainingInYear() << endl;


		// int numberDaysInMonth = 0; 

		// ask user how many days to increment the date
		do {
			cout << "\nPlease enter number of days to increment date: " << endl;
			cin >> inputInteger2;

			extDateType.incrementDateByNumberDays(inputInteger2);
			extDateType.printDate();

			cout << "\nIncrement again? (y/n): ";
			cin >> inputString2;
		} while (inputString2 == "y");

		cout << "\nDemonstrate calendar:" << endl; 
		//test calendar object
		calendarType cal(extDateType.getMonth(), extDateType.getYear());
		cal.printCalendar();

		cout << "\nChange date again? (y/n): ";
		cin >> inputString;
	} while (inputString == "y");

	
	return 0;
}