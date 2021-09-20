/*
David Ankory 206780066
Workshop in C ++
Exercise 10
This exercise deals with the Zelshim array after Operation The Wall Guard.
Recruits, commanders and officers took part in Operation The Wall Guard.
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <algorithm>
#include "Soldier.h"
#include "Private.h"
#include "Commander.h"
#include "Officer.h"
using namespace std;



enum option {
	stop,	//	End of program
	addNewSoldier,	//	Adding a new soldier
	medalList,	//	Printing the details of all the soldiers who are entitled to the SLA
	mostSociometric,	//	Printing the name (family and first name) of the soldier with a maximum sociometric score 
	countMedalPrivate,	//	Printing the number of novice soldiers eligible for the SLA
	noCombatCommander,	//	Printing names (family and private) of the commanders who are not combat
	overSoldier,	//	Print an appropriate message, is there a soldier who participated in more than 15 military operations
	removeOfficer,	//	Deletion of all officer soldiers who did not participate in a military operation at all
};

void add(vector<Soldier*>& s)
{
	cout << "enter 1 to add a private soldier\n";
	cout << "enter 2 to add a commander soldier\n";
	cout << "enter 3 to add a officer soldier\n";
	int choice=0, tz = 0, numOfOperations = 0;
	string first_name, last_name;
	cin >> choice;
	if (choice < 1 || choice > 3)
		throw "Please enter a num between 1 and 3 included\n";

	cout << "enter id, first name, last name and number Of operations\n";
	cin >> tz >> first_name >> last_name >> numOfOperations;

	//in to the vector

	if (choice == 1)
	{
		s.push_back(new Private(tz, first_name, last_name, numOfOperations));
	}

	else if (choice == 2)
	{
		s.push_back(new Commander(tz, first_name, last_name, numOfOperations));
	}

	else if (choice == 3)
	{
		s.push_back(new Officer(tz, first_name, last_name, numOfOperations));
	}
}


void medal(vector<Soldier*>& s)
{
	for (size_t j = 0; j < s.size(); j++)
	{
		if (s[j]->medal())//if he have a medal, print
		{
			s[j]->print();
		}
	}
}  
Soldier* mostSociometricScore(vector<Soldier*>& s)
{
	int maxociometricScore = 0;
	Soldier* max;
	max = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i]->soldierType() == "Officer")
		{
			Officer* p = (Officer*)s[i];
			if (p->get_sociometric_score() > maxociometricScore)// If there is someone with a higher score then he is the maximum
			{
				maxociometricScore = p->get_sociometric_score();
				max = p;//refresh the max
			}
		}
	}

	if (maxociometricScore == 0)//No officers at all
	{
		return NULL;
	}

	return max;

} 

int main()
{
	int count = 0;
	vector<Soldier*> soldiers; // A statement about a vector  of soldiers
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewSoldier:
		try
		{
			add(soldiers);  //Adding a new soldier						
		}
		catch (const char* str)
		{
				cout << str;
		}
		break;

		case medalList:medal(soldiers);  //Printing the details of those entitled to the SLA
			break;

		case mostSociometric://Printing the name of the officer with the highest sociometric score
		{
			Soldier* temp = mostSociometricScore(soldiers); 
			cout << "Officer soldier with most sociometric score: ";
			if (temp != NULL)//If there are officers on the list
			{
				cout << temp->getFname() << ' ' << temp->getName() << endl;
			}
			cout << endl;
			break;
		}

		case countMedalPrivate:cout << "# private soldier for medal: ";
		{
			int counter = [&soldiers]()->int {int count = 0; for_each(soldiers.begin(), soldiers.end(), [&count](Soldier* s) {if (s->medal() && s->soldierType() == "Private") count++; }); return count; }(); //הדפסת מספר הזכאים לצל"ש בטירונים
			cout << counter << endl;//The counter variable gets at the end the number of novices who have a medal
			break;
		}
		
		

		case noCombatCommander:
		
			cout << "list of no combat commander soldier :";//print the commander that is not a combat
			for_each(soldiers.begin(), soldiers.end(), [](Soldier* s) {if (!s->getisCombatCommander()) cout << s->getFname() << ' ' << s->getName() << endl; });
			cout << endl;
			break;
		

		case overSoldier://check for soldier that takes more than 15 operations
			if (any_of(soldiers.begin(), soldiers.end(), [](Soldier* s)->int {return s->getNumOparethion() >= 15; }))
				cout << "there is a soldier that takes more than 15 operations\n";
			else cout << "no soldier takes more than 15 operations\n";
			break;

		case removeOfficer:
			//Deletion from the vector of all soldiers Officers who did not participate at all in military operations
			vector<Soldier*>::iterator p = remove_if(soldiers.begin(), soldiers.end(), [](Soldier* a) {return(a->getNumOparethion() == 0) && a->soldierType() == "Officer"; });
			for_each(soldiers.begin(), p, [](Soldier* c) { c->print(); });//Print the entire list after deleting the organs
			break;

		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}
/*
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
1
enter id, first name, last name and number Of operations
111 aaa aaa 3
enter 3 grades
100 95 98
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
2
enter id, first name, last name and number Of operations
222 bbb bbb 0
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
enter 1 to add a private soldier
enter 2 to add a commander soldier
enter 3 to add a officer soldier
3
enter id, first name, last name and number Of operations
333 ccc ccc 0
enter number of sociometric score
100
enter 0-7
3
Officer soldier with most sociometric score: ccc ccc

enter 0-7
4
# private soldier for medal: 0
enter 0-7
5
list of no combat commander soldier :
enter 0-7
6
no soldier takes more than 15 operations
enter 0-7
7
Private
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 100 95 98
Commander
ID: 222
first name: bbb
last name: bbb
num operations: 0
grades:
combat: yes
enter 0-7
0

C:\Users\ankor\Documents\מדעי המחשב- שנה א\סמסטר ב\סדנה C++\exercice10.1\Debug\C++10.1.exe (process 9020) exited with code 0.
Press any key to close this window . . .
*/
