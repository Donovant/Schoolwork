//
// Donovan Torgerson
// Assignment 6
// October 20, 2010
//

#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	int f = 0;
	int l = 0;
	char first[10];
	char last[10];
	char firstCopy[10];
	char fullName[20];
	char name;
	cout << "Enter first name: ";
	cin >> first;
	cout << "Enter last name: ";
	cin >> last;

	for (int x = 0; x < 10; x++)
		firstCopy[x] = first[x];
	
	cout << "Your name is " << first << " and the copy of your first name is " << firstCopy << "." << endl;

	while(first[f] && (first[f] != '\0'))
	{
		fullName[f] = first[f];
		f++;
	}

	while(last[l] && (last[l] != '\0'))
	{
		fullName[f] = last[l];
		l++;
		f++;
	}

	cout << "Your first name is " << first << " and your last name is " << last << " and the concatenation is ";
	for(int x=0; x < 20 && (fullName[x] != 'Ì'); x++)
	{
		cout << fullName[x];
	}

	cout << "." << endl;

	system("pause");
	return 0;
}