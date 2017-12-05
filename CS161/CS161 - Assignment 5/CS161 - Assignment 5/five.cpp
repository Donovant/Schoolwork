//
// Assignment 5
// Donovan Torgerson
// 10/3/11
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class KString
{
	friend istream & operator >> (istream & left, KString & right);
	friend ostream & operator << (ostream & left, KString & right);
	friend bool operator == (KString left, KString right);
	friend bool operator < (KString left, KString right);
	friend bool operator > (KString left, KString right);
private:
	char * nameArray;
	int size;
	int index;
	int growsize;

public:
	KString(const char name[])							// Constructor that is passed in an array of characters.  This constructor should make it possible to do                                                 
	{													//  the following.   Name = "Scott";   In this example Scott is an array of characters.  The computer would 
		size = strlen(name);							// call the constructor which would convert it into a KString and then it would assign it.  This constructor 
		nameArray = new char[size+1];					// Should ask for dynamic memory and then store Scott in it.  It should also set size.		
		strcpy(nameArray, name);
		index = size;
		growsize = 5;
	}
	

	KString(const KString & temp)						// copy constructor
	{
		nameArray = new char[temp.size];
		size = temp.size;
		growsize = temp.growsize;
		index = temp.index;
		for (int x = 0; x < size; x++)
		{
			nameArray[x] = temp.nameArray[x];
		}	
	}

	KString(int len, int grow)
	{
		size = len;
		index = 0;
		growsize = grow;
		nameArray = new char[size];
	}
	
	KString()											// default constructor should just set size to zero.
	{
		size = 10;
		index = 0;
		growsize = 5;
		nameArray = new char[size];
	}

	~KString()											// Destructor, should give dynamic memory back.
	{
		delete [] nameArray;
	}

	void grow()
	{
		char * temp = new char[size + growsize];
		for (int x = 0; x < size; x++)
		{
			temp[x]=nameArray[x];
		}
		delete [] nameArray;
		nameArray = temp;
		size += growsize;
	}

	KString operator = (KString temp)					// This procedure makes it possible to assign one KString equal to another KString. 
	{
		this->size = temp.size;
		delete [] nameArray;
		this->growsize = temp.growsize;
		this->index = temp.index;
		this->size = (temp.size)+1;
		nameArray = new char[size];
		for (int x = 0; x < size; x++)
		{
			nameArray[x] = temp.nameArray[x];
		}
		return *this;
	}

	char & operator [] (int i)							// This overloads the [ ].  This return one character as a lvalue.
	{
		return nameArray[i];
	}

	const char & operator [] (int i) const				// This overloads the [ ].  This return one character as a rvalue. 
	{
		int junk = 0;
	}

	void additem(int item)
	{
		if(index >= size)
		{
			grow();
		}
		nameArray[index++]=item;
	}

	int length()
	{
		return size;
	}

	KString operator + (KString right)				// This makes it possible to add two KStrings together (concatenation). 
	{
		int index = 0;
		KString temp;
		temp.size = right.size + size - 1;
		delete [] temp.nameArray;
		temp.nameArray = new char[temp.size];
		strcat(temp.nameArray, right.nameArray);
		for(int x = 0 ; x < size - 1; x++)
		{
			temp.nameArray[x] = nameArray[x];
			index++;
		}

		for(int x = 0; index < temp.size; x++)
		{
			temp.nameArray[index] = right.nameArray[x];
			index++;
		}
		return temp;
	}

	bool operator == (char name[])
	{
		if((strcmp(nameArray, name) == 0))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};


	bool operator < (KString left, KString right)
	{
		if((strcmp(left.nameArray, right.nameArray) == -1))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


	bool operator > (KString left, KString right)
	{
		if((strcmp(left.nameArray, right.nameArray) == 1))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool operator == (KString left, KString right)
	{
		if((strcmp(left.nameArray, right.nameArray) == 0))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	

	istream & operator >> (istream & left, KString & right)
	{
		char name[1000];
		left >> name;
		int size = strlen(name);
		delete [] right.nameArray;
		right.nameArray = new char[size +1];
		strcpy(right.nameArray, name);
		right.size = size;
		right.index = size;
		return left;
	}


	ostream & operator << (ostream & left, KString & right)
	{
		left << right.nameArray;
		return left;
	}

void main() 
{ 
	KString k1("Scott ");										// Creates a KString initialized to "Scott " 
	KString k2;													// Creates a KString 
	KString k3;													// Creates a KString 
	k2 = "Cast";												// Assigns "Cast" to k2 
	k3 = k1 + k2;												// Concatenates K1 and K2 and assigns to k3 
	cout << k3[5] << endl;										// Prints out the 6 character in k3 (C) 
	k3[5]='K';													// Changes the 6 character from (C) to (K) 
	cout << "Enter your name:";
	cin >> k2;													// you need to overload >> for the KString 
 	if (k1 == k2)                                              // you need to overload == to compare two KStrings. 
		cout << "Same Name"  << endl; 
	if ( k1 < k2)												// you need to overload < to compare two KStrings. 
	cout << "First name less than"  << endl; 
	if ( k1 > k2)												// you need to overload > to compare two KStrings. 
	cout << "First name greater than"  << endl; 
	cout << k2 << " have a nice day!" << endl;					// you need to overload << for the KString
	if (k1 =="Scott")											// Should be able to compare a KString with an array of characters 
	{
		cout << "Nice Name" << endl;
	}
	cout << k1.length() << endl;								// Create the function which returns the size of the KString.  size would be 5 in this example. 
	system("pause");
} 