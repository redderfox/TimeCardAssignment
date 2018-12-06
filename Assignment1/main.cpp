#include <iostream>
#include <vector>
#include <iomanip>
#include "TimeCard.h"
using namespace std;


int findTimeCard(vector<TimeCard> &);
void displayTimeCards(vector<TimeCard> &, int);

int main()
{
	string input;
	int index;

	// Initialize timeCards with test data
	Time2 in("08:00:00 AM");
	Time2 out1("03:30:00 PM");
	Time2 out2("04:30:00 PM");
	TimeCard employee1("123456789", in, out1, 12.5);
	TimeCard employee2("997654321", in, out2, 12.5);
	TimeCard timeCard;

	vector<TimeCard> timeCards;

	timeCards.push_back(employee1);
	timeCards.push_back(employee2);

	do
	{
		cout << "\tMENU\n";
		cout << "\t----\n";
		cout << "1) New Time Card\n";
		cout << "2) Punch In/Out\n";
		cout << "3) Display employee time card\n";
		cout << "4) Display all time cards\n";
		cout << "5) Quit\n\n";
		cout << "Enter your choice: ";
		getline(cin, input);

		while (input.length() > 1 && (input < "1" || input > "5"))
		{
			cout << "Please enter a valid choice: ";
			getline(cin, input);
		}

		switch (input[0])
		{
		case '1':  // Create a new TimeCard
			cin >> timeCard;  // Overloaded stream insertion
			cin.ignore();
			timeCards.push_back(timeCard);
			break;
		case '2':  // Punch In/Out
			index = findTimeCard(timeCards);
			if (index > -1)  // If TimeCard found
			{
				if (!timeCards[index].getHasPunched())  // If not punched out
				{
					cout << "\n\tTIME FORMAT:    HH:MM:SS XX\n";
					cout << "\tEnter the time: ";
					getline(cin, input);
					while (!timeCards[index].punch(input))  // While time is not valid
					{
						cout << "\tPlease enter a valid time: ";
						getline(cin, input);
					}
					cout << endl;
				}
				else  // If punched out
					cout << "\nYOU HAVE ALREADY PUNCHED OUT!\n\n";
			}
			else  // If Time Card not found
			{
				cout << "\nEMPLOYEE NOT FOUND!\n\n";
			}
			break;
		case '3':  // Display single employee TimeCard
			index = findTimeCard(timeCards);
			if (index > -1)  // If TimeCard found
				displayTimeCards(timeCards, index);
			break;
		case '4':  // Display all TimeCards
			displayTimeCards(timeCards, -1);
			break;
		}
	} while (input[0] != '5');  // User did not select Quit
	
	return 0;
}


// Prompts user for ID and searches the TimeCards
// If found return the index, else return -1
int findTimeCard(vector<TimeCard> &tc)
{
	string id;

	cout << "\nLOGIN\n";
	cout << "---------\n";
	cout << "Enter ID: ";
	getline(cin, id);

	for (int i = 0; i < tc.size(); i++)
	{
		if (tc[i].getWorkerID() == id)
			return i;
	}
	return -1;
}


// Displays a single TimeCard if an index is passed to ind
// Displays all TimeCards if -1 is passed
void displayTimeCards(vector<TimeCard> &tc, int ind)
{
	cout << endl;
	cout << left << setw(12) << "Worker ID" << setw(14) << "Start Time";
	cout << setw(14) << "End Time" << setw(11) << "Pay Rate";
	cout << setw(8) << "Hours" << "Earnings\n";
	cout << "---------   -----------   -----------   --------   -----   --------\n";
	if (ind > -1)  // If an index was passed
		cout << tc[ind];  // Overloaded stream extraction operator
	else
	{
		for (int i = 0; i < tc.size(); i++)
			cout << tc[i];  // Overloaded stream extraction operator
	}
	cout << endl;
}