#include "Time2.h"
//cstdlib

void Time2::simplify()
{
	if (minutes < 0)
	{
		hours--;
		minutes += 60;
	}
	if (seconds < 0)
	{
		minutes--;
		seconds += 60;
	}
}

Time2 Time2::operator - (const Time2 &right)
{
	Time2 temp;

	temp.seconds = seconds - right.seconds;
	temp.minutes = minutes - right.minutes;
	temp.hours = hours - right.hours;
	temp.simplify();

	return temp;
}