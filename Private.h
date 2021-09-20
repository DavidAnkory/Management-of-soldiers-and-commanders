/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The h file includes the names of the functions and their definition
*/
#pragma once
#include <iostream>
#include <string>
#include "Soldier.h"

class Private :public Soldier
{
protected:
	int* grades;

public:
	//Methods of builders
	Private():Soldier::Soldier(),grades(nullptr){}
	Private(int _tz, string _first, string _lest, int _oparethion);
	~Private();

	//Methods
	string soldierType() { return "Private"; };
	void set_grades();

	//Methods of override
	void print() override;
	bool medal() override;

};



