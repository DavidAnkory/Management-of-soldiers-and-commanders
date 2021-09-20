/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The h file includes the names of the functions and their definition
*/
#pragma once
#include "Private.h"


class Commander :public Private 
{
protected:
	bool combat;

public:
	//Methods of builders
	Commander():Private::Private(), combat(false){}
	Commander(int _tz, string _first, string _lest, int _oparethion);

	//Methods
	string soldierType() { return "Commander"; };
	void setCombat();

	//Methods of override
	void print() override;
	bool medal() override;
	bool getisCombatCommander() override;

};



