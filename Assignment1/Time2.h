#ifndef TIME2_H
#define TIME2_H

class Time2 
{
private:
	int hour;
	int minute;
	int second;
public:
	Time2()
	{
		hour = 0;
		minute = 0;
		second = 0;
	}

	Time2(int h, int m, int s)
	{
		set(h, m, s);
	}

	void set(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}

	string getTime() const
	{
		string time = hour + ":" + minute + ":" + second;
	}
};
#endif 