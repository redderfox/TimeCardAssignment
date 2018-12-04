#include "TimeCard.h"
#include <iostream>
#include <iomanip>
using namespace std;

ostream &operator << (ostream &strm, const TimeCard &obj)
{
	strm << fixed << showpoint << setprecision(2);
	strm << setw(11) << obj.workerID << setw(12) << "00:00:00 AM";
	strm << setw(12) << "00:00:00 PM" << setw(9) << "$" << obj.payRate;
	strm << setw(6) << obj.getHours() << " $" << obj.getEarnings() << endl;

	return strm;
}

istream &operator >> (istream &strm, TimeCard &obj)
{
	string input;

	cout << "Worker ID: ";
	strm >> obj.workerID;
	cout << "Pay Rate: ";
	strm >> obj.payRate;

	return strm;
} 