/* Beth Reel
CSC161C00
Chapter 11 Program Assignment
February 08, 2017

This class saves days of week for printing of calendar in CalendarType 
*/
// Header file for dayType

#ifndef dayType_H
#define dayType_H

#include <string>

using namespace std;

class dayType
{
public:
	static string daysOfWeek[7];

	//**** setters *****
	void setDay(string);

	//**** getters *****
	string getDay() const;


	//**** constructors ****
	dayType();
	dayType(string);

	//*** destructors ***
	~dayType(); 

	//**** other functions ***
	void printDayType() const;


private:
	string dayOfWeek;
};

#endif
