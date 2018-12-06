/*
 * Name:		Time Card Application
 *
 * Description: This program simulates a workplace time clock with options
 *				to create a new time card, punch in/out, and display time card data
 *
 *				The program implements 2 classes: TimeCard and Time2
 *
 *				Time2 contains members that validate, store, and retrieve punch times
 *				TimeCard contains employee data including Time2 objects for punch times
 *					-It also validates data, calculates hours and earnings, and displays time cards
 *
 * Author:		Mike Lisak
 * Version:		1
 * Class:		CIS2541-Net01
 * Instructor:	Mohammad Morvati
 * Assignment:	#1
 * Date:		12/5/2018
 */
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
	bool validTime;

	// ===================================================
	// TEST DATA - Check if the constructors work properly
	// ===================================================
	Time2 emptyTime;
	// Invalid inputs get set to '0'
	Time2 invalid1("39:72:x PM");
	Time2 invalid2(78, 30, 0);
	// Valid Time2 objects
	Time2 in("08:00:00 AM");
	Time2 out1("03:30:00 PM");
	Time2 out2("04:30:00 PM");
	// Testing all constructors with valid/invalid data
	TimeCard employee1("123456789", in, out1, 12.5);
	TimeCard employee2("997654321", in, out2, 12.5);
	TimeCard employee3("000000000", out1, in, 25);  // Punched out before in
	TimeCard employee4("111111111", invalid1, invalid2, 30);  // Invalid times
	TimeCard employee5("222222222", emptyTime, 20);  // Empty time
	TimeCard employee6("333333333", 15);
	TimeCard emptyTimeCard;

	TimeCard timeCard;  // Used to add new employee TimeCard

	// Store test data
	vector<TimeCard> timeCards
	{
		employee1, employee2, employee3,
		employee4, employee5, employee6,
		emptyTimeCard
	};

	do
	{
		// Display Menu
		cout << "\tMENU\n";
		cout << "\t----\n";
		cout << "1) New Time Card\n";
		cout << "2) Punch In/Out\n";
		cout << "3) Display Employee Time Card\n";
		cout << "4) Display All Time Cards\n";
		cout << "5) Quit\n\n";
		cout << "Enter your choice: ";
		getline(cin, input);

		while (input.length() > 1 || (input[0] < '1' || input[0] > '5'))
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

					validTime = timeCards[index].punch(input);
					while (!validTime)  // While time is not valid
					{
						cout << "\tPlease enter a valid time: ";
						getline(cin, input);
						validTime = timeCards[index].punch(input);
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
			else
				cout << "\nEMPLOYEE NOT FOUND!\n\n";
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

	cout << "\n\tLOGIN\n";
	cout << "\t---------\n";
	cout << "\tEnter ID: ";
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