#include <iostream>
#include <iomanip>
#include "TimeCard.h"
using namespace std;


// Checks if a valid time was entered, returns the result
// Punches in or out depending on which object has already been set
// If both have been set, make hasPunched = true
bool TimeCard::punch(string time)
{
	bool isValid = false;

	if (punchInTime.getTotalSeconds() == 0)
		isValid = punchInTime.set(time);  // Set punch in time if it is valid
	else if (punchOutTime.getTotalSeconds() == 0)
	{
		isValid = punchOutTime.set(time);  // Set punch out time if it is valid
		// If punched out before punched in, set not valid
		if (punchOutTime.getTotalSeconds() < punchInTime.getTotalSeconds())
		{
			punchOutTime.setEmpty();
			isValid = false;
		}
		else
			hasPunched = true;
	}

	return isValid;
}


// Overloaded stream insertion for displaying TimeCard in a table
ostream &operator << (ostream &strm, const TimeCard &obj)
{
	double dispHours = obj.getHours();
	double dispEarnings = obj.getEarnings();

	// If employee has not punched in or out, Display '0' for hours and earnings
	if (obj.punchOutTime.getTotalSeconds() == 0 || obj.punchInTime.getTotalSeconds() == 0)
	{
		dispHours = 0.0;
		dispEarnings = 0.0;
	}

	strm << fixed << showpoint << setprecision(2) << left;
	strm << setw(12) << obj.workerID << setw(14) << obj.punchInTime.getTime();
	strm << setw(14) << obj.punchOutTime.getTime() << setw(11) << obj.payRate;
	strm << setw(8) << dispHours << dispEarnings << endl;

	return strm;
}


// Overloaded stream extraction for creating a new TimeCard
istream &operator >> (istream &strm, TimeCard &obj)
{
	string input;

	obj.punchInTime.setEmpty();
	obj.punchOutTime.setEmpty();
	obj.hasPunched = false;

	cout << "\n\tNEW TIME CARD\n";
	cout << "\t-------------\n";
	cout << "\tEnter Worker ID: ";
	strm >> obj.workerID;
	cout << "\tEnter Pay Rate: $";
	strm >> obj.payRate;
	cout << endl;

	return strm;
} 