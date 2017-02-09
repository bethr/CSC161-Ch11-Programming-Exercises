/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017

Class for saving the numerical month, day, and year for a specific date
*/
// Header file for DateType
#ifndef DateType_H
#define DateType_H
#include <string>
using namespace std;
class DateType {
public:

	DateType();    
	               
	//DateType(int month = 1, int day = 1, int year = 1900); 
	//Constructor to set the date
	//The member variables dMonth, dDay, and dYear are set
	//according to the parameters.
	//Postcondition: dMonth = month; dDay = day; dYear = year; 
	//                        If no values are specified, the default
	//                        values are used to initialize the member 
	//                        variables.

	 DateType(int month, int day, int year);

	~DateType();
	//destructors 
	// no input, no output

	/**************** setters ************************/

	void setMonth(int) ;
	void setDay(int) ;
	void setYear(int) ;
	
	void setDate(int month, int day, int year);
	//Function to set the date.
	//The member variables dMonth, dDay, and dYear are set
	//according to the parameters.
	//Postcondition: dMonth = month; dDay = day;
	//               dYear = year

	/**************** getters ************************/

	int getDay() const;
	//Function to return the day.
	//Postcondition: The value of dDay is returned.

	int getMonth() const;
	//Function to return the month.
	//Postcondition: The value of dMonth is returned.

	int getYear() const;
	//Function to return the year.
	//Postcondition: The value of dYear is returned.


	//********* other  functions *********

	
	void printDate() const;
	//Function to output the date
	//print out the date information in a nice format 
	//form mm-dd-yyyy. 


	bool isLeapYear(int) const;
	//check for leap year

	int numberDaysInMonth(int, int) const;
	//determine how many days in the month

	int numberDaysPassedInYear() const;
	//determine how many days of the year have passed

	int numberDaysRemainingInYear() const; 
	//determine how many days remaining in the year

	void incrementDateByNumberDays(int);
	//calculate new date by adding specific number of days


private:
	int dMonth; 
	//variable to store the month

	int dDay;   
	//variable to store the day

	int dYear; 
	//variable to store the year


};
#endif
