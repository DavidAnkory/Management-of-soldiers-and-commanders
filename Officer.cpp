/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The Officer.cpp file Includes all the codes of the functions
*/
#include "Officer.h"
#include <iostream>
using namespace std;

Officer::Officer(int iD, string nameF, string nameL, int op) : Soldier::Soldier(iD, nameF, nameL, op)
{
	set_sociometric_score();//set by the user
}

void Officer::print()
{
	cout << soldierType() << endl;//print "Officer"
	Soldier::print();//Thanks to the inheritance
	cout << "sociometric score: " << sociometric_score << endl;
}

bool Officer::medal()
{
	if (oparethion > 2 && sociometric_score >= 92)//by the order
	{
		return true;
	}
	return false;//else flase
}

void Officer::set_sociometric_score()
{
	int choice;
	cout << "enter number of sociometric score\n";
	cin >> choice;

	if (choice < 0 || choice > 100)
		throw "Invalid sociometric score\n";//ERROR GRADE
	sociometric_score = choice;
}
