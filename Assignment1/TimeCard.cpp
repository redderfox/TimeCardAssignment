#include <iostream>
#include <iomanip>
#include "TimeCard.h"
using namespace std;


// Checks if a valid time was entered, returns the result
// Punches in or out depending on which object has already been set
// If both have been set, make hasPunched = true
bool TimeCard::punch(string time)
{
	bool isValid;

	if (punchInTime.getTotalSeconds() == 0)
		isValid = punchInTime.set(time);
	else if (punchOutTime.getTotalSeconds()  == 0)
	{
		isValid = punchOutTime.set(time);
		hasPunched = true;
	}

	return isValid;
}


// Overloaded stream insertion for displaying TimeCard in a table
ostream &operator << (ostream &strm, const TimeCard &obj)
{
	strm << fixed << showpoint << setprecision(2) << left;
	strm << setw(12) << obj.workerID << setw(14) << obj.punchInTime.getTime();
	strm << setw(14) << obj.punchOutTime.getTime() << setw(11) << obj.payRate;
	strm << setw(8) << obj.getHours() << obj.getEarnings() << endl;

	return strm;
}


// Overloaded stream extraction for creating a new TimeCard
istream &operator >> (istream &strm, TimeCard &obj)
{
	string input;

	cout << "\n\tNEW TIME CARD\n";
	cout << "\t-------------\n";
	cout << "\tEnter Worker ID: ";
	strm >> obj.workerID;
	cout << "\tEnter Pay Rate: $";
	strm >> obj.payRate;
	cout << endl;

	return strm;
} 