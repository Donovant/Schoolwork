/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Program is written using dynamic array of structures as the original assignment asked.
	I only have 1 sort function for ascending and 1 for descending and then a seperate function
	for the print out (printf) portion.

	******************************************************
	HW-2-b	CS230	20 points	Due: Sept. 14
	******************************************************

	You have just bombed a test and feel humiliated.
	To add insult to injury, your neighbor's dog now
	growls at you, your mother will not return your
	calls, and President Obama mistakenly used your
	name when referring to Iran's nuclear energy
	program during a speech on national television.

	Well,

	here is your chance

	to

	redeem yourself.


	Part 1:
	-------
	Write a program that provides the user with a simple
	menu that includes the following options:
	 1. Sort data by the float value & print high to low
	 2. Sort data by the float value & print low to high
	 3. Sort data by the int value & print high to low
	 4. Sort data by the int value & print low to high
	 5. Exit

	Of course, the menu must repeatedly be displayed until
	the user selects the ?exit? option. You will need an
	infinite loop to accomplish ths.

	The only thing allowed in the main routine is the code
	required to handle the menu and calls to functions to
	read the data and sort it.

	Part 2:
	-------
	For menu options 1, 2, 3 & 4 your program must call a
	function that opens a file of unknown size and stores
	the data in a array of struct***. The file will
	be called hw4.data. The file will contain a string, a
	float, an int and string. Below is a sample file:

	   F150 5.4 28000 white
	   RAM1500 5.7 32000 orange

	The code to handle this MUST be a function separate from
	the main routine.

	*** You can assume that the file will contain no more than
	100 entries.


	Part 3:
	-------
	For menu options 1, 2, 3 & 4 your program must call a
	function that sorts the data HIGH TO LOW by the appropriate
	component. Since we are sorting the data by 2 different
	components you are allowed to have 2 different sort
	functions. But, ONLY 2!

	Part 4:
	-------
	For menu options 1, 2, 3 & 4 your program must call a
	function that prints the resulting data. Since you must
	print the data high to low or low to high, you are allowed
	to have 2 routines. But, only 2!

	REQUIREMENTS:
	-------------
	1. Your program must run in Streibel 115/109 or on Gandalf.aero.und.edu.

	2. Your full name must appear as a comment at the beginning of your
	   program.

	3. Your source code must be named hw2-yourname.c

	3. Email your source (subject hw2-yourname) to <<Redacted>>
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
	char one[10];
	float two;
	int three;
	char four[8];
} data;

data *input = NULL;

void display(int y)
{
	int i;
	for (i = 0; i < y; i++)
	{
		printf("\n%s\n", input[i].one);
		printf("%.1f\n", input[i].two);
		printf("%d\n", input[i].three);
		printf("%s\n", input[i].four);
	}
	printf("\n");
}

int fillArray()
{
	int x = 0, lines = 0;
	char line[1024];
	FILE *incData;
	incData = fopen("hw4.data", "r");
	if (incData == NULL) exit(0); //trap file not opened
	while (fgets(line, sizeof(line), incData) != NULL) //Gets number of lines of file
	{
		lines++;
	}
	rewind(incData);
	void *_tmp = realloc(input, (lines * sizeof(data)));
	if (!_tmp)
	{
		fprintf(stderr, "Couldn't reallocate memory!\n");
	}
	input = (data*)_tmp;
	if (incData != NULL)
	{

		for (x = 0; x < lines; x++)
		{
			if (fscanf(incData, "%s%f%d%s", input[x].one, &input[x].two, &input[x].three, input[x].four) != EOF)
			{
			}
		}
		display(lines);
	}
	fclose(incData);
	return lines;
}

void sortDes(int y, char opt)
{
	int i, j, max;
	data *temp = NULL;
	void *_tmp = realloc(temp, (1 * sizeof(data)));
	temp = (data*)_tmp;
	if (opt == '3') // Mileage sort high to low
	{
		for (i = 0; i < y; i++)
		{
			max = i;
			for (j = i + 1; j < y; j++)
			{
				if (input[j].three > input[max].three)
				{
					max = j;
				}
			}
			temp[0] = input[i];
			input[i] = input[max];
			input[max] = temp[0];
		}
	}
	if (opt == '1') // Engine size sort high to low
	{
		for (i = 0; i < y; i++)
		{
			max = i;
			for (j = i + 1; j < y; j++)
			{
				if (input[j].two > input[max].two)
				{
					max = j;
				}
			}
			temp[0] = input[i];
			input[i] = input[max];
			input[max] = temp[0];
		}
	}
	display(y);
	free(temp);
}

void sortAsc(int y, char opt)
{
	int k, l, min;
	data *temp = NULL;
	void *_tmp = realloc(temp, (1 * sizeof(data)));
	temp = (data*)_tmp;
	if (opt == '4') // Mileage sort low to high
	{
		for (k = 0; k < y; k++)
		{
			min = k;
			for (l = k + 1; l < y; l++)
			{
				if (input[l].three < input[min].three)
				{
					min = l;
				}
			}
			temp[0] = input[k];
			input[k] = input[min];
			input[min] = temp[0];
		}
	}
	if (opt == '2') // Engine size sort low to high
	{
		for (k = 0; k < y; k++)
		{
			min = k;
			for (l = k + 1; l < y; l++)
			{
				if (input[l].two < input[min].two)
				{
					min = l;
				}
			}
			temp[0] = input[k];
			input[k] = input[min];
			input[min] = temp[0];
		}
	}
	display(y);
	free(temp);
}

int main()
{
	char opt[2];
	int y;
	y = fillArray();
	do
	{
		printf("1. Sort data by the float value & print high to low\n");
		printf("2. Sort data by the float value & print low to high\n");
		printf("3. Sort data by the int value & print high to low\n");
		printf("4. Sort data by the int value & print low to high\n");
		printf("5. Exit\n");
		scanf("%c%c", &opt[0], &opt[1]);
		printf("\n");
		switch (opt[0])
		{
		case '1':
		case '3':
			sortDes(y, opt[0]);
			break;
		case '2':
		case '4':
			sortAsc(y, opt[0]);
			break;
		}
	} while (opt[0] != '5');
	free(input);
	return 0;
}
