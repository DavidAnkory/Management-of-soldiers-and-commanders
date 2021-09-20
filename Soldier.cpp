/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The Soldier.cpp file Includes all the codes of the functions
*/
#include "Soldier.h"
#include <iostream>
using namespace std;

Soldier::Soldier(int _tz, string _first, string _lest, int _oparethion)
{
	//For incorrect values
	if (_tz < 0)
		throw "Invalid ID\n";
	if (_first == "\0" || _lest == "\0")
		throw "Invalid Name\n";
	if (_oparethion < 0)
		throw "Invalid operation number\n";

	//For correct values
	tz = _tz;
	first_name = _first;
	last_name = _lest;
	oparethion = _oparethion;
}



int Soldier::get_sociometric_score()
{
	//Only for officer-type soldiers, so the method throws an error
	throw "ERROR: this function is just for officer soldier";
}

void Soldier::print()
{
	cout << "ID: " << tz << endl;
	cout << "first name: " << first_name << endl;
	cout << "last name: " << last_name << endl;
	cout << "num operations: " << oparethion << endl;
}

