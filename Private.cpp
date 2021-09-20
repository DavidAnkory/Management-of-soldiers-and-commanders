/*
David Ankory 206780066
Workshop in C ++
Exercise 10
The Private.cpp file Includes all the codes of the functions
*/

#include "Private.h"
#include <iostream>
using namespace std;

Private::Private(int iD, string nameF, string nameL, int op) : Soldier::Soldier(iD, nameF, nameL, op)
{
	//Increases the size of the dynamic array and sends to the method where the user enters scores
	if (oparethion)
	{
		int* arr = new int[oparethion];
		grades = arr;
		set_grades();
	}
}

Private::~Private()
{
	if (oparethion)
	{
		delete[] grades;
	}
}

void Private::print()
{
	cout << soldierType() << endl;
	Soldier::print();//Thanks to the inheritance
	cout << "grades: ";
	for (size_t i = 0; i < oparethion; i++)
	{
		cout << grades[i] << " ";
	}
	cout << endl;
}

bool Private::medal()
{
	if (oparethion > 9)
	{
		int sum = 0;
		for (size_t i = 0; i < oparethion; i++)//run throw all the oparethions
		{
			sum += grades[i];
		}
		sum /= oparethion;//average
		if (sum >= 95)//if not continue to return false
		{
			return true;
		}

	}
	return false;
}

void Private::set_grades()
{
	int grade;
	cout << "enter " << oparethion << " grades\n";
	for (int i = 0; i < oparethion; i++)
	{
		cin >> grade;
		if (grade >= 0 && grade <= 100)
			grades[i] = grade;
		else
		{
			cout << "Invalid grade\n";//ERORR GRADE
			i--;
		}
	}
}
