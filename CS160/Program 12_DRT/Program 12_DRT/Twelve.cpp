//
// Donovan Torgerson
// Assignment 12
// December 1, 2010
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct employee
{
	char name[20];		// 20 bytes
	char phone[15];		// 15 bytes
	char position[25];	// 25 bytes
	float salary;		// 8 bytes
};

void enterInfo(employee Records[], int &size)
{
	char flush[2]; // clears buffer otherwise the first line of data would be skipped.
	cin.getline(flush, 2);
	cout << "Input Name: ";
	cin.getline(Records[size].name,20);
	cout << "Input Phone Number: ";
	cin.getline(Records[size].phone,15);
	cout << "Input Position: ";
	cin.getline(Records[size].position,25);
	cout << "Input Salary: ";
	cin >> Records[size].salary;
	cout << endl;
	size++;
}

void printComplete(employee Records[], int &size) // Prints complete list of employee records.
{
	cout << setw(20) << setiosflags(ios::left) << "Name" << setw(15) << fixed << "Phone Number" << setw(25) << fixed << "Position" << setw(8) << setprecision(2) << fixed << "Salary" <<endl;
	for(int x = 0; x < size; x++)
	{
		cout << setw(20) << setiosflags(ios::left) << Records[x].name << setw(15) << Records[x].phone << setw(25) << fixed << Records[x].position << setw(8) << setprecision(2) << fixed << Records[x].salary <<endl;
	}
	cout << endl;
}

void printConditional(employee Records[], int &size, int salMin) // Prints conditional list of employee records based off input for minimum value of salary.
{
	cout << setw(20) << setiosflags(ios::left) << "Name" << setw(15) << fixed << "Phone Number" << setw(25) << fixed << "Position" << setw(8) << setprecision(2) << fixed << "Salary" <<endl;
	for(int x = 0; x < size; x++)
	{
		if(Records[x].salary >= salMin)
		{
			cout << setw(20) << setiosflags(ios::left) << Records[x].name << setw(15) << Records[x].phone  << setw(25) << fixed << Records[x].position  << setw(8) << setprecision(2) << fixed << Records[x].salary <<endl;
		}
	}
	cout << endl;
}

void bblSort(employee Records[], int size) // Sorts the structures by name.
{
	employee tmp;
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size - x; y++)
		{
			if(strcmp(Records[y].name, Records[y+1].name) > 0)
			{
				tmp = Records[y];
				Records[y] = Records[y+1];
				Records[y+1] = tmp;
			}
		}
	}
}

void selSort(employee Records[], int size) // Sorts the structures by salary.
{
	int minIndex = 0;
	for (int x = 0; x < size; x++)
	{
		minIndex = x;
		for (int y = x + 1; y < size; y++)
		{
			if(Records[y].salary > Records[minIndex].salary)
			{
				minIndex = y;
			}
		}
		employee temp = Records[x];
		Records[x] = Records[minIndex];
		Records[minIndex] = temp;
	}
}


void searchName(employee Records[], int size) // searches for a specified name
{
	bool found = 0;
	employee temp;
	char flush[2]; // clears buffer otherwise the first line of data would be skipped.
	cin.getline(flush, 2);
	cout << "Input Name to search for: ";
	cin.getline(temp.name,20);
	for (int x = 0; x < size; x++)
	{
		if(strcmp(Records[x].name, temp.name) == 0)
		{
			found = 1;
			cout << setw(20) << setiosflags(ios::left) << Records[x].name << setw(15) << Records[x].phone << setw(25) << fixed << Records[x].position << setw(8) << setprecision(2) << fixed << Records[x].salary << endl;
		}
		cout << endl;
	}
	if(found == 0)
	{
		cout << "Not found!\n" << endl;
	}
}

void searchPosition(employee Records[], int size) // searches for specified position held.
{
	bool found = 0;
	employee temp;
	char flush[2]; // clears buffer otherwise the first line of data would be skipped.
	cin.getline(flush, 2);
	cout << "Input Position to search for: ";
	cin.getline(temp.position,25);
	for (int x = 0; x < size; x++)
	{
		if(strcmp(Records[x].position, temp.position) == 0)
		{
			found = 1;
			cout << setw(25) << setiosflags(ios::left) << Records[x].name << setw(15) << Records[x].phone << setw(25) << fixed << Records[x].position << setw(8) << setprecision(2) << fixed << Records[x].salary << endl;
		}
		cout << endl;
	}
	if(found == 0)
	{
		cout << "Selection not found!\n" << endl;
	}
}

void saveFile(employee theEmpl[], int size, char outFile[])
{
	fstream out;
	out.open(outFile, ios::binary | ios::out);
	if(out.is_open())
	{
		out.write((char *) &size, sizeof(int));
		for(int y = 0; y < size; y++)
		{
			out.write((char *) &theEmpl[y], sizeof(employee));
		}
	}
	out.close();
}

void loadFile(employee theEmpl[], int &size, char inFile[])
{
	fstream in;
	in.open(inFile, ios::binary | ios::in);
	while(!in.is_open())
	{
		cout << "File does not exist, please try again.\n";
		break;
	} 
	if(in.is_open())
	{
		in.read((char *) &size, sizeof(int));
		for(int y = 0; y < size; y++)
		{
			in.read((char *) &theEmpl[y], sizeof(employee));
		}
	}
	else
	in.close();
}



int main()
{
	employee theEmpl[10];
	theEmpl[0].name;
	char inFile[30];
	char outFile[30];
	int menuVal = 0;
	int size = 0;
	int salMin = 0;
	do
	{
		cout << "1)     Add new user info\n";
		cout << "2)     Print complete report\n";
		cout << "3)     Print conditional report\n";
		cout << "4)     Sort the data by name\n";
		cout << "5)     Sort the data by salary\n";
		cout << "6)     Search for name\n";
		cout << "7)     Search by position\n";
		cout << "8)     Save\n";
		cout << "9)     Load\n";
		cout << "0)     Quit\n";
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
			cout << "Print user with a salary greater than: ";
			cin >> salMin;
			printConditional(theEmpl, size, salMin);
		}
		else if(menuVal == 4)
		{
			bblSort(theEmpl, size);
		}
		else if(menuVal == 5)
		{
			selSort(theEmpl, size); // Sort by salary
		}
		else if(menuVal == 6)
		{
			searchName(theEmpl, size);
		}
		else if(menuVal == 7)
		{
			searchPosition(theEmpl, size);
		}
		else if(menuVal == 8)
		{
			cout << "Enter filename to save: ";
			cin >> outFile;
			saveFile(theEmpl, size, outFile);
		}
		else if(menuVal == 9)
		{
			cout << "Enter filename to load: ";
			cin >> inFile;
			loadFile(theEmpl, size, inFile);
		}
	}while(menuVal != 0);

	system("pause");
	return 0;
}