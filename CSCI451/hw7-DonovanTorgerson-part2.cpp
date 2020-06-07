/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw7.txt

*/

#include <sys/time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <pthread.h>

using namespace std;

#define SIZE 12

/*Part 2:
-------
Write a program that benchmarks:

B) Once 10 pages have been loaded:
   1] Randomly write one of those loaded pages out to the disk
	  using the same filename, but with a different extension
	  (.data.swaps). No usleep allowed here;
   2] Randomly read one of the 1000 files, calling usleep(1)
	  again;
   3] Randomly read in one of the .swaps files. No usleep
	  allowed here;

   *] Repeat this process until your program has read in
	  500 of the 1000 pages.

Your code must return the number of milliseconds required to run.

This program attempts to benchmark the cost of loading our
initial pages from the filesystem, but then uses the swaps partition
for page faults whenever possible.
*/

int files[SIZE];
int swaps[SIZE];

int checkFilesArray(int incoming)
{
	int arrayLocation = 0;
	while (arrayLocation <= SIZE - 1)
	{
		if (incoming == files[arrayLocation])
		{
			return arrayLocation;
		}
		arrayLocation++;
	}
	return -1;
}

int checkSwapArray(int incoming)
{
	int arrayLocation = 0;
	while (arrayLocation <= SIZE - 1)
	{
		if (incoming == swaps[arrayLocation])
		{
			return arrayLocation;
		}
		arrayLocation++;
	}
	return -1;
}

int getFreeFilesSlot()
{
	int arrayLocation = 0;
	while (arrayLocation <= SIZE - 1)
	{
		if (files[arrayLocation] == -1)
		{
			return arrayLocation;
		}
		arrayLocation++;
	}
	return -1;
}

int getFreeSwapSlot()
{
	int arrayLocation = 0;
	while (arrayLocation <= SIZE - 1)
	{
		if (swaps[arrayLocation] == -1)
		{
			return arrayLocation;
		}
		arrayLocation++;
	}
	return -1;
}

int main()
{
	int dataFileID = -1, initialCounter = 1, secondaryCounter = 0, writeOut = -1, x = 0;
	ofstream outFile;
	ifstream inFile;
	struct timeval startTime;
	struct timeval endTime;
	string filename;
	const string fileStart = "hw7-";
	const string dataEnd = ".data";
	const string swapEnd = ".swap.data";
	srand(time(NULL));
	ostringstream convert;

	for (int i = 0; i < SIZE; ++i)
	{
		files[i] = -1;
		swaps[i] = -1;
	}

	gettimeofday(&startTime, NULL);

	while (initialCounter <= 10)
	{
		dataFileID = rand() % 1000;
		while (checkFilesArray(dataFileID) != -1)
		{
			dataFileID = rand() % 1000;
		}
		cout << "Random number is " << dataFileID << endl;
		files[getFreeFilesSlot()] = dataFileID;
		filename = fileStart;
		convert << dataFileID;
		filename += convert.str();
		filename += dataEnd;
		initialCounter++;
		secondaryCounter++;
		filename = "";
		convert.clear();
		convert.str("");
		usleep(1);
	}

	x = 0;
	while (x <= SIZE - 1)
	{
		cout << "files[" << x << "] = " << files[x] << endl;
		x++;
	}

	while (secondaryCounter <= SIZE - 1)
	{
		writeOut = rand() % initialCounter;
		while (files[writeOut] == -1)
		{
			writeOut = rand() % initialCounter;
		}
		cout << "writeOut is " << writeOut << " and swap while Random number is " << files[writeOut] << endl;
		swaps[getFreeSwapSlot()] = files[writeOut];
		filename = fileStart;
		convert << files[writeOut];
		cout << "Convert: " << convert.str() << endl;
		filename += convert.str();
		filename += swapEnd;
		cout << "Filename " << filename << endl;
		files[writeOut] = -1;
		secondaryCounter++;
		outFile.open(filename.c_str());
		outFile << filename.c_str() << endl;
		outFile.close();
		filename = "";
		cout << "Filename " << filename << endl;

		dataFileID = rand() % 1000;
		while (checkFilesArray(dataFileID) != -1)
		{
			dataFileID = rand() % 1000;
		}
		cout << "Random number is " << dataFileID << endl;
		files[getFreeFilesSlot()] = dataFileID;
		filename = fileStart;
		convert << dataFileID;
		filename += convert.str();
		filename += dataEnd;
		initialCounter++;
		filename = "";
		convert.clear();
		convert.str("");
		usleep(1);
	}

	x = 0;
	while (x <= SIZE - 1)
	{
		cout << "files[" << x << "] = " << files[x] << endl;
		x++;
	}

	x = 0;
	while (x <= SIZE - 1)
	{
		cout << "swaps[" << x << "] = " << swaps[x] << endl;
		x++;
	}

	cout << "secondary counter is: " << secondaryCounter << endl;

	gettimeofday(&endTime, NULL);
	float duration = (endTime.tv_sec - startTime.tv_sec) + (endTime.tv_usec - startTime.tv_usec);
	cout << "time to run: " << duration / 1000 << " milliseconds" << endl;
	return 0;
}
