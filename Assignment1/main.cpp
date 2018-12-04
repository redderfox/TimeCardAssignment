#include <iostream>
#include <vector>
#include "TimeCard.h"
using namespace std;


int findTimeCard(vector<TimeCard> &);

int main()
{
	char choice;
	string input;
	int index;
	TimeCard timeCard;

	vector<TimeCard> timeCards;

	do
	{
		cout << "MENU\n\n";
		cout << "1) New Time Card\n";
		cout << "2) Punch In/Out\n";
		cout << "3) Display individual time card\n";
		cout << "4) Display all time cards\n";
		cout << "5) Quit\n";
		do
		{
			cout << "Enter your choice: ";
			cin >> choice;
		} while (choice < '1' || choice > '5');

		switch (choice)
		{
		case '1':
			cin >> timeCard;
			timeCards.push_back(timeCard);
			break;
		case '2':
			index = findTimeCard(timeCards);
			if (index != -1)
			{
				if (!timeCards[index].getHasPunched())
				{
					cout << "Enter the time: ";
					cin.ignore();
					getline(cin, input);
					timeCards[index].punch(input);
				}
				else
					cout << "You have already punched out!\n";
			}
			else
			{
				cout << "Employee not found/n";
			}
			break;
		case '3':
			index = findTimeCard(timeCards);
			if (index != -1)
			{
				cout << timeCards[index];
			}
			break;
		case '4':
			// displayAllTimeCards();
			break;
		}
	} while (choice != '5');
	cin.get();
	cin.get();
	return 0;
}

int findTimeCard(vector<TimeCard> &tc)
{
	string id;

	cout << "Enter ID: ";
	cin >> id;

	for (int i = 0; i < tc.size(); i++)
	{
		if (tc[i].getWorkerID() == id)
			return i;
	}
	return -1;
}