//
// Assignment 2
// Donovan Torgerson
// Donovan@Bitzpc.com
// 8/31/11
//

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <time.h>

using namespace std;

class Cspinner
{  
private:
	int fruit;
	int a;			// apple
	int o;			// orange
	int c;			// cherry
	int b;			// banana
	int p;			// peach
public:
	Cspinner()
	{
		srand(time(NULL));
		fruit = 0;
		a = 30;
		o = 25;
		c = 20;
		b = 15;
		p = 10;
	}

	Cspinner(int apple, int orange, int cherry, int banana, int peach)
	{
		srand(time(NULL));
		fruit = 0;
		a = apple;
		o = orange;
		c = cherry;
		b = banana;
		p = peach;
	}

	void spin()
	{
		this->fruit = (rand() % 100) + 1;
	}

	void show()
	{
		if(fruit >= 1 && fruit <= a)
		{
			cout << "apple ";
		}
		else if(fruit > a && fruit <= a+o)
		{
			cout << "orange ";
		}
		else if(fruit > a+o && fruit <= a+o+c)
		{
			cout << "cherry ";
		}
		else if(fruit > a+o+c && fruit <= a+o+c+b)
		{
			cout << "banana ";
		}
		else
		{
			cout << "peach ";
		}
	}
};


void main() 
{ 
	Cspinner w1; 
	Cspinner w2; 
	Cspinner w3(80, 5, 5, 5, 5); 
	for (int x = 0; x <= 9; x++) 
	{ 
		w1.spin(); 
		w2.spin(); 
		w3.spin(); 
		w1.show(); 
		w2.show(); 
		w3.show(); 
		cout << endl; 
	}
	system("pause");
} 
