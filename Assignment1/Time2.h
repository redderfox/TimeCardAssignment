#ifndef TIME2_H
#define TIME2_H

#include <cstdlib>
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

	void set(string time)
	{
		string temp;

		for (size_t i = 0; i < time.length(); i += 3)
		{
			temp = time.substr(i, 2);
			if (i == 0)
				hours = stoi(temp);
			else if (i == 3)
				minutes = stoi(temp);
			else if (i == 6)
				seconds = stoi(temp);
			else
			{
				if (temp == "PM" || temp == "pm")
					hours += 12;
			}
		}
	}


	int getTotalSeconds() const
	{
		return (hours * 3600 + minutes * 60 + seconds);
	}

};
#endif 