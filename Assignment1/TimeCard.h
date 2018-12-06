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
	// ============
	// CONSTRUCTORS
	// ============
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
		hasPunched = true;
	}

	// ================
	// MUTATORS
	// ================
	void setWorkerID(string id)
	{
		workerID = id;
	}

	void setPayRate(double pr)
	{
		payRate = pr;
	}

	// ==================
	// ACCESSORS
	// ==================
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

	// FUNCTION DECLARATIONS
	bool punch(string);
	friend ostream &operator << (ostream &, const TimeCard &);
	friend istream &operator >> (istream &, TimeCard &);
};
#endif 