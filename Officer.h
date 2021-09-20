/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The h file includes the names of the functions and their definition
*/
#pragma once
#include "Soldier.h"

class Officer : public Soldier
{
protected:
	int sociometric_score;

public:
	//Methods of builders
	Officer() : Soldier::Soldier(), sociometric_score(0) {}
	Officer(int _id, string first_name, string lest_name, int _oparethion);

	//Methods
	void set_sociometric_score();
	string soldierType() { return "Officer"; };

	//Methods of override
	void print() override;
	bool medal() override;
	int get_sociometric_score() override { return sociometric_score; }

};






