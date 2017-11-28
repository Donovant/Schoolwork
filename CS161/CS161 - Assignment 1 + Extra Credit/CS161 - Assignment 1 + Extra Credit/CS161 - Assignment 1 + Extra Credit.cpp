//
// Assignment 1
// Donovan Torgerson
// Donovan@Bitzpc.com
// 8/29/11
//


#include <iomanip>
#include <iostream>

using namespace std;

class gastank
{
private:
	int size;
	int currentLvl;
	int level;
	bool light;

public:

	gastank()
	{
		size = 20;
		currentLvl = 0;
		level = 0;
		light = 0;
	}

	gastank(int size)
	{
		this->size = size;
		currentLvl = 0;
		level = 0;
		light = 0;
	}

	int fill()
	{
		int gallonsFilled = size - currentLvl;
		level = 100;
		currentLvl = size;
		return gallonsFilled;
	}

	int fill(int amt)
	{
		if(amt > (size-currentLvl))
		{
			cout << "Error: Amount entered exceeds size of tank" << endl;
			cout << "Amount to top off tank (" << (size - currentLvl) << " gallons) will be added." << endl;
			amt = size - currentLvl;
		}

		if(amt < 0)
		{
			cout << "Error: Cannot use negative number, no fuel is being added." << endl;
			amt = 0;
		}

		int gallonsFilled = amt;
		level = (gallonsFilled * 100) / float(size);
		currentLvl += gallonsFilled;
		return gallonsFilled;
	}

	void used(int gone)
	{
		currentLvl -= gone;
	}

	int lowFuel()
	{
		if(currentLvl <= (size * 0.25))
			return true;
		else
			return false;
	}

	int left()
	{
		return currentLvl;
	}
};


void main() 
{ 
	int amt = 0;
	gastank tank1; 
    gastank tank2(5); 
	cout << "Gallons filled tank 1 -> " << tank1.fill() << endl;
	cout << "How many gallons would you like to add to tank 2? ";
	cin >> amt;
    cout << "Gallons filled tank 2 -> " << tank2.fill(amt) << endl; 

    tank1.used(10); 

    if (tank1.lowFuel()) 
    { 
        cout << "Low fuel light" << endl; 
        cout << "Gallons left ->" << tank1.left() << endl; 
    } 
    else 
        cout << "Fuel OK" << endl; 

    tank1.used(6);
	
  if (tank1.lowFuel()) 
    { 
        cout << "Low fuel light" << endl; 
        cout << "Gallons left -> " << tank1.left() << endl; 
    } 
    else 
        cout << "Fuel OK" << endl; 

  cout << "Gallons filled tank 1 -> " << tank1.fill() << endl;
  cout << "How many gallons would you like to add to tank 2? ";
  cin >> amt;
  cout << "Gallons filled tank 2 -> " << tank2.fill(amt) << endl; 
  system("pause");
}