//
// Donovan Torgerson
// Assignment 13
// December 9, 2010
//

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


struct node
{
	char name[25];
	node *nxt;        // Points to next node

	node()
	{
		nxt = NULL;
	}
};


int main()
{
	char ch;
	char frntName[25] = {0};
	char bckName[25] = {0};
	node *first, *last, *newNode;
	first = NULL;
	last = NULL;
	newNode = new node;
	int menuVal = 0;
	do
	{
		cout << "1)     Add to the front of the list.\n";
		cout << "2)     Add to the back of the list.\n";
		cout << "3)     Print the list.\n";
		cout << "4)     \n";
		cout << "5)     \n";
		cout << "6)     Quit\n";
		cout << "Enter selection: ";
		cin >> menuVal;
		cout << endl;
		if(menuVal == 1)  // Add to front
		{
			cout << "Insert name to add to front of list: ";
			cin.get(ch);
			cin.get(frntName,25);
			newNode = new node;
			if(first == NULL && last == NULL)
			{
				first = last = newNode;
			}
			else
			{
				newNode->nxt = first;
				first = newNode;
			}
			strcpy(first->name, frntName);
		}
		else if(menuVal == 2)  // Add to back
		{
			cout << "Insert name to add to back of list: ";
			cin.get(ch);
			cin.get(bckName,25);
			newNode = new node;
			if(first == NULL && last == NULL)
			{
				first = last = newNode;
			}
			else
			{
				last->nxt = newNode;
				last = newNode;
			}
			last->nxt = NULL;
			strcpy(last->name, bckName);
		}
		else if(menuVal == 3)  // Print
		{
			node *current;
			current = first;
			while(current != NULL)
			{
				cout << current->name << endl;
				current = current->nxt;
			}
			cout << endl;
		}
		else if(menuVal == 4)
		{
			
		}
		else if(menuVal == 5)
		{
			
		}
	}while(menuVal != 6);

	system("pause");
	return 0;
}