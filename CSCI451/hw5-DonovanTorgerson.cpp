/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw5.txt

*/

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

bool doneMichele, donePaul, doneRob, doneTim, doneVern;

int balance = 0, incAmt = 0, tmpBalance = 0;

ifstream inMichele, inPaul, inRob, inTim, inVern;

pthread_mutex_t balanceMutex = PTHREAD_MUTEX_INITIALIZER;
string incString = "00000000";

void *Michele(void *ptr)
{
	inMichele.open("Michele.in", ios::in);
	for (;;)
	{
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneMichele == false)
		{
			while (!inMichele.eof())
			{
				getline(inMichele, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					balance += tmpBalance;
					tmpBalance = 0;
					incString = "00000000";
					cout << "Balance after Michele: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					sleep(1);
					break;
				}
				else
				{
					//cout << "Michele incString: " << incString << endl;
					stringstream(incString) >> incAmt;
					incString = "00000000";
					tmpBalance += incAmt;
				}
			}
			if (inMichele.eof())
			{
				doneMichele = true;
				tmpBalance = 0;
				sleep(1);
				if (doneMichele && donePaul && doneRob && doneTim && doneVern)
				{
					pthread_mutex_lock(&balanceMutex);
					cout << "Balance after Michele: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
				}
				inMichele.close();
				pthread_exit(NULL);
			}
		}
	}
}

void *Paul(void *ptr)
{
	inPaul.open("Paul.in", ios::in);
	for (;;)
	{
		if (pthread_mutex_trylock(&balanceMutex) == 0 && donePaul == false)
		{
			while (!inPaul.eof())
			{
				getline(inPaul, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					balance += tmpBalance;
					tmpBalance = 0;
					incString = "00000000";
					cout << "Balance after Paul: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					sleep(1);
					break;
				}
				else
				{
					//cout << "Paul incString: " << incString << endl;
					stringstream(incString) >> incAmt;
					incString = "00000000";
					tmpBalance += incAmt;
				}
			}
			if (inPaul.eof())
			{
				donePaul = true;
				tmpBalance = 0;
				sleep(1);
				if (doneMichele && donePaul && doneRob && doneTim && doneVern)
				{
					pthread_mutex_lock(&balanceMutex);
					cout << "Balance after Paul: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
				}
				inPaul.close();
				pthread_exit(NULL);
			}
		}
	}
}

void *Rob(void *ptr)
{
	inRob.open("Rob.in", ios::in);
	for (;;)
	{
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneRob == false)
		{
			while (!inRob.eof())
			{
				getline(inRob, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					balance += tmpBalance;
					tmpBalance = 0;
					incString = "00000000";
					cout << "Balance after Rob: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					sleep(1);
					break;
				}
				else
				{
					//cout << "Rob incString: " << incString << endl;
					stringstream(incString) >> incAmt;
					incString = "00000000";
					tmpBalance += incAmt;
				}
			}
			if (inRob.eof())
			{
				doneRob = true;
				tmpBalance = 0;
				sleep(1);
				if (doneMichele && donePaul && doneRob && doneTim && doneVern)
				{
					pthread_mutex_lock(&balanceMutex);
					cout << "Balance after Rob: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
				}
				inRob.close();
				pthread_exit(NULL);
			}
		}
	}
}

void *Tim(void *ptr)
{
	inTim.open("Tim.in", ios::in);
	for (;;)
	{
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneTim == false)
		{
			while (!inTim.eof())
			{
				getline(inTim, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					balance += tmpBalance;
					tmpBalance = 0;
					incString = "00000000";
					cout << "Balance after Tim: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					sleep(1);
					break;
				}
				else
				{
					//cout << "Tim incString: " << incString << endl;
					stringstream(incString) >> incAmt;
					incString = "00000000";
					tmpBalance += incAmt;
				}
			}
			if (inTim.eof())
			{
				doneTim = true;
				tmpBalance = 0;
				sleep(1);
				if (doneMichele && donePaul && doneRob && doneTim && doneVern)
				{
					pthread_mutex_lock(&balanceMutex);
					cout << "Balance after Tim: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
				}
				inTim.close();
				pthread_exit(NULL);
			}
		}
	}
}

void *Vern(void *ptr)
{
	inVern.open("Vern.in", ios::in);
	for (;;)
	{
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneVern == false)
		{
			while (!inVern.eof())
			{
				getline(inVern, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					balance += tmpBalance;
					tmpBalance = 0;
					incString = "00000000";
					cout << "Balance after Vern: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					sleep(1);
					break;
				}
				else
				{
					//cout << "Vern incString: " << incString << endl;
					stringstream(incString) >> incAmt;
					incString = "00000000";
					tmpBalance += incAmt;
				}
			}
			if (inVern.eof())
			{
				doneVern = true;
				tmpBalance = 0;
				sleep(1);
				if (doneMichele && donePaul && doneRob && doneTim && doneVern)
				{
					pthread_mutex_lock(&balanceMutex);
					cout << "Balance after Vern: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
				}
				inVern.close();
				pthread_exit(NULL);
			}
		}
	}
}

int main()
{
	doneMichele = donePaul = doneRob = doneTim = doneVern = false;
	pthread_t threadMichele, threadPaul, threadRob, threadTim, threadVern;
	pthread_create(&threadMichele, NULL, &Michele, NULL);
	pthread_create(&threadPaul, NULL, &Paul, NULL);
	pthread_create(&threadRob, NULL, &Rob, NULL);
	pthread_create(&threadTim, NULL, &Tim, NULL);
	pthread_create(&threadVern, NULL, &Vern, NULL);

	pthread_join(threadMichele, NULL);
	pthread_join(threadPaul, NULL);
	pthread_join(threadRob, NULL);
	pthread_join(threadTim, NULL);
	pthread_join(threadVern, NULL);
	return 0;
}
