//
// Donovan Torgerson
// Assignment 7
// October 25, 2010
//

#include <iostream>;

using namespace std;

void copyString(const char name[], char copy[]) // Procedure that copies the name array to the copy array.
{
	for (int x = 0; x < 20; x++)
		copy[x] = name[x];
}

void calcAverageSum(const int num[], int &sum, int &avg) // Procedure that calculates the sum and average of the values entered.
{
	for(int i = 0; i < 5; i++)
		sum += num[i];
	avg = sum / 5;
}

void upperCase(char name[]) // Procedure that converts the name entered to staggered form with odd numbered indexes being capital letters and even numbered being lowercase.
{
	for(int i = 0; i < 20; i++)
	{
		if(i % 2 != 0)
		{
			if((name[i] >= 65) && (name[i] <= 90))
			{
				name[i] += 32;
			}
			else
			{
			}
		}
		else
		{
			if((name[i] >= 97) && (name[i] <= 122))
			{
				name[i] -= 32;
			}
			else
			{
			}
		}

	}
}

int getStringLength(const char name[]) // Function that calculates the character length of the name.
{
	int length = 0;
	for(int x = 0; name[x] != 0; x++)
		length += 1;
	return length;
}

int main()
{	
	int sum = 0;
	int avg = 0;
	int length; 
	char name[20];
	char copy[20];
	int num[20];
	cout << "Input Name: ";
	cin >> name;
	
	for(int i = 0; i < 5; i++)
	{
		cout << "Input number " << (i+1) << ": ";
		cin >> num[i];
	}
	
	cout << endl;
	length = getStringLength(name);
	copyString(name, copy);
	cout << copy << " is a copy of the name." << endl;
	cout << "The length of the name is " << length << " characters." << endl;
	calcAverageSum(num, sum, avg);
	cout << "The sum of these numbers is " << sum << "." << endl;
	cout << "The average of these numbers is " << avg << "." << endl;
	upperCase(name);
	cout << "The name in staggered form is " << name << "." << endl;
	system("pause");
	return 0;
}
