#include <iostream>
#include <vector>
#include "TimeCard.h"
using namespace std;


int found(vector<TimeCard> &, string);

int main()
{
	char choice;
	string input;
	vector<TimeCard> timeCards;

	do
	{
		cout << "MENU\n\n";
		cout << "1) New Time Card\n";
		cout << "2) Punch time card\n";
		cout << "3) Quit\n";
		do
		{
			cout << "Enter your choice: ";
			cin >> choice;
		} while (choice < '1' || choice > '3');

		if (choice == '1')
		{
			TimeCard tc;
			cin >> tc;
			timeCards.push_back(tc);
		}
		else if (choice == '2')
		{
			cout << "Enter ID: ";
			cin >> input;
			int index = found(timeCards, input);
			if (index)
			{
				cout << "Enter the time: ";
				cin >> input;
				if (timeCards[index].punch(input))
				{
					cout << "Hours:\n";
					cout << timeCards[index].getHours();
				}
			}
			else
			{
				cout << "Employee not found/n";
			}
		}
	} while (choice != '3');
	cin.get();
	cin.get();
	return 0;
}

int found(vector<TimeCard> &tc, string id)
{
	for (int i = 0; i < tc.size(); i++)
	{
		if (tc[i].getWorkerID() == id)
			return i;
	}
	return -1;
}