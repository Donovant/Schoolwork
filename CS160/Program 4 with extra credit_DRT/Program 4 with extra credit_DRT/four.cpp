//
// Donovan Torgerson
// Assignment 4
// September 23, 2010
//
//
//

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int sumdm; //sum day/month
	int sumy;
	int sumcy; //sum century/year
	float day;
	int month;
	float monthnumber;
	int year, yr, century;
	int total1, total2, total;
	int centnum;
	int remainder = 0;
	cout << "Input Day: ";
	cin >> day;
	cout << "Input Month: ";
	cin >> month;
	cout << "Input Year: ";
	cin >> year;

	century = year/100;
	yr = year - (century*100);

	switch(month)
	{
	case 1:
	case 10:
		{
			monthnumber = 0;
			break;
		}
	case 5:
		{
			monthnumber = 1;
			break;
		}
	case 8:
		{
			monthnumber = 2;
			break;
		}
	case 2:
	case 3:
	case 11:
		{
			monthnumber = 3;
			break;
		}
	case 6:
		{
			monthnumber = 4;
			break;
		}
	case 9:
	case 12:
		{
			monthnumber = 5;
			break;
		}
	case 4:
	case 7:
		{
			monthnumber = 6;
			break;
		}
	}
	
switch(century)
	{
	case 8:
	case 12:
	case 16:
	case 20:
		{
			centnum = 0;
			break;
		}
	case 5:
	case 9:
	case 13:
	case 17:
	case 21:
		{
			centnum = 5;
			break;
		}
	case 6:
	case 10:
	case 14:
	case 18:
	case 22:
		{
			centnum = 3;
			break;
		}
	case 7:
	case 11:
	case 15:
	case 19:
	case 23:
		{
			centnum = 1;
			break;
		}
}

total1 = day + monthnumber;

if(total1 > 6)
{
	sumdm = total1/7;
	sumdm = sumdm*7;
	total1 = total1 - sumdm;
}
else
{
	
}

sumy = yr/28;
sumcy = sumy * 28;
sumy = yr - sumcy;
sumcy = sumy/4;
total2 = sumy + sumcy + centnum;

total = total1 + total2;
total = total-((total/7)*7);

if((year%100 == 0 && year%400 == 0) ||  (year%4 == 0)) // leap year
{
	if(month == 1 || month == 2) //if month is January or February
	{
		total -= 1;
	}
	else // if month is NOT January or February
	{

	}
}
else // non-leap year
{

}


if(total == 1)
{
	if(month == 1)
	{
		cout << "January " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 2)
	{
		cout << "February " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 3)
	{
		cout << "March " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 4)
	{
		cout << "April " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 5)
	{
		cout << "May " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 6)
	{
		cout << "June " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 7)
	{
		cout << "July " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 8)
	{
		cout << "August " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 9)
	{
		cout << "September " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 10)
	{
		cout << "October " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else if(month == 11)
	{
		cout << "November " << day << ", " <<  year << " was a Sunday." << endl;
	}
	else
	{
		cout << "December " << day << ", " <<  year << " was a Sunday." << endl;
	}
}
else if(total == 2)
{
	if(month == 1)
	{
		cout << "January " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 2)
	{
		cout << "February " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 3)
	{
		cout << "March " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 4)
	{
		cout << "April " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 5)
	{
		cout << "May " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 6)
	{
		cout << "June " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 7)
	{
		cout << "July " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 8)
	{
		cout << "August " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 9)
	{
		cout << "September " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 10)
	{
		cout << "October " << day << ", " <<  year << " was a Monday." << endl;
	}
	else if(month == 11)
	{
		cout << "November " << day << ", " <<  year << " was a Monday." << endl;
	}
	else
	{
		cout << "December " << day << ", " <<  year << " was a Monday." << endl;
	}
}
else if(total == 3)
{
	if(month == 1)
	{
		cout << "January " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 2)
	{
		cout << "February " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 3)
	{
		cout << "March " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 4)
	{
		cout << "April " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 5)
	{
		cout << "May " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 6)
	{
		cout << "June " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 7)
	{
		cout << "July " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 8)
	{
		cout << "August " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 9)
	{
		cout << "September " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 10)
	{
		cout << "October " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else if(month == 11)
	{
		cout << "November " << day << ", " <<  year << " was a Tuesday." << endl;
	}
	else
	{
		cout << "December " << day << ", " <<  year << " was a Tuesday." << endl;
	}
}
else if(total == 4)
{
	if(month == 1)
	{
		cout << "January " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 2)
	{
		cout << "February " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 3)
	{
		cout << "March " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 4)
	{
		cout << "April " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 5)
	{
		cout << "May " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 6)
	{
		cout << "June " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 7)
	{
		cout << "July " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 8)
	{
		cout << "August " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 9)
	{
		cout << "September " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 10)
	{
		cout << "October " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else if(month == 11)
	{
		cout << "November " << day << ", " <<  year << " was a Wednesday." << endl;
	}
	else
	{
		cout << "December " << day << ", " <<  year << " was a Wednesday." << endl;
	}
}
else if(total == 5)
{
	if(month == 1)
	{
		cout << "January " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 2)
	{
		cout << "February " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 3)
	{
		cout << "March " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 4)
	{
		cout << "April " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 5)
	{
		cout << "May " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 6)
	{
		cout << "June " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 7)
	{
		cout << "July " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 8)
	{
		cout << "August " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 9)
	{
		cout << "September " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 10)
	{
		cout << "October " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else if(month == 11)
	{
		cout << "November " << day << ", " <<  year << " was a Thursday." << endl;
	}
	else
	{
		cout << "December " << day << ", " <<  year << " was a Thursday." << endl;
	}
}
else if(total == 6)
{
	if(month == 1)
	{
		cout << "January " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 2)
	{
		cout << "February " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 3)
	{
		cout << "March " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 4)
	{
		cout << "April " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 5)
	{
		cout << "May " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 6)
	{
		cout << "June " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 7)
	{
		cout << "July " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 8)
	{
		cout << "August " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 9)
	{
		cout << "September " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 10)
	{
		cout << "October " << day << ", " <<  year << " was a Friday." << endl;
	}
	else if(month == 11)
	{
		cout << "November " << day << ", " <<  year << " was a Friday." << endl;
	}
	else
	{
		cout << "December " << day << ", " <<  year << " was a Friday." << endl;
	}
}
else if(total == 0 || total == 7)
{
	if(month == 1)
	{
		cout << "January " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 2)
	{
		cout << "February " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 3)
	{
		cout << "March " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 4)
	{
		cout << "April " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 5)
	{
		cout << "May " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 6)
	{
		cout << "June " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 7)
	{
		cout << "July " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 8)
	{
		cout << "August " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 9)
	{
		cout << "September " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 10)
	{
		cout << "October " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else if(month == 11)
	{
		cout << "November " << day << ", " <<  year << " was a Saturday." << endl;
	}
	else
	{
		cout << "December " << day << ", " <<  year << " was a Saturday." << endl;
	}
}


system("pause");
return 0;

}