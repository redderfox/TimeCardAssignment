#include "TimeCard.h"
#include <iostream>
using namespace std;

istream &operator >> (istream &strm, TimeCard &obj)
{
	string input;

	cout << "Worker ID: ";
	strm >> obj.workerID;
	obj.punchOutTime.set(input);
	cout << "Pay Rate: ";
	strm >> obj.payRate;

	return strm;
}