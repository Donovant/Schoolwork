// Program 3_DRT.cpp : Defines the entry point for the console application.
//
// Donovan Torgerson
// Assignment 3
// September 9, 2010
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double wage;
	double hours;
	double total1 = 0;
	double total2 = 0;
	double total3 = 0;
	double grand = 0;
	cout << "Enter hours: ";
	cin >> hours;
	cout << "Enter wage: $";
	cin >> wage;
	if(hours < 41)
	{
		total1 = wage * hours;
	}
	else if(hours > 40 && hours <= 50)
	{
		total2 = (wage * 1.5) * (hours - 40);
		total1 = wage * 40;
	}
	else
	{
		total3 = (wage * 2) * (hours - 50);
		total2 = (wage * 1.5) * 10;
		total1 = wage * 40;
	}
	grand = total1 + total2 + total3;
	cout.precision(2);
	cout << fixed << "\n" << setw (15) <<setiosflags (ios::left) << "Regular Pay: " << "$" << total1 << endl;
	cout << fixed << setw (15)  << "Overtime Pay: " << "$" << total2 << endl;
	cout << setw (15)  << "Double Pay: " << "$" << total3 << endl;
	cout << setw (15)  << "Total Pay: " << "$" << grand << "\n" << endl;
	system("pause");
	return 0;
}