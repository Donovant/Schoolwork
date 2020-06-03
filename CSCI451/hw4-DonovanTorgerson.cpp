/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw4.txt

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

FILE *inFile;
FILE *outFile;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
int COUNT_DONE, ct = 0, incomingVariable = -99999990, numLines = 1;
 
void *function1(void *ptr)
{
	inFile = fopen("hw4.in", "r");
	for(;;)
	{
		pthread_mutex_lock(&mutex1);
		fscanf(inFile, "%d\n", &incomingVariable);
		ct++;
		pthread_mutex_unlock(&mutex2);
		if(ct >= COUNT_DONE) // || incomingVariable == EOF)
		{
			return(NULL);
		}
	}
}
 
void *function2(void *ptr)
{
	int newNumber;
	string file2String;
    for(;;)
	{
		pthread_mutex_lock(&mutex2);
		if(incomingVariable % 2 == 0 && incomingVariable != -99999990)
		{
			fprintf(outFile, "%d", incomingVariable);
			fprintf(outFile, "\n");
			fprintf(outFile, "%d", incomingVariable);
			fprintf(outFile, "\n");
		}
		else if(incomingVariable != -99999990)
		{
			fprintf(outFile, "%d", incomingVariable);
			fprintf(outFile, "\n");
		}
		ct++;
		if(ct >= COUNT_DONE)
		{
			pthread_mutex_unlock(&mutex1);
			pthread_exit((void*) 0);
			return(NULL);
		}
		pthread_mutex_unlock(&mutex1);
	}
	pthread_exit((void*) 0);
}

int main()
{
	outFile = fopen("hw4.out", "w");
	char c;
	ifstream iF("hw4.in");
	while(iF.good())
	{
		c = iF.get();
		if(c == '\n' || c == iF.eof())
		{
			numLines++;
		}
	}
	iF.close();
	COUNT_DONE = (numLines * 2) - 1;
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &function1, NULL);
	pthread_create(&thread2, NULL, &function2, NULL);
	pthread_join( thread1, NULL);
	pthread_join( thread2, NULL);
	fclose(outFile);
	return 0;
}