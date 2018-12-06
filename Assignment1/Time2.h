#ifndef TIME2_H
#define TIME2_H

#include <iostream>
#include <string>
using namespace std;


class Time2 
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	// ===================
	// DEFAULT CONSTRUCTOR
	// ===================
	Time2()
	{
		setEmpty();
	}

	// ==============
	// CONSTRUCTOR #2
	// ==============
	Time2(int h, int m, int s)  // Sets time as '0' if parameters are invalid
	{
		int times[3] = { h, m, s };

		if (validTime(times))
		{
			hours = h;
			minutes = m;
			seconds = s;
		}
		else
			setEmpty();
	}

	// ==============
	// CONSTRUCTOR #3
	// ==============
	Time2(string time)  // Sets time as '0' if parameters are invalid
	{
		if (!set(time))
			setEmpty();
	}

	// ================
	// MUTATORS
	// ================
	void setEmpty()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	bool set(string);

	// ==================
	// ACCESSORS
	// ==================

	// Returns time in total seconds. Easier to calculate hours worked
	int getTotalSeconds() const
	{
		return (hours * 3600 + minutes * 60 + seconds);
	}

	string getTime() const;

	// =====================
	// FUNCTION DECLARATIONS
	// =====================
	bool validTime(int *);
	friend ostream &operator << (ostream &, const Time2 &);
};
#endif 