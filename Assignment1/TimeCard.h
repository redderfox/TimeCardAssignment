#ifndef TIMECARD_H
#define TIMECARD_H

#include <string>
#include <iostream>
#include "Time2.h"
using namespace std;

class TimeCard
{
private:
	string workerID;
	Time2 punchInTime, punchOutTime;
	double payRate;
	bool hasPunched;
public:
	TimeCard()
	{
		workerID = "";
		payRate = 0.0;
		hasPunched = false;
	}

	TimeCard(string id, const Time2 &in, const Time2 &out, double pr)
	{
		workerID = id;
		punchInTime = in;
		punchOutTime = out;
		payRate = pr;
		hasPunched = false;
	}

	void setWorkerID(string id)
	{
		workerID = id;
	}

	void setPayRate(double pr)
	{
		payRate = pr;
	}

	string getWorkerID() const
	{
		return workerID;
	}

	double getPayRate() const
	{
		return payRate;
	}

	double getHours() const
	{
		double seconds = punchOutTime.getTotalSeconds() - punchInTime.getTotalSeconds();
		return (seconds / 3600);
	}

	bool punch(string time)
	{
		if (punchInTime.getTotalSeconds() == 0)
		{
			punchInTime.set(time);
		}
		else
		{
			punchOutTime.set(time);
			hasPunched = true;
		}
		return hasPunched;
	}

	// friend ostream &operator << (ostream &, const TimeCard &);
	friend istream &operator >> (istream &, TimeCard &);
};
#endif 