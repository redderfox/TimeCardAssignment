#ifndef TIME2_H
#define TIME2_H

#include <cstdlib>
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
		size_t pos = 0;
		string token;
		int iteration = 1;

		while (pos = time.find(":") != string::npos)
		{
			token = time.substr(0, pos);
			if (iteration == 1)
				hours = atoi(token.c_str());
			else
				minutes = atoi(token.c_str());
			time.erase(0, pos + 1);
			iteration++;
		}
		pos = time.find(" ");
		token = time.substr(0, pos);
		seconds = atoi(token.c_str());
		time.erase(0, pos + 1);

		if (time == "PM")
			hours += 12;
	}


	int getTime() const
	{
		return (hours * 3600 + minutes * 60 + seconds);
	}

	Time2 operator - (const Time2 &); // Overloaded -
	void simplify();
};
#endif 