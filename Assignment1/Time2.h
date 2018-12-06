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
	// ============
	// CONSTRUCTORS
	// ============
	Time2()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time2(string time)
	{
		set(time);
	}

	// ================
	// MUTATOR
	// ================
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

	// FUNCTION DECLARATIONS
	bool validTime(int[]);
	friend ostream &operator << (ostream &, const Time2 &);
};
#endif 