/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The h file includes the names of the functions and their definition
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Soldier
{
protected:
	int tz;
	string first_name;
	string last_name;
	int oparethion;

public:
	//Methods of builders
	Soldier() : tz(0), first_name("\0"), last_name("\0"), oparethion(0) {}
	Soldier(int _tz, string _first, string _lest, int _oparethion);
	virtual ~Soldier() {};//desctructor

	//pure virtual methods
	virtual bool medal() = 0;
	virtual string soldierType() = 0;

	//virtual methods
	virtual void print();
	virtual int get_sociometric_score();
	virtual bool getisCombatCommander() { return true; };
	virtual int getNumOparethion() { return oparethion; };
	virtual string getFname() { return first_name; };
	virtual string getName() { return last_name; };
};




