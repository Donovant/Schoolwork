//
// Donovan Torgerson
// Assignment 5 Extra Credit
// October 11, 2010
//


#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int num;
	int number, left, right, sum;
	for(int num = 1000; num < 10000; num++)
	{
		left = num / 100;
		right = num - (left*100);
		sum = left + right;
		for(int number = 1; number <= num; number++)
		{
			if(sum * sum == num)
			{
					cout << num << endl;
					break;
			}
		}
	}


	system("pause");
	return 0;
}