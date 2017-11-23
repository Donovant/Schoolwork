//
// Donovan Torgerson
// Assignment 9
// November 1, 2010
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct employee
{
	char name[20];
	char phone[15];
	float salary;
};

void enterInfo(employee Records[], int &size)
{
	char flush[2]; // clears buffer otherwise the first line of data would be skipped.
	cin.getline(flush, 2);
	cout << "Input Name: ";
	cin.getline(Records[size].name,20);
	cout << "Input Phone Number: ";
	cin.getline(Records[size].phone,15);
	cout << "Input Salary: $";
	cin >> Records[size].salary;
	cout << endl;
	size++;
}

void printComplete(employee Records[], int &size) // Prints complete list of employee records.
{
	cout << setw(20) << setiosflags(ios::left) << "Name" << setw(15) << fixed << "Phone Number" << setw(8) << setprecision(2) << fixed << "Salary" <<endl;
	for(int x = 0; x < size; x++)
	{
		cout << setw(20) << setiosflags(ios::left) << Records[x].name << setw(15) << Records[x].phone << setw(8) << setprecision(2) << fixed << Records[x].salary <<endl;
	}
	cout << endl;
}

void printConditional(employee Records[], int &size, int salMin) // Prints conditional list of employee records based off input for minimum value of salary.
{
	cout << setw(20) << setiosflags(ios::left) << "Name" << setw(15) << fixed << "Phone Number" << setw(8) << setprecision(2) << fixed << "Salary" <<endl;
	for(int x = 0; x < size; x++)
	{
		if(Records[x].salary >= salMin)
		{
			cout << setw(20) << setiosflags(ios::left) << Records[x].name << setw(15) << Records[x].phone << setw(8) << setprecision(2) << fixed << Records[x].salary <<endl;
		}
	}
	cout << endl;
}

void bblSort(employee Records[], int size) // Sorts the structures by name.
{
	employee tmp;
	for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
        {
            if((Records[x].name[y]) > (Records[x+1].name[y]))
            {
                tmp = Records[x];
				Records[x] = Records[x+1];
				Records[x+1] = tmp;
            }
        }
}

void payRaise(employee Records[], int &size)
{
	float percent = 0;
	cout << "Enter pay raise percentage: ";
	cin >> percent;
	percent = percent / 100;
	for(int x = 0; x < size; x++)
	{
		if(percent < 1)
		{
			Records[x].salary = Records[x].salary * (percent + 1);
		}
		else
		{
			Records[x].salary = Records[x].salary * (percent);
		}

	}
}

int main()
{
	employee theEmpl[10];
	theEmpl[0].name;
	int menuVal = 0;
	int size = 0;
	int salMin = 0;
	float percent = 0;
	do
	{
		cout << "1)	Add new user info\n";
		cout << "2)	Print complete report\n";
		cout << "3)	Print conditional report\n";
		cout <<	"4)	Sort the data by name\n"; //use bubble sort
		cout <<	"5)	Pay raise\n";
		cout << "7)	Quit\n";
		cout << "Enter selection: ";
		cin >> menuVal;
		cout << endl;
		if(menuVal == 1)
		{
			enterInfo(theEmpl, size);
		}
		else if(menuVal == 2)
		{
			printComplete(theEmpl, size);
		}
		else if(menuVal == 3)
		{
			cout << "Print user with a salary greater than: $";
			cin >> salMin;
			printConditional(theEmpl, size, salMin);
		}
		else if(menuVal == 4)
		{
			bblSort(theEmpl, size);
		}
		else if(menuVal == 5)
		{
			payRaise(theEmpl, size);
		}
	}while(menuVal != 7);

	system("pause");
	return 0;
}