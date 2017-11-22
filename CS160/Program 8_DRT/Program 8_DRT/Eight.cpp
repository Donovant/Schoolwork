//
// Donovan Torgerson
// Assignment 8
// October 29, 2010
//

#include <iostream>

using namespace std;

void fillArray(int count, int numArray[], const int length) // Menu option 1, fill the array. If the array is full, return "Memory Full" message.
{
	if (count != length)
	{
		cout << "Input number: ";
		cin >> numArray[count];
	}
	else
		cout << "\nMemory Full!\n\n";
}

void sort(int numArray[], const int length, bool &sorted) // Menu option 2, sort the contents of the array, return the sorted array and turn sorted bool to true.
{
	int tmp, min, mini =0;
	for(int x = 0; x < length - 1; x++)
	{
		min = numArray[x];
		mini = x;
		for(int y = x +1; y < length; y++)
		{
			if(numArray[y] < min)
			{
				min = numArray[y];
				mini = y;
			}
		}
		if(min < numArray[x])
		{
			tmp = numArray[x];
			numArray[x] = min;
			numArray[mini] = tmp;
		}
	}
	sorted = true;
}

void output(int numArray[], const int length, bool sorted) // Menu option 3, output contents of the array and weather or not it was sorted.
{
	if(sorted)
	{
		cout << "\nThe sorted list is: \n";
	}
	else
		cout << "\nThe unsorted list is: \n";
	for(int x = 0; x < length; x++)
	{
		cout << numArray[x] << endl;
	}
}

int factorial(int num) // Menu option 7, find the factorial of the given number.
{
	if(num == 0)
		return (1);
	else
		return (num * factorial(num-1));
}

int main()
{
	bool sorted = 0;
	const int length = 10;
	int num = 0;
	int menuVal = 0;
	int count = 0;
	int total = 0;
	int numArray[length];
	
	do
	{
		cout << "MAIN MENU\n";
		cout << "1) Input number\n";
		cout << "2) Sort numbers\n";
		cout << "3) Output numbers\n"; 
		cout << "4) Quit\n";
		cout << "7) Factorial\n";
		cout << "Enter selection: ";
		cin >> menuVal;

		if(menuVal == 1)
		{
			fillArray(count, numArray, length);
			count++;			
		}
		else if(menuVal == 2)
		{
			sort(numArray, length, sorted);
		}	
		else if(menuVal == 3)
		{
			output(numArray, length, sorted);
		}
		else if(menuVal == 7)
		{
			cout << "Enter number: ";
			cin >> num;
			total = factorial(num);
			cout << "The factorial of " << num << " is " << total << ".\n";
		}
	}while(menuVal != 4);
	
	system("pause");
	return 0;
}