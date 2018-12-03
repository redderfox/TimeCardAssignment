#ifndef TIMECARD_H
#define TIMECARD_H

#include <string>
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

	TimeCard(string id, const Time2 &in, const Time2 &out, double pr, bool hp)
	{
		workerID = id;
		punchInTime = in;
		punchOutTime = out;
		payRate = pr;
		hasPunched = hp;
	}

	void setWorkerID(string id)
	{
		workerID = id;
	}

	void setPayRate(double pr)
	{
		payRate = pr;
	}

	void setHasPunched(bool hp)
	{
		hasPunched = hp;
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

	}
};
#endif 