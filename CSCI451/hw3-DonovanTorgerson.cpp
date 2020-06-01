/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw3.txt

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>
#include <pthread.h>

using namespace std;

//ifstream inFile1; //("hw3-1.in");
//ifstream inFile2; //("hw3-2.in");

FILE *inFile1;
FILE *inFile2;

ofstream outFile("hw3.out", ios::app);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition = PTHREAD_COND_INITIALIZER;

int  ct = 0;
int incomingVariable = 0;
int variable2 = 0;
int numLines1 = 1;
int numLines2 = 1;

int COUNT_DONE;

void *functionCount1(void *ptr)
{
	for (;;)
	{
		pthread_mutex_lock(&mutex);

		pthread_cond_wait(&condition, &mutex);
		fscanf(inFile1, "%d\n", &incomingVariable);
		ct++;
		printf("Counter value functionCount1: %d\n", ct);

		pthread_mutex_unlock(&mutex);

		if (ct >= COUNT_DONE)
		{
			return(NULL);
		}
	}
}

void *functionCount2(void *ptr)
{
	int newNumber;
	string file2String;
	for (;;)
	{
		pthread_mutex_lock(&mutex);
		if (ct % 2 == 0)
		{
			pthread_cond_signal(&condition);
		}
		else
		{
			fscanf(inFile2, "%d\n", &variable2);
			if (variable2 > incomingVariable)
			{
				outFile << incomingVariable << " " << variable2 << endl;
			}
			else
			{
				outFile << variable2 << " " << incomingVariable << endl;
			}
			ct++;
			cout << "Counter value functionCount2: " << ct << endl;
		}

		pthread_mutex_unlock(&mutex);

		if (ct >= COUNT_DONE)
		{
			pthread_cond_signal(&condition);
			return(NULL);
		}
	}
	pthread_exit((void*)0);
}


int main()
{
	char c;
	ifstream iF1("hw3-1.in");
	ifstream iF2("hw3-2.in");

	while (iF1.good())
	{
		c = iF1.get();
		if (c == '\n')
		{
			numLines1++;
		}
	}
	while (iF2.good())
	{
		c = iF2.get();
		if (c == '\n')
		{
			numLines2++;
		}
	}
	iF1.close();
	iF2.close();
	inFile1 = fopen("hw3-1.in", "r");
	inFile2 = fopen("hw3-2.in", "r");
	COUNT_DONE = numLines1 + numLines2;
	cout << "COUNT_DONE: " << COUNT_DONE << endl;
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &functionCount1, NULL);
	pthread_create(&thread2, NULL, &functionCount2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final count: %d\n", ct);

	return 0;
}