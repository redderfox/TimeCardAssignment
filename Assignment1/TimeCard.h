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
	// ===================
	// DEFAULT CONSTRUCTOR
	// ===================
	TimeCard()
	{
		workerID = "EMPTY";
		payRate = 0.0;
		hasPunched = false;
	}

	// ==============
	// CONSTRUCTOR #2
	// ==============
	TimeCard(string id, const Time2 &in, const Time2 &out, double pr)
	{
		workerID = id;
		payRate = pr;
		// If punched out before punched in, set empty Times
		if (out.getTotalSeconds() < in.getTotalSeconds())
		{
			punchInTime.setEmpty();
			punchOutTime.setEmpty();
			hasPunched = false;
		}
		else
		{
			punchInTime = in;
			punchOutTime = out;
			hasPunched = true;
		}
	}

	// ==============
	// CONSTRUCTOR #3
	// ==============
	TimeCard(string id, const Time2 &in, double pr)
	{
		workerID = id;
		punchInTime = in;
		payRate = pr;
		hasPunched = false;
	}

	// ==============
	// CONSTRUCTOR #4
	// ==============
	TimeCard(string id, double pr)
	{
		workerID = id;
		payRate = pr;
		hasPunched = false;
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
		// Convert from seconds to hours
		double seconds = punchOutTime.getTotalSeconds() - punchInTime.getTotalSeconds();
		return (seconds / 3600);
	}

	double getEarnings() const
	{
		return payRate * this->getHours();
	}

	// =====================
	// FUNCTION DECLARATIONS
	// =====================
	bool punch(string);
	friend ostream &operator << (ostream &, const TimeCard &);
	friend istream &operator >> (istream &, TimeCard &);
};
#endif 