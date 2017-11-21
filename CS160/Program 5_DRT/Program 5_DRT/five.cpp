//
// Donovan Torgerson
// Assignment 1
// October 8, 2010
//

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{    
	int Col, Row, Total, StartCol, StartRow, EndCol, EndRow;
	int Count = 0;
	cout << "Enter Starting Column: ";
	cin >> StartCol;
	cout << "Enter Ending Column: ";
	cin >> EndCol;
	cout << "Enter Starting Row: ";
	cin >> StartRow;
	cout << "Enter Ending Row: ";
	cin >> EndRow;
	
	Total = (EndRow * EndCol);
	while(Total > 0) // Sets count to assist with setw spacing
	{
		Total= Total / 10;
		Count += 1;
	}
	cout << setiosflags(ios::left) << setw(Count + 2) << "*";
    for (int Row = StartRow; Row <= EndRow; Row++) // Fills in first row of data
		{
			cout << setw(Count + 2) << Row;
	    }
	    cout << endl;
	for (int Col = StartCol; Col <= EndCol; Col++) // Fills in first column of data
		{
			cout << setw(Count + 2) << Col << "";
		{
		for (int Row = StartRow; Row <= EndRow; Row++) // Fills in rest of multiplication table
		{
			cout << setw(Count + 2) << (Row * Col);
		}
		}
		cout << endl;
		}
    system("pause");
    return 0;
}