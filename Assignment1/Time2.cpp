#include <cstdlib>  // Used isdigit()
#include "Time2.h"


// Parses a string into individual time components
// Checks if time components are valid
// If they are valid, set the time and return true
// If they are not valid, return false
bool Time2::set(string time)
{
	int times[3];  // Stores hours, minutes, seconds
	string temp;
	bool isValidTime = false;

	if (time.length() == 11)  // If time is correct length
	{
		for (int i = 0; i < 3; i++)
		{
			temp = time.substr(i * 3, 2);  // Parse 2 characters from the string

			if (isdigit(temp[0]) && isdigit(temp[1]))  // If the characters are digits
				times[i] = stoi(temp);  // Store them as integers
		}
		isValidTime = validTime(times);  // Check if hours, minutes, and seconds are valid

		if (isValidTime)
		{
			temp = time.substr(9, 2);  // Parse the AM/PM portion

			if (temp == "PM" || temp == "pm")
				times[0] += 12;  // If PM, add 12 to hours (military time)
			else if (temp != "am" && temp != "AM")
				return false;  // If user did not enter AM or PM, string is not valid

			// Set the time for the object
			hours = times[0];
			minutes = times[1];
			seconds = times[2];
		}
	}
	return isValidTime;
}


// Returns the time as a string to be displayed in a table
string Time2::getTime() const
{
	string h, m, s, ampm;  // Time components

	if (this->getTotalSeconds() == 0)
		return "NOT SET";

	// If time is PM, subtract 12 from hours and set PM
	if (hours > 12)
	{
		h = to_string(hours - 12);  
		ampm = "PM";
	}
	else
	{
		h = to_string(hours);
		ampm = "AM";
	}

	// Add a '0' if the time is a single digit
	// Allows the time to be displayed correctly in a table
	if (minutes < 10)
		m = "0" + to_string(minutes);
	else
		m = to_string(minutes);

	if (seconds < 10)
		s = "0" + to_string(seconds);
	else
		s = to_string(seconds);

	return (h + ":" + m + ":" + s + " " + ampm);  // Return time components as a single string
}


// Checks if hours, minutes, seconds are valid values
bool Time2::validTime(int *times)
{
	bool isValidt = false;

	if (times[0] > 0 && times[0] < 13)  // Hours is between 1-12?
		if (times[1] >= 0 && times[1] < 60)  // Minutes is between 0-59?
			if (times[2] >= 0 && times[2] < 60)  // Seconds is between 0-59?
				isValidt = true;

	return isValidt;
}


// Overloaded stream insertion operator to display the time
ostream &operator << (ostream &strm, const Time2 &obj)
{
	strm << obj.getTime();
	return strm;
}