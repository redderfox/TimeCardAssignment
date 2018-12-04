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

	bool getHasPunched() const
	{
		return hasPunched;
	}

	double getHours() const
	{
		double seconds = punchOutTime.getTotalSeconds() - punchInTime.getTotalSeconds();
		return (seconds / 3600);
	}

	double getEarnings() const
	{
		return payRate * this->getHours();
	}

	void punch(string time)
	{
		if (punchInTime.getTotalSeconds() == 0)
			punchInTime.set(time);
		else if (punchOutTime.getTotalSeconds() == 0)
		{
			punchOutTime.set(time);
			hasPunched = true;
		}
	}

	friend ostream &operator << (ostream &, const TimeCard &);
	friend istream &operator >> (istream &, TimeCard &);
};
#endif 