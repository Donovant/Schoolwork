// Program 1_DRT.cpp : Defines the entry point for the console application.
//
// Donovan Torgerson
// Assignment 1
// August 29, 2010
//

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	float temp, calc;
	bool scale = true;
	cout << "Enter Temperature:";
	cin >> temp;
	cout << "Enter 1 for Celsius or 0 for Fahrenheit:";
	cin >> scale;
		if(scale)
		{
			calc = 1.8 * temp + 32;
			cout << "The temperature " << temp << " degrees Celsius is " << calc << " degrees Fahrenheit." << endl;
		}
		else
		{
			calc = (temp - 32) / 1.8;
			cout << setprecision (2) << "The temperature " << temp << " degrees Fahrenheit is " << calc << " degrees Celsius." << endl;
		}

	system("pause");
	return 0;
}