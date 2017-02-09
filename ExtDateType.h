/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017

This class saves months of week for printing of calendar in CalendarType
*/
// Header file for ExtDateType

#ifndef ExtDateType_H
#define ExtDateType_H

#include <string>
#include "DateType.h"

using namespace std;

class extDateType : public DateType
{
public:
	static string longStringMonths[12];

	
	//***** setters *****
	
	void setDate(int, int, int);
	void setMonth(int);

	//***** constructors ****
	extDateType();
	extDateType(int, int, int);

	//***** destructor ****
	~extDateType(); 

	//***** other member functions ****

	// print date for calendar "Month yyyy"
	void printLongMonthYear();

	// print date in format "Month dd, yyyy"
	void printLongDate();

private:
	// store string form for name of month
	string extendedMonth;
};

#endif