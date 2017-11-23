//
// Donovan Torgerson
// Program 10
// November 24, 2010
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;


/*

void selSort(char words[][255])
{
	for ( int i = 0; i < n - 1; i++ )
	{
		char temp[255];
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if ( strcmp ( words[j], words[min] ) < 0 )
			min = j;
		}
	memcpy ( temp, names[i], 255 );
	memcpy ( names[i], names[min], 255 );
	memcpy ( names[min], temp, 255 );
	}
}
*/





int main()
{
	ifstream inFile("advice.dat");;
	bool found = 0;
	char ch;
	char * words[250];
	char newWord[255];
	int length=0;
	int row = 0;
	int col = 0;
	int wordCount = 0;
	int lineCount = 0;
	int printChar = 0;


	if(inFile.fail())  // If the file doesn't open, output error message.
	{
		cout << "\nThe file was not successfully opened!\n" << endl;
	}
	
	for(int x = 0; x < 250; x++)
	{
		words[x] = new char[255];  // This does the same thing as creating a two-dimensional array off the bat like  char words[250][255].
	}

	while(!inFile.eof())
	{
		inFile.get(ch);
		cout << ch;
		if(ch == 32)
		{
			newWord[col] = 0;
			for(int x = 0; x < row && !found; x++)
			{
				if(strcmp(newWord,words[x]) == 0)
					found = 1;
				if(newWord[0] >= 97) // Swaps first letter between upper and lower case.
					newWord[0] -= 32;
				else
					newWord[0] += 32; 
				if(strcmp(newWord,words[x]) == 0)
					found = 1;
			}
			if(!found)  // If not found, copy newWord to current row of words array.
			{
				strcpy(words[row],newWord);
				row++;
			}
			col = 0;
			found = 0;
			wordCount += 1;
		}
		if(ch == '\n')
		{
			newWord[col] = 0;
			for(int x = 0; x < row && !found; x++)
			{
				if(strcmp(newWord,words[x]) == 0)
					found = 1;
				if(newWord[0] >= 97) // Swaps first letter between upper and lower case.
					newWord[0] -= 32;
				else
					newWord[0] += 32; 
				if(strcmp(newWord,words[x]) == 0)
					found = 1;
			}
			if(!found)  // If not found, copy newWord to current row of words array.
			{
				strcpy(words[row],newWord);
				row++;
			}
			col = 0;
			found = 0;
			wordCount += 1;
			lineCount += 1;
			ch = 0;
		}
		if(!((ch == ' ') || (ch == '\t') || (ch == '\n') || (ch == '\v') || (ch == '\f') || (ch == '\r')))
		{
			if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <=122))
			{
				newWord[col] = ch;
				col++;
			}
			printChar += 1;
			ch = 0;
		}
	}
	if(ch == 32)
	{
		wordCount -= 1;
		row -= 1;
	}
	else
	{
		newWord[col] = 0;
		for(int x = 0; x < row && !found; x++)
			{
				if(strcmp(newWord,words[x]) == 0)
					found = 1;
				if(newWord[0] >= 97) // Swaps first letter between upper and lower case.
					newWord[0] -= 32;
				else
					newWord[0] += 32; 
				if(strcmp(newWord,words[x]) == 0)
					found = 1;
			}
			if(!found)  // If not found, copy newWord to current row of words array.
			{
				strcpy(words[row],newWord);
				row++;
			}
			col = 0;
			found = 0;
			wordCount += 1;
	}

	cout << endl;
	inFile.close();
	cout << "\nWord Count: " << wordCount << endl;
	cout << "Number of printable characters: " << printChar << endl;
	cout << "Line Count: " << lineCount << endl;
	//cout << "Rows: " << row << endl;


	for(int x = 0; x < row; x++)
	{
		if((*words[x] >= 97) && (*words[x] <= 122))
			words[x][0] -= 32;
	}

	for(int i = 0; i < row - 1; i++)
	{
		char temp[255];
		int min = i;
		for (int j = i + 1; j < row; j++)
		{
			if (strcmp(words[j], words[min]) < 0)
			{
				min = j;
			}
		}
	memcpy(temp, words[i], 255);
	memcpy(words[i], words[min], 255);
	memcpy(words[min], temp, 255);
	}
	
	for(int x = 0; x < row; x++)
	{
		if((*words[x] >= 97) && (*words[x] <= 122))
			words[x][0] -= 32;
		cout << words[x] << endl;
	}


	int junk = 0;

	system("pause");
	return 0;
}