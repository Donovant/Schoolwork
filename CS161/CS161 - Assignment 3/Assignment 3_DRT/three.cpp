//
// Assignment 2
// Donovan Torgerson
// 1/20/11
//

#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include<iomanip>
#include<iostream>
#include<ctime>

using namespace std;

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
			strcpy(fruit, "apple ");			
		}
		else if(result >= a && result <= (a+o)-1)
		{
			strcpy(fruit, "orange ");
		}
		else if(result >= (a+o) && result <= (a+o+c)-1)
		{
			strcpy(fruit, "cherry ");
		}
		else if(result >= (a+o+c) && result <= (a+o+c+b)-1)
		{
			strcpy(fruit, "banana ");
		}
		else
		{
			strcpy(fruit, "peach ");
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

void main()
{
	Cspinner w1; 
	Cspinner w2; 
	Cspinner w3(80,5,5,5,5); 
	for (int x=0; x<=9; x++) 
	{ 
		w1.spin(); 
		w2.spin(); 
		w3.spin(); 
		cout << w1 << w2 << w3; 
		if (w1 == w2 && w2 == w3)
		{ 
			if (w1 == "apple ")    cout << "  (All Apples) "; 
			else if (w1 == "orange ") cout << "  (All Oranges) "; 
			else if (w1 == "cherry ") cout << "  (All Cherries) "; 
			else if (w1 == "banana ") cout << "  (All Bananas) "; 
			else  cout << "   (All Peaches)"; 
		}

		cout << endl; 
	}
	system("pause");
}