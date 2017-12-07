/*In option 1 and 2 if the stack throws a stack full error the following menu should appear.

A)    Throw away new item.   //  The item they tried to add is thrown away.
B)    Throw away top item.   //  The top item is thrown away and the new value is added to the top.
C)    Throw away bottom item. // The bottom item is thrown away and the new value is added to the top.

After the user selects (A, B, or C) the program should go back to the main menu.

When the user quits remove and display the remaining items in the stack.

*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

enum stacktype {Full,Empty};
class StackError
{
public:
	stacktype m_error;

	StackError(stacktype error)
	{ 
		m_error = error;
	}
	stacktype get()
	{
		return m_error;
	}
};

template <class t>
class stack
{
public:
	stack()					//	Default constructor. Creates a stack that holds five items.
	{
		size = 5;
		theArray = new t[size];
		top = -1;
	}

	stack(int tSize)			// Constructor. Creates a stack that holds size items.
	{
		size = tSize;
		theArray = new t[size];
		top = -1;
	}

	~stack()
	{
		delete [] theArray;
	}

	t Pop()					// This procedure should return the top item of the stack.
	{						//  This procedure should throw an exception if the stack is empty.
		if(isEmpty())
		{
			throw new StackError(Empty);			
		}
		t temp = theArray[top];
		theArray[top] = NULL;
		top --;
		return temp;
	}

	t RemoveItemFromBottom();  // This procedure removes the item from the bottom.

	void push(t item)		// This procedure should put the new item on the top of the stack.
	{						// This procedure should throw an exception if the stack is full.
		if(top+1 > size-1)
		{
			throw new StackError(Full);			
		}
		top++;
		theArray[top] = item;
	}

	bool isEmpty();			// Returns (true) if the stack is empty.

	int returnTop()
	{
		return top;
	}

private:
	int size;
	int top;
	t * theArray;
};

template <class t>
t stack<t>::RemoveItemFromBottom()
{
	t temp = theArray[0];
	for(int x = 0; x < size; x++)
	{
		theArray[x] = theArray[x+1];
	}
	theArray[top] = NULL;
	top --;
	return temp;
}

template <class t>
bool stack<t>::isEmpty()
{
	bool temp = false;
	if(top == -1)
	{
		temp = true;
	}
	return temp;
}

void main()
{
	int tInt = NULL;
	char tChar = NULL;
	int option = 0;
	char cOption = NULL;
	int sSize = 0;
	stack<int> intStack;
	stack<char> charStack(7);

	do{
		cout << "Please select one of the following options" << endl; 
		cout << "1)    Add an item to the integer stack." << endl;
		cout << "2)    Add an item to the character stack." << endl;
		cout << "3)    Remove and display top item of integer stack." << endl;
		cout << "4)    Remove and display top item of character stack" << endl;
		cout << "5)    Quit" << endl;
		cout << "Enter Selection: ";
		cin >> option;
		cout << endl;
		switch(option)
		{
		case 1:		// Add to intStack
			try
			{
				cout << "Enter integer to add: ";
				cin >> tInt;
				intStack.push(tInt);
			}catch(StackError * e)
			{
				cout << "Stack is full!!!\n" << endl;
				do{
					cout << "A)    Throw away new item." << endl;  //  The item they tried to add is thrown away.
					cout << "B)    Throw away top item." << endl;   //  The top item is thrown away and the new value is added to the top.
					cout << "C)    Throw away bottom item." << endl; // The bottom item is thrown away and the new value is added to the top.
					cout << "Enter Selection: ";
					cin >> cOption;
					cout << endl;
					switch(cOption)
					{
					case 'a':
					case 'A':
						cout << tInt << " was discarded.\n" << endl;
						break;
					case 'b':
					case 'B':
						cout << intStack.Pop() << " was discarded from top of stack.\n" << endl;
						intStack.push(tInt);
						break;
					case 'c':
					case 'C':
						cout << intStack.RemoveItemFromBottom() << " was discarded from bottom of stack.\n" << endl;
						intStack.push(tInt);
						break;
					}
				}while((cOption < 'a' && cOption > 'c') || (cOption < 'A' && cOption > 'C'));
				delete e;
			};
			break;
		case 2:		// Add to charStack
			try
			{
				cout << "Enter char to add: ";
				cin >> tChar;
				charStack.push(tChar);
			}catch(StackError * e)
			{
				cout << "Stack is full!!!" << endl;
				do{
					cout << "A)    Throw away new item." << endl;  //  The item they tried to add is thrown away.
					cout << "B)    Throw away top item." << endl;   //  The top item is thrown away and the new value is added to the top.
					cout << "C)    Throw away bottom item." << endl; // The bottom item is thrown away and the new value is added to the top.
					cout << "Enter Selection: ";
					cin >> cOption;
					cout << endl;
					switch(cOption)
					{
					case 'a':
					case 'A':
						cout << tChar << " was discarded.\n" << endl;
						break;
					case 'b':
					case 'B':
						cout << charStack.Pop() << " was discarded from top of stack.\n" << endl;
						charStack.push(tChar);
						break;
					case 'c':
					case 'C':
						cout << charStack.RemoveItemFromBottom() << " was discarded from bottom of stack.\n" << endl;
						charStack.push(tChar);
						break;
					}
				}while((cOption < 'a' && cOption > 'c') || (cOption < 'A' && cOption > 'C'));
				delete e;
			};
			break;
		case 3:		// Remove and display from top of intStack
			try
			{
				cout << intStack.Pop() << " was discarded from top of stack.\n" << endl;
			}catch(StackError * e)
			{
				cout << "Stack is empty!!!\n" << endl;
				delete e;
			}
			break;
		case 4:		// Remove and display from top of charStack
			try
			{
				cout << charStack.Pop() << " was discarded from top of stack.\n" << endl;
			}catch(StackError * e)
			{
				cout << "Stack is empty!!!" << endl;
				delete e;
			}

			break;
		}
}while(option != 5);

for(int x = charStack.returnTop(); x > -1; x--)
{
	cout << charStack.Pop() << endl;
}

for(int x = intStack.returnTop(); x > -1; x--)
{
	cout << intStack.Pop() << endl;
}

system("pause");
}