#if !defined(Cspinner_h)
#define Cspinner_h
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include<iomanip>
#include<iostream>
#include<ctime>

#include "Cslot.h"

using namespace std;

enum Currency{Quarter = 1, Dollar = 4, Five = 20, Ten = 40};

class Cspinner
{
	friend bool operator == (Cspinner leftside, char rightside[]);
	friend ostream & operator << (ostream & leftside, Cspinner rightside);
private:
	char fruit[10];
	int result;
	int a;
	int o;
	int c;
	int b;
	int p;

public:
	Cspinner()
	{
		a = 30;
		o = 25;
		c = 20;
		b = 15;
		p = 10;
		srand(time(NULL));
	}

	Cspinner(int a, int o, int c, int b, int p)
	{
		this->a = a;
		this->o = o; 
		this->c = c;
		this->b = b;
		this->p = p;		
	}

	int spin()
	{
		result = rand()%100+1;
		if(result >= 1 && result <= a-1)
		{
			strcpy(fruit, "Apple ");			
		}
		else if(result >= a && result <= (a+o)-1)
		{
			strcpy(fruit, "Orange ");
		}
		else if(result >= (a+o) && result <= (a+o+c)-1)
		{
			strcpy(fruit, "Cherry ");
		}
		else if(result >= (a+o+c) && result <= (a+o+c+b)-1)
		{
			strcpy(fruit, "Banana ");
		}
		else
		{
			strcpy(fruit, "Peach ");
		}
		return fruit[10];
	}

	bool operator == (char rightside)
	{
		if (fruit[10] == rightside)
			return true;
		else
			return false;
	}

	bool operator == (Cspinner rightside)
	{
		if (strcmp(fruit, rightside.fruit)==0)
			return true;
		else
			return false;
	}
};

bool operator == (Cspinner leftside, char rightside[])
{
	if (strcmp(leftside.fruit, rightside)==0)
		return true;
	else
		return false;
}

ostream & operator << (ostream & leftside, Cspinner rightside)
{
	leftside << rightside.fruit;
	return leftside;
}

#endif