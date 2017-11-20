// Program 2_DRT.cpp : Defines the entry point for the console application.
//
// Donovan Torgerson
// Assignment 2
// September 9, 2010
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double type;
	double height;
	double radius;
	double surface;
	double volume;
	double pi = 3.14159;
	cout << "Enter 1 for cone or 2 for sphere: ";
	cin >> type;
	if(type == 1)
	{
		cout << "Input height: ";
		cin >> height;
		cout << "Input radius: ";
		cin >> radius;
		surface = pi * radius * sqrt( pow(radius,2.0) + pow(height,2.0));
		cout << "The lateral surface area of a cone with a radius of " << radius << " and a height of " << height << " is " << surface << "." << endl;
		volume = (pi * pow(radius,2.0) * height) / 3;
		cout << "The volume of a cone with a radius of " << radius << " and a height of " << height << " is " << volume << "." << endl;
	}
	else if(type == 2)
	{
		cout << "Input radius: ";
		cin >> radius;
		surface = 4 * pi * pow(radius,2.0);
		cout << "The surface area of a sphere with a radius of " << radius << " is " << surface << "." << endl;
		volume = (4 * pi * pow(radius,3.0) / 3);
		cout << "The volume of a sphere with a radius of " << radius << " is " << volume << "." << endl;
	}
	else
	{
		cout << "Invalid choice!\n";
	}
	system("pause");
	return 0;
}