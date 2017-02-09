/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017

This class creates and prints calendar for any year starting January 1500. 
*/
// Header file for CalendarType

#ifndef CalendarType_h
#define CalendarType_h

#include "DateType.h"
#include "ExtDateType.h"
#include "dayType.h"
#include <iostream>

class calendarType
{
public:

	//****  setters ****
	void setMonth(int);
	void setYear(int);

	//***** getters *****
	int getMonth();
	int getYear();	

	//***** other functions  *****
	// print the calendar
	void printCalendar();

	// determine first day of month 
	int firstDayOfMonth();
	
	//***** constructors *****

	// default constructor 
	calendarType();

	// constructor with parameters, month and year
	calendarType(int, int);

	//***** destructor *****

	calendarType::~calendarType();

private:

	// calendarType includes extDateType class and dayType class 

	extDateType extDateForCalendar;
	dayType FirstDayOfMonth;

};

#endif
