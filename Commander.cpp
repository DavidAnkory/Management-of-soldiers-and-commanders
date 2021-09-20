/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The Commander.cpp file Includes all the codes of the functions
*/
#include "Commander.h"
#include <iostream>
using namespace std;

Commander::Commander(int _tz, string _first, string _lest, int _oparethion) :Private(_tz, _first, _lest, _oparethion)
{
	setCombat();//get if he is a combat
}

bool Commander::getisCombatCommander()//return if combat or not
{
	if (combat)
		return true;
	return false;
}



void Commander::print() {//print is combat or not
	Private::print();
	cout << "combat: ";

	if (combat)
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
}

bool Commander::medal()
{
	if (oparethion >6 && combat == true)//If performed more than 6 operations (ie at least 7)
	{
		int sum = 0;
		for (size_t i = 0; i < oparethion; i++)//run throw all the oparethions
		{
			sum += grades[i];
		}
		sum =sum/ oparethion;//average
		if (sum > 90)//if not continue to return false 
		{
			return true;
		}
	}
	return false;
}

void Commander::setCombat()//set by the user
{
	int choice;
	cout << "enter 1 if the soldier is combat and 0 if not\n";
	cin >> choice;
	if (choice == 1)
		combat = true;
	else if (choice == 0)
		combat = false;
	else
		throw "Please enter 1 or 0\n";//ERROR
}
