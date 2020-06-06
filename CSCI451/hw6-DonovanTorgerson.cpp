/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw6.txt

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

struct page
{
	page *prev;
	bool taken;
	int r, m;
	string senator;
	page *next;

	page()
	{
		taken = false;
		r = -1;
		m = -1;
		senator = "";
	}
};

page *current, *first, *last, *micheleCurrent, *page1, *page2, *page3, *page4, *page5, *page6, *paulCurrent, *robCurrent, *timCurrent, *vernCurrent;

pthread_mutex_t page1Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t page2Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t page3Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t page4Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t page5Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t page6Mutex = PTHREAD_MUTEX_INITIALIZER;

//pthread_mutex_t  = PTHREAD_MUTEX_INITIALIZER;

/*
 * //	The circular linked list will have 6 entries (can manage 6
 * //	pages) and will be managed by Dianne.
 *
 * //	Each of the 5 little corrupt Senator threads will request
 * //	at least 1 memory page when they are created.
 *
 * //	If the account balance for any thread is negative (after
 * //	ANY "W") the thread will set the R and M bits to 1 for that
 * //	initially loaded page.
 *
 * //	If the account balance for any thread is positive (after
 * //	ANY "W") the thread will set the R bit to 1 for that
 * //	initially loaded page and leave the M bit as it was.
 *
 * //	The ESC-C algorithm must reset all R bits to 0 on occasion
 * //	(I leave this to you to decide).
 *
 *	On occasion (e.g. randomly) each thread will require an
 *	additional page, generating a page fault. At this point the
 *	thread generating the page fault must: 1) print "Page fault in
 *	thread XXX", 2) locate a page to replace and print the details
 *	(R and M bits and ownership) of the page being removed, 3) load
 *	the new page, and 4) set the bits to some initial value (see
 *	notes).
 *
 *	Once more than 1 additional page has been loaded, it is very
 *	likely that a thread will have no pages in memory. That
 *	thread will also generate a page fault whenever it encounters
 *	a "W".
 *
 * //	You will also need a mutex to protect the links in the linked
 * //	list to prevent any possible corruptions of the linked list.
 */

bool doneMichele, donePaul, doneRob, doneTim, doneVern, foundMichele, foundPaul, foundRob, foundTim, foundVern, freePageMichele, freePagePaul, freePageRob, freePageTim, freePageVern, pageReplacedMichele, pageReplacedPaul, pageReplacedRob, pageReplacedTim, pageReplacedVern;

int balance = 0, incAmt = 0, tmpBalance = 0;

ifstream inMichele, inPaul, inRob, inTim, inVern;

pthread_mutex_t balanceMutex = PTHREAD_MUTEX_INITIALIZER;
string incString = "00000000";
string pageName;

void *Michele(void *ptr)
{
	int micheleX = 1;
	inMichele.open("Michele.in", ios::in);
	current = first;
	if (micheleX < 7)
	{
		while (micheleX <= 6)
		{ // Finding a blank page
			if (current->r == -1 && current->m == -1 && current->taken == false && current->senator == "")
			{

				if (micheleX == 1)
				{
					pthread_mutex_lock(&page1Mutex);
					current->taken = true;
					current->senator = "Michele";
					pthread_mutex_unlock(&page1Mutex);
					break;
				}
				else if (micheleX == 2)
				{
					pthread_mutex_lock(&page2Mutex);
					current->taken = true;
					current->senator = "Michele";
					pthread_mutex_unlock(&page2Mutex);
					break;
				}
				else if (micheleX == 3)
				{
					pthread_mutex_lock(&page3Mutex);
					current->taken = true;
					current->senator = "Michele";
					pthread_mutex_unlock(&page3Mutex);
					break;
				}
				else if (micheleX == 4)
				{
					pthread_mutex_lock(&page4Mutex);
					current->taken = true;
					current->senator = "Michele";
					pthread_mutex_unlock(&page4Mutex);
					break;
				}
				else if (micheleX == 5)
				{
					pthread_mutex_lock(&page5Mutex);
					current->taken = true;
					current->senator = "Michele";
					pthread_mutex_unlock(&page5Mutex);
					break;
				}
				else if (micheleX == 6)
				{
					pthread_mutex_lock(&page6Mutex);
					current->taken = true;
					current->senator = "Michele";
					pthread_mutex_unlock(&page6Mutex);
					break;
				}
			}
			micheleX++;
			current = current->next;
		}
	}
	else
	{
		cout << "pages full" << endl << endl << endl << endl << endl << endl;
	}
	for (;;)
	{
		cout << page1->senator << " " << page1->taken << " " << page1->r << " " << page1->m << endl;
		cout << page2->senator << " " << page2->taken << " " << page2->r << " " << page2->m << endl;
		cout << page3->senator << " " << page3->taken << " " << page3->r << " " << page3->m << endl;
		cout << page4->senator << " " << page4->taken << " " << page4->r << " " << page4->m << endl;
		cout << page5->senator << " " << page5->taken << " " << page5->r << " " << page5->m << endl;
		cout << page6->senator << " " << page6->taken << " " << page6->r << " " << page6->m << endl;

		int micheleExtraPage = rand() % 2, micheleReset = rand() % 4;
		micheleCurrent = first;
		if (micheleReset == 1)
		{
			micheleX = 1;
			while (micheleX <= 6)
			{
				if (micheleCurrent->taken == true)
				{
					micheleCurrent->r = 0;
					micheleCurrent = micheleCurrent->next;
				}
				micheleX++;
			}
			micheleReset = -1;
		}
		micheleCurrent = first;
		micheleX = 1;
		if (micheleExtraPage == 1)
		{
			cout << "Thread Michele is asking for another page" << endl;
			micheleCurrent = first;
			micheleX = 1;
			while (micheleX < 7 && freePageMichele == false)
			{
				if (micheleX == 1 && micheleCurrent->taken == false && micheleCurrent->senator == "")
				{
					pthread_mutex_lock(&page1Mutex);
					micheleCurrent->taken = true;
					micheleCurrent->senator = "Michele";
					cout << "page" << micheleX << " " << micheleCurrent->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					freePageMichele = true;
					break;
				}
				if (micheleX == 2 && micheleCurrent->taken == false && micheleCurrent->senator == "")
				{
					pthread_mutex_lock(&page2Mutex);
					micheleCurrent->taken = true;
					micheleCurrent->senator = "Michele";
					cout << "page" << micheleX << " " << micheleCurrent->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					freePageMichele = true;
					break;
				}
				if (micheleX == 3 && micheleCurrent->taken == false && micheleCurrent->senator == "")
				{
					pthread_mutex_lock(&page3Mutex);
					micheleCurrent->taken = true;
					micheleCurrent->senator = "Michele";
					cout << "page" << micheleX << " " << micheleCurrent->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					freePageMichele = true;
					break;
				}
				if (micheleX == 4 && micheleCurrent->taken == false && micheleCurrent->senator == "")
				{
					pthread_mutex_lock(&page4Mutex);
					micheleCurrent->taken = true;
					micheleCurrent->senator = "Michele";
					cout << "page" << micheleX << " " << micheleCurrent->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					freePageMichele = true;
					break;
				}
				if (micheleX == 5 && micheleCurrent->taken == false && micheleCurrent->senator == "")
				{
					pthread_mutex_lock(&page5Mutex);
					micheleCurrent->taken = true;
					micheleCurrent->senator = "Michele";
					cout << "page" << micheleX << " " << micheleCurrent->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					freePageMichele = true;
					break;
				}
				if (micheleX == 6 && micheleCurrent->taken == false && micheleCurrent->senator == "")
				{
					pthread_mutex_lock(&page6Mutex);
					micheleCurrent->taken = true;
					micheleCurrent->senator = "Michele";
					cout << "page" << micheleX << " " << micheleCurrent->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					freePageMichele = true;
					break;
				}
				micheleX++;
				micheleCurrent = micheleCurrent->next;
			}
			micheleX = 1;
			micheleCurrent = first;
			if (freePageMichele == false && micheleExtraPage == 1)
			{
				//				cout << "No free Pages" << endl;
				while (micheleX < 7 && !pageReplacedMichele)
				{
					if (micheleCurrent->r == 0 && micheleCurrent->m == 0)
					{
						if (micheleX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedMichele = true;
							break;
						}
					}
					micheleX++;
					micheleCurrent = micheleCurrent->next;
				}
				micheleX = 1;
				micheleCurrent = first;
				while (micheleX < 7 && !pageReplacedMichele)
				{
					if (micheleCurrent->r == 0 && micheleCurrent->m == 1)
					{
						if (micheleX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedMichele = true;
							break;
						}
					}
					micheleX++;
					micheleCurrent = micheleCurrent->next;
				}
				micheleX = 1;
				micheleCurrent = first;
				while (micheleX < 7 && !pageReplacedMichele)
				{
					if (micheleCurrent->r == 1 && micheleCurrent->m == 0)
					{
						if (micheleX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedMichele = true;
							break;
						}
					}
					micheleX++;
					micheleCurrent = micheleCurrent->next;
				}
				micheleX = 1;
				micheleCurrent = first;
				while (micheleX < 7 && !pageReplacedMichele)
				{
					if (micheleCurrent->r == 1 && micheleCurrent->m == 1)
					{
						if (micheleX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedMichele = true;
							break;
						}
						if (micheleX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << micheleX << " " << micheleCurrent->r << " " << micheleCurrent->m << " " << micheleCurrent->senator << " is being replaced" << endl;
							micheleCurrent->r = -1;
							micheleCurrent->m = -1;
							micheleCurrent->senator = "Michele";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedMichele = true;
							break;
						}
					}
					micheleX++;
					micheleCurrent = micheleCurrent->next;
				}
				micheleX = 1;
				micheleCurrent = first;
			}
			micheleExtraPage = -1;
		}
		pageReplacedMichele = false;
		freePageMichele = false;
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneMichele == false)
		{
			while (!inMichele.eof())
			{
				micheleX = 1;
				micheleCurrent = first;
				getline(inMichele, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					while (micheleX <= 6)
					{
						if (micheleCurrent->senator == "Michele")
						{
							foundMichele = true;
							break;
						}
						else
						{
							micheleCurrent = micheleCurrent->next;
							micheleX++;
						}
					}
					if (!foundMichele)
					{
						cout << "Page fault in thread Michele" << endl;
						//run search for page to replace here
					}
					balance += tmpBalance;
					tmpBalance = 0;
					micheleX = 1;
					micheleCurrent = first;
					if (balance < 0)
					{
						while (micheleX <= 6)
						{
							if (current->senator == "Michele")
							{
								current->r = 1;
								current->m = 1;
								cout << "page" << micheleX << " " << current->senator << " " << current->r << " " << current->m << endl;
								break;
							}
							micheleX++;
							current = current->next;
						}
					}
					else
					{
						while (micheleX <= 6)
						{
							if (micheleCurrent->senator == "Michele")
							{
								current->r = 1;
								cout << "page" << micheleX << " " << micheleCurrent->senator << " " << micheleCurrent->r << " " << micheleCurrent->m << endl;
								break;
							}
							micheleX++;
							micheleCurrent = micheleCurrent->next;
						}
					}
					cout << "Balance after Michele: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else if (incString == "")
				{
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else
				{
					stringstream(incString) >> incAmt;
					tmpBalance += incAmt;
				}
			}
			if (inMichele.eof())
			{
				doneMichele = true;
				tmpBalance = 0;
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
	int paulX = 1;
	inPaul.open("Paul.in", ios::in);
	current = first;
	//	ostringstream mConvert;
	if (paulX < 7)
	{
		while (paulX <= 6)
		{ // Finding a blank page
			if (current->r == -1 && current->m == -1 && current->taken == false && current->senator == "")
			{
				/*				pageName = "page";
								mConvert << paulX;
								pageName += mConvert.str();
								pageName += "Mutex";
								cout << pageName << endl;
								pthread_mutex_lock(&pageName);
				*/
				if (paulX == 1)
				{
					pthread_mutex_lock(&page1Mutex);
					current->taken = true;
					current->senator = "Paul";
					//					cout << "page" << paulX << " " << current->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					break;
				}
				else if (paulX == 2)
				{
					pthread_mutex_lock(&page2Mutex);
					current->taken = true;
					current->senator = "Paul";
					//					cout << "page" << paulX << " " << current->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					break;
				}
				else if (paulX == 3)
				{
					pthread_mutex_lock(&page3Mutex);
					current->taken = true;
					current->senator = "Paul";
					//					cout << "page" << paulX << " " << current->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					break;
				}
				else if (paulX == 4)
				{
					pthread_mutex_lock(&page4Mutex);
					current->taken = true;
					current->senator = "Paul";
					//					cout << "page" << paulX << " " << current->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					break;
				}
				else if (paulX == 5)
				{
					pthread_mutex_lock(&page5Mutex);
					current->taken = true;
					current->senator = "Paul";
					//					cout << "page" << paulX << " " << current->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					break;
				}
				else if (paulX == 6)
				{
					pthread_mutex_lock(&page6Mutex);
					current->taken = true;
					current->senator = "Paul";
					//					cout << "page" << paulX << " " << current->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					break;
				}
			}
			paulX++;
			current = current->next;
		}
	}
	else
	{
		cout << "pages full" << endl << endl << endl << endl << endl << endl;
	}
	for (;;)
	{
		cout << page1->senator << " " << page1->taken << " " << page1->r << " " << page1->m << endl;
		cout << page2->senator << " " << page2->taken << " " << page2->r << " " << page2->m << endl;
		cout << page3->senator << " " << page3->taken << " " << page3->r << " " << page3->m << endl;
		cout << page4->senator << " " << page4->taken << " " << page4->r << " " << page4->m << endl;
		cout << page5->senator << " " << page5->taken << " " << page5->r << " " << page5->m << endl;
		cout << page6->senator << " " << page6->taken << " " << page6->r << " " << page6->m << endl;

		int paulExtraPage = rand() % 2, paulReset = rand() % 4;
		//		cout << "paulExtraPage= " << paulExtraPage << endl;
		paulCurrent = first;
		if (paulReset == 1)
		{
			paulX = 1;
			while (paulX <= 6)
			{
				//				cout << "in Paul reset" << endl;
				if (paulCurrent->taken == true)
				{
					paulCurrent->r = 0;
					paulCurrent = paulCurrent->next;
				}
				paulX++;
			}
			paulReset = -1;
		}
		paulCurrent = first;
		paulX = 1;
		if (paulExtraPage == 1)
		{
			cout << "Thread Paul is asking for another page" << endl;
			paulCurrent = first;
			paulX = 1;
			while (paulX < 7 && freePagePaul == false)
			{
				if (paulX == 1 && paulCurrent->taken == false && paulCurrent->senator == "")
				{
					pthread_mutex_lock(&page1Mutex);
					paulCurrent->taken = true;
					paulCurrent->senator = "Paul";
					cout << "page" << paulX << " " << paulCurrent->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					freePagePaul = true;
					break;
				}
				if (paulX == 2 && paulCurrent->taken == false && paulCurrent->senator == "")
				{
					pthread_mutex_lock(&page2Mutex);
					paulCurrent->taken = true;
					paulCurrent->senator = "Paul";
					cout << "page" << paulX << " " << paulCurrent->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					freePagePaul = true;
					break;
				}
				if (paulX == 3 && paulCurrent->taken == false && paulCurrent->senator == "")
				{
					pthread_mutex_lock(&page3Mutex);
					paulCurrent->taken = true;
					paulCurrent->senator = "Paul";
					cout << "page" << paulX << " " << paulCurrent->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					freePagePaul = true;
					break;
				}
				if (paulX == 4 && paulCurrent->taken == false && paulCurrent->senator == "")
				{
					pthread_mutex_lock(&page4Mutex);
					paulCurrent->taken = true;
					paulCurrent->senator = "Paul";
					cout << "page" << paulX << " " << paulCurrent->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					freePagePaul = true;
					break;
				}
				if (paulX == 5 && paulCurrent->taken == false && paulCurrent->senator == "")
				{
					pthread_mutex_lock(&page5Mutex);
					paulCurrent->taken = true;
					paulCurrent->senator = "Paul";
					cout << "page" << paulX << " " << paulCurrent->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					freePagePaul = true;
					break;
				}
				if (paulX == 6 && paulCurrent->taken == false && paulCurrent->senator == "")
				{
					pthread_mutex_lock(&page6Mutex);
					paulCurrent->taken = true;
					paulCurrent->senator = "Paul";
					cout << "page" << paulX << " " << paulCurrent->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					freePagePaul = true;
					break;
				}
				paulX++;
				paulCurrent = paulCurrent->next;
			}
			paulX = 1;
			paulCurrent = first;
			if (freePagePaul == false && paulExtraPage == 1)
			{
				//				cout << "No free Pages" << endl;
				while (paulX < 7 && !pageReplacedPaul)
				{
					if (paulCurrent->r == 0 && paulCurrent->m == 0)
					{
						if (paulX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedPaul = true;
							break;
						}
					}
					paulX++;
					paulCurrent = paulCurrent->next;
				}
				paulX = 1;
				paulCurrent = first;
				while (paulX < 7 && !pageReplacedPaul)
				{
					if (paulCurrent->r == 0 && paulCurrent->m == 1)
					{
						if (paulX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedPaul = true;
							break;
						}
					}
					paulX++;
					paulCurrent = paulCurrent->next;
				}
				paulX = 1;
				paulCurrent = first;
				while (paulX < 7 && !pageReplacedPaul)
				{
					if (paulCurrent->r == 1 && paulCurrent->m == 0)
					{
						if (paulX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedPaul = true;
							break;
						}
					}
					paulX++;
					paulCurrent = paulCurrent->next;
				}
				paulX = 1;
				paulCurrent = first;
				while (paulX < 7 && !pageReplacedPaul)
				{
					if (paulCurrent->r == 1 && paulCurrent->m == 1)
					{
						if (paulX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedPaul = true;
							break;
						}
						if (paulX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << paulX << " " << paulCurrent->r << " " << paulCurrent->m << " " << paulCurrent->senator << " is being replaced" << endl;
							paulCurrent->r = -1;
							paulCurrent->m = -1;
							paulCurrent->senator = "Paul";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedPaul = true;
							break;
						}
					}
					paulX++;
					paulCurrent = paulCurrent->next;
				}
				paulX = 1;
				paulCurrent = first;
			}
			paulExtraPage = -1;
		}
		pageReplacedPaul = false;
		freePagePaul = false;
		if (pthread_mutex_trylock(&balanceMutex) == 0 && donePaul == false)
		{
			while (!inPaul.eof())
			{
				paulX = 1;
				paulCurrent = first;
				getline(inPaul, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					while (paulX <= 6)
					{
						if (paulCurrent->senator == "Paul")
						{
							foundPaul = true;
							break;
						}
						else
						{
							paulCurrent = paulCurrent->next;
							paulX++;
						}
					}
					if (!foundPaul)
					{
						cout << "Page fault in thread Paul" << endl;
						//run search for page to replace here
					}
					balance += tmpBalance;
					tmpBalance = 0;
					paulX = 1;
					paulCurrent = first;
					if (balance < 0)
					{
						while (paulX <= 6)
						{
							if (current->senator == "Paul")
							{
								current->r = 1;
								current->m = 1;
								cout << "page" << paulX << " " << current->senator << " " << current->r << " " << current->m << endl;
								break;
							}
							paulX++;
							current = current->next;
						}
					}
					else
					{
						while (paulX <= 6)
						{
							if (paulCurrent->senator == "Paul")
							{
								current->r = 1;
								cout << "page" << paulX << " " << paulCurrent->senator << " " << paulCurrent->r << " " << paulCurrent->m << endl;
								break;
							}
							paulX++;
							paulCurrent = paulCurrent->next;
						}
					}
					cout << "Balance after Paul: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else if (incString == "")
				{
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else
				{
					stringstream(incString) >> incAmt;
					tmpBalance += incAmt;
				}
			}
			if (inPaul.eof())
			{
				donePaul = true;
				tmpBalance = 0;
				if (donePaul && donePaul && doneRob && doneTim && doneVern)
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
	int robX = 1;
	inRob.open("Rob.in", ios::in);
	current = first;
	//	ostringstream mConvert;
	if (robX < 7)
	{
		while (robX <= 6)
		{ // Finding a blank page
			if (current->r == -1 && current->m == -1 && current->taken == false && current->senator == "")
			{
				/*				pageName = "page";
								mConvert << robX;
								pageName += mConvert.str();
								pageName += "Mutex";
								cout << pageName << endl;
								pthread_mutex_lock(&pageName);
				*/
				if (robX == 1)
				{
					pthread_mutex_lock(&page1Mutex);
					current->taken = true;
					current->senator = "Rob";
					//					cout << "page" << robX << " " << current->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					break;
				}
				else if (robX == 2)
				{
					pthread_mutex_lock(&page2Mutex);
					current->taken = true;
					current->senator = "Rob";
					//					cout << "page" << robX << " " << current->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					break;
				}
				else if (robX == 3)
				{
					pthread_mutex_lock(&page3Mutex);
					current->taken = true;
					current->senator = "Rob";
					//					cout << "page" << robX << " " << current->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					break;
				}
				else if (robX == 4)
				{
					pthread_mutex_lock(&page4Mutex);
					current->taken = true;
					current->senator = "Rob";
					//					cout << "page" << robX << " " << current->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					break;
				}
				else if (robX == 5)
				{
					pthread_mutex_lock(&page5Mutex);
					current->taken = true;
					current->senator = "Rob";
					//					cout << "page" << robX << " " << current->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					break;
				}
				else if (robX == 6)
				{
					pthread_mutex_lock(&page6Mutex);
					current->taken = true;
					current->senator = "Rob";
					//					cout << "page" << robX << " " << current->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					break;
				}
			}
			robX++;
			current = current->next;
		}
	}
	else
	{
		cout << "pages full" << endl << endl << endl << endl << endl << endl;
	}
	for (;;)
	{
		cout << page1->senator << " " << page1->taken << " " << page1->r << " " << page1->m << endl;
		cout << page2->senator << " " << page2->taken << " " << page2->r << " " << page2->m << endl;
		cout << page3->senator << " " << page3->taken << " " << page3->r << " " << page3->m << endl;
		cout << page4->senator << " " << page4->taken << " " << page4->r << " " << page4->m << endl;
		cout << page5->senator << " " << page5->taken << " " << page5->r << " " << page5->m << endl;
		cout << page6->senator << " " << page6->taken << " " << page6->r << " " << page6->m << endl;

		int robExtraPage = rand() % 2, robReset = rand() % 4;
		//		cout << "robExtraPage= " << robExtraPage << endl;
		robCurrent = first;
		if (robReset == 1)
		{
			robX = 1;
			while (robX <= 6)
			{
				//				cout << "in Rob reset" << endl;
				if (robCurrent->taken == true)
				{
					robCurrent->r = 0;
					robCurrent = robCurrent->next;
				}
				robX++;
			}
			robReset = -1;
		}
		robCurrent = first;
		robX = 1;
		if (robExtraPage == 1)
		{
			cout << "Thread Rob is asking for another page" << endl;
			robCurrent = first;
			robX = 1;
			while (robX < 7 && freePageRob == false)
			{
				if (robX == 1 && robCurrent->taken == false && robCurrent->senator == "")
				{
					pthread_mutex_lock(&page1Mutex);
					robCurrent->taken = true;
					robCurrent->senator = "Rob";
					cout << "page" << robX << " " << robCurrent->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					freePageRob = true;
					break;
				}
				if (robX == 2 && robCurrent->taken == false && robCurrent->senator == "")
				{
					pthread_mutex_lock(&page2Mutex);
					robCurrent->taken = true;
					robCurrent->senator = "Rob";
					cout << "page" << robX << " " << robCurrent->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					freePageRob = true;
					break;
				}
				if (robX == 3 && robCurrent->taken == false && robCurrent->senator == "")
				{
					pthread_mutex_lock(&page3Mutex);
					robCurrent->taken = true;
					robCurrent->senator = "Rob";
					cout << "page" << robX << " " << robCurrent->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					freePageRob = true;
					break;
				}
				if (robX == 4 && robCurrent->taken == false && robCurrent->senator == "")
				{
					pthread_mutex_lock(&page4Mutex);
					robCurrent->taken = true;
					robCurrent->senator = "Rob";
					cout << "page" << robX << " " << robCurrent->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					freePageRob = true;
					break;
				}
				if (robX == 5 && robCurrent->taken == false && robCurrent->senator == "")
				{
					pthread_mutex_lock(&page5Mutex);
					robCurrent->taken = true;
					robCurrent->senator = "Rob";
					cout << "page" << robX << " " << robCurrent->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					freePageRob = true;
					break;
				}
				if (robX == 6 && robCurrent->taken == false && robCurrent->senator == "")
				{
					pthread_mutex_lock(&page6Mutex);
					robCurrent->taken = true;
					robCurrent->senator = "Rob";
					cout << "page" << robX << " " << robCurrent->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					freePageRob = true;
					break;
				}
				robX++;
				robCurrent = robCurrent->next;
			}
			robX = 1;
			robCurrent = first;
			if (freePageRob == false && robExtraPage == 1)
			{
				//				cout << "No free Pages" << endl;
				while (robX < 7 && !pageReplacedRob)
				{
					if (robCurrent->r == 0 && robCurrent->m == 0)
					{
						if (robX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedRob = true;
							break;
						}
					}
					robX++;
					robCurrent = robCurrent->next;
				}
				robX = 1;
				robCurrent = first;
				while (robX < 7 && !pageReplacedRob)
				{
					if (robCurrent->r == 0 && robCurrent->m == 1)
					{
						if (robX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedRob = true;
							break;
						}
					}
					robX++;
					robCurrent = robCurrent->next;
				}
				robX = 1;
				robCurrent = first;
				while (robX < 7 && !pageReplacedRob)
				{
					if (robCurrent->r == 1 && robCurrent->m == 0)
					{
						if (robX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedRob = true;
							break;
						}
					}
					robX++;
					robCurrent = robCurrent->next;
				}
				robX = 1;
				robCurrent = first;
				while (robX < 7 && !pageReplacedRob)
				{
					if (robCurrent->r == 1 && robCurrent->m == 1)
					{
						if (robX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedRob = true;
							break;
						}
						if (robX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << robX << " " << robCurrent->r << " " << robCurrent->m << " " << robCurrent->senator << " is being replaced" << endl;
							robCurrent->r = -1;
							robCurrent->m = -1;
							robCurrent->senator = "Rob";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedRob = true;
							break;
						}
					}
					robX++;
					robCurrent = robCurrent->next;
				}
				robX = 1;
				robCurrent = first;
			}
			robExtraPage = -1;
		}
		pageReplacedRob = false;
		freePageRob = false;
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneRob == false)
		{
			while (!inRob.eof())
			{
				robX = 1;
				robCurrent = first;
				getline(inRob, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					while (robX <= 6)
					{
						if (robCurrent->senator == "Rob")
						{
							foundRob = true;
							break;
						}
						else
						{
							robCurrent = robCurrent->next;
							robX++;
						}
					}
					if (!foundRob)
					{
						cout << "Page fault in thread Rob" << endl;
						//run search for page to replace here
					}
					balance += tmpBalance;
					tmpBalance = 0;
					robX = 1;
					robCurrent = first;
					if (balance < 0)
					{
						while (robX <= 6)
						{
							if (current->senator == "Rob")
							{
								current->r = 1;
								current->m = 1;
								cout << "page" << robX << " " << current->senator << " " << current->r << " " << current->m << endl;
								break;
							}
							robX++;
							current = current->next;
						}
					}
					else
					{
						while (robX <= 6)
						{
							if (robCurrent->senator == "Rob")
							{
								current->r = 1;
								cout << "page" << robX << " " << robCurrent->senator << " " << robCurrent->r << " " << robCurrent->m << endl;
								break;
							}
							robX++;
							robCurrent = robCurrent->next;
						}
					}
					cout << "Balance after Rob: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else if (incString == "")
				{
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else
				{
					stringstream(incString) >> incAmt;
					tmpBalance += incAmt;
				}
			}
			if (inRob.eof())
			{
				doneRob = true;
				tmpBalance = 0;
				if (doneRob && doneRob && doneRob && doneTim && doneVern)
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
	int timX = 1;
	inTim.open("Tim.in", ios::in);
	current = first;
	//	ostringstream mConvert;
	if (timX < 7)
	{
		while (timX <= 6)
		{ // Finding a blank page
			if (current->r == -1 && current->m == -1 && current->taken == false && current->senator == "")
			{
				/*				pageName = "page";
								mConvert << timX;
								pageName += mConvert.str();
								pageName += "Mutex";
								cout << pageName << endl;
								pthread_mutex_lock(&pageName);
				*/
				if (timX == 1)
				{
					pthread_mutex_lock(&page1Mutex);
					current->taken = true;
					current->senator = "Tim";
					//					cout << "page" << timX << " " << current->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					break;
				}
				else if (timX == 2)
				{
					pthread_mutex_lock(&page2Mutex);
					current->taken = true;
					current->senator = "Tim";
					//					cout << "page" << timX << " " << current->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					break;
				}
				else if (timX == 3)
				{
					pthread_mutex_lock(&page3Mutex);
					current->taken = true;
					current->senator = "Tim";
					//					cout << "page" << timX << " " << current->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					break;
				}
				else if (timX == 4)
				{
					pthread_mutex_lock(&page4Mutex);
					current->taken = true;
					current->senator = "Tim";
					//					cout << "page" << timX << " " << current->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					break;
				}
				else if (timX == 5)
				{
					pthread_mutex_lock(&page5Mutex);
					current->taken = true;
					current->senator = "Tim";
					//					cout << "page" << timX << " " << current->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					break;
				}
				else if (timX == 6)
				{
					pthread_mutex_lock(&page6Mutex);
					current->taken = true;
					current->senator = "Tim";
					//					cout << "page" << timX << " " << current->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					break;
				}
			}
			timX++;
			current = current->next;
		}
	}
	else
	{
		cout << "pages full" << endl << endl << endl << endl << endl << endl;
	}
	for (;;)
	{
		cout << page1->senator << " " << page1->taken << " " << page1->r << " " << page1->m << endl;
		cout << page2->senator << " " << page2->taken << " " << page2->r << " " << page2->m << endl;
		cout << page3->senator << " " << page3->taken << " " << page3->r << " " << page3->m << endl;
		cout << page4->senator << " " << page4->taken << " " << page4->r << " " << page4->m << endl;
		cout << page5->senator << " " << page5->taken << " " << page5->r << " " << page5->m << endl;
		cout << page6->senator << " " << page6->taken << " " << page6->r << " " << page6->m << endl;

		int timExtraPage = rand() % 2, timReset = rand() % 4;
		//		cout << "timExtraPage= " << timExtraPage << endl;
		timCurrent = first;
		if (timReset == 1)
		{
			timX = 1;
			while (timX <= 6)
			{
				//				cout << "in Tim reset" << endl;
				if (timCurrent->taken == true)
				{
					timCurrent->r = 0;
					timCurrent = timCurrent->next;
				}
				timX++;
			}
			timReset = -1;
		}
		timCurrent = first;
		timX = 1;
		if (timExtraPage == 1)
		{
			cout << "Thread Tim is asking for another page" << endl;
			timCurrent = first;
			timX = 1;
			while (timX < 7 && freePageTim == false)
			{
				if (timX == 1 && timCurrent->taken == false && timCurrent->senator == "")
				{
					pthread_mutex_lock(&page1Mutex);
					timCurrent->taken = true;
					timCurrent->senator = "Tim";
					cout << "page" << timX << " " << timCurrent->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					freePageTim = true;
					break;
				}
				if (timX == 2 && timCurrent->taken == false && timCurrent->senator == "")
				{
					pthread_mutex_lock(&page2Mutex);
					timCurrent->taken = true;
					timCurrent->senator = "Tim";
					cout << "page" << timX << " " << timCurrent->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					freePageTim = true;
					break;
				}
				if (timX == 3 && timCurrent->taken == false && timCurrent->senator == "")
				{
					pthread_mutex_lock(&page3Mutex);
					timCurrent->taken = true;
					timCurrent->senator = "Tim";
					cout << "page" << timX << " " << timCurrent->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					freePageTim = true;
					break;
				}
				if (timX == 4 && timCurrent->taken == false && timCurrent->senator == "")
				{
					pthread_mutex_lock(&page4Mutex);
					timCurrent->taken = true;
					timCurrent->senator = "Tim";
					cout << "page" << timX << " " << timCurrent->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					freePageTim = true;
					break;
				}
				if (timX == 5 && timCurrent->taken == false && timCurrent->senator == "")
				{
					pthread_mutex_lock(&page5Mutex);
					timCurrent->taken = true;
					timCurrent->senator = "Tim";
					cout << "page" << timX << " " << timCurrent->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					freePageTim = true;
					break;
				}
				if (timX == 6 && timCurrent->taken == false && timCurrent->senator == "")
				{
					pthread_mutex_lock(&page6Mutex);
					timCurrent->taken = true;
					timCurrent->senator = "Tim";
					cout << "page" << timX << " " << timCurrent->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					freePageTim = true;
					break;
				}
				timX++;
				timCurrent = timCurrent->next;
			}
			timX = 1;
			timCurrent = first;
			if (freePageTim == false && timExtraPage == 1)
			{
				//				cout << "No free Pages" << endl;
				while (timX < 7 && !pageReplacedTim)
				{
					if (timCurrent->r == 0 && timCurrent->m == 0)
					{
						if (timX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedTim = true;
							break;
						}
					}
					timX++;
					timCurrent = timCurrent->next;
				}
				timX = 1;
				timCurrent = first;
				while (timX < 7 && !pageReplacedTim)
				{
					if (timCurrent->r == 0 && timCurrent->m == 1)
					{
						if (timX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedTim = true;
							break;
						}
					}
					timX++;
					timCurrent = timCurrent->next;
				}
				timX = 1;
				timCurrent = first;
				while (timX < 7 && !pageReplacedTim)
				{
					if (timCurrent->r == 1 && timCurrent->m == 0)
					{
						if (timX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedTim = true;
							break;
						}
					}
					timX++;
					timCurrent = timCurrent->next;
				}
				timX = 1;
				timCurrent = first;
				while (timX < 7 && !pageReplacedTim)
				{
					if (timCurrent->r == 1 && timCurrent->m == 1)
					{
						if (timX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedTim = true;
							break;
						}
						if (timX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << timX << " " << timCurrent->r << " " << timCurrent->m << " " << timCurrent->senator << " is being replaced" << endl;
							timCurrent->r = -1;
							timCurrent->m = -1;
							timCurrent->senator = "Tim";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedTim = true;
							break;
						}
					}
					timX++;
					timCurrent = timCurrent->next;
				}
				timX = 1;
				timCurrent = first;
			}
			timExtraPage = -1;
		}
		pageReplacedTim = false;
		freePageTim = false;
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneTim == false)
		{
			while (!inTim.eof())
			{
				timX = 1;
				timCurrent = first;
				getline(inTim, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					while (timX <= 6)
					{
						if (timCurrent->senator == "Tim")
						{
							foundTim = true;
							break;
						}
						else
						{
							timCurrent = timCurrent->next;
							timX++;
						}
					}
					if (!foundTim)
					{
						cout << "Page fault in thread Tim" << endl;
						//run search for page to replace here
					}
					balance += tmpBalance;
					tmpBalance = 0;
					timX = 1;
					timCurrent = first;
					if (balance < 0)
					{
						while (timX <= 6)
						{
							if (current->senator == "Tim")
							{
								current->r = 1;
								current->m = 1;
								cout << "page" << timX << " " << current->senator << " " << current->r << " " << current->m << endl;
								break;
							}
							timX++;
							current = current->next;
						}
					}
					else
					{
						while (timX <= 6)
						{
							if (timCurrent->senator == "Tim")
							{
								current->r = 1;
								cout << "page" << timX << " " << timCurrent->senator << " " << timCurrent->r << " " << timCurrent->m << endl;
								break;
							}
							timX++;
							timCurrent = timCurrent->next;
						}
					}
					cout << "Balance after Tim: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else if (incString == "")
				{
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else
				{
					stringstream(incString) >> incAmt;
					tmpBalance += incAmt;
				}
			}
			if (inTim.eof())
			{
				doneTim = true;
				tmpBalance = 0;
				if (doneTim && doneTim && doneTim && doneTim && doneVern)
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
	int vernX = 1;
	inVern.open("Vern.in", ios::in);
	current = first;
	//	ostringstream mConvert;
	if (vernX < 7)
	{
		while (vernX <= 6)
		{ // Finding a blank page
			if (current->r == -1 && current->m == -1 && current->taken == false && current->senator == "")
			{
				/*				pageName = "page";
								mConvert << vernX;
								pageName += mConvert.str();
								pageName += "Mutex";
								cout << pageName << endl;
								pthread_mutex_lock(&pageName);
				*/
				if (vernX == 1)
				{
					pthread_mutex_lock(&page1Mutex);
					current->taken = true;
					current->senator = "Vern";
					//					cout << "page" << vernX << " " << current->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					break;
				}
				else if (vernX == 2)
				{
					pthread_mutex_lock(&page2Mutex);
					current->taken = true;
					current->senator = "Vern";
					//					cout << "page" << vernX << " " << current->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					break;
				}
				else if (vernX == 3)
				{
					pthread_mutex_lock(&page3Mutex);
					current->taken = true;
					current->senator = "Vern";
					//					cout << "page" << vernX << " " << current->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					break;
				}
				else if (vernX == 4)
				{
					pthread_mutex_lock(&page4Mutex);
					current->taken = true;
					current->senator = "Vern";
					//					cout << "page" << vernX << " " << current->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					break;
				}
				else if (vernX == 5)
				{
					pthread_mutex_lock(&page5Mutex);
					current->taken = true;
					current->senator = "Vern";
					//					cout << "page" << vernX << " " << current->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					break;
				}
				else if (vernX == 6)
				{
					pthread_mutex_lock(&page6Mutex);
					current->taken = true;
					current->senator = "Vern";
					//					cout << "page" << vernX << " " << current->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					break;
				}
			}
			vernX++;
			current = current->next;
		}
	}
	else
	{
		cout << "pages full" << endl << endl << endl << endl << endl << endl;
	}
	for (;;)
	{
		cout << page1->senator << " " << page1->taken << " " << page1->r << " " << page1->m << endl;
		cout << page2->senator << " " << page2->taken << " " << page2->r << " " << page2->m << endl;
		cout << page3->senator << " " << page3->taken << " " << page3->r << " " << page3->m << endl;
		cout << page4->senator << " " << page4->taken << " " << page4->r << " " << page4->m << endl;
		cout << page5->senator << " " << page5->taken << " " << page5->r << " " << page5->m << endl;
		cout << page6->senator << " " << page6->taken << " " << page6->r << " " << page6->m << endl;

		int vernExtraPage = rand() % 2, vernReset = rand() % 4;
		//		cout << "vernExtraPage= " << vernExtraPage << endl;
		vernCurrent = first;
		if (vernReset == 1)
		{
			vernX = 1;
			while (vernX <= 6)
			{
				//				cout << "in Vern reset" << endl;
				if (vernCurrent->taken == true)
				{
					vernCurrent->r = 0;
					vernCurrent = vernCurrent->next;
				}
				vernX++;
			}
			vernReset = -1;
		}
		vernCurrent = first;
		vernX = 1;
		if (vernExtraPage == 1)
		{
			cout << "Thread Vern is asking for another page" << endl;
			vernCurrent = first;
			vernX = 1;
			while (vernX < 7 && freePageVern == false)
			{
				if (vernX == 1 && vernCurrent->taken == false && vernCurrent->senator == "")
				{
					pthread_mutex_lock(&page1Mutex);
					vernCurrent->taken = true;
					vernCurrent->senator = "Vern";
					cout << "page" << vernX << " " << vernCurrent->senator << endl;
					pthread_mutex_unlock(&page1Mutex);
					freePageVern = true;
					break;
				}
				if (vernX == 2 && vernCurrent->taken == false && vernCurrent->senator == "")
				{
					pthread_mutex_lock(&page2Mutex);
					vernCurrent->taken = true;
					vernCurrent->senator = "Vern";
					cout << "page" << vernX << " " << vernCurrent->senator << endl;
					pthread_mutex_unlock(&page2Mutex);
					freePageVern = true;
					break;
				}
				if (vernX == 3 && vernCurrent->taken == false && vernCurrent->senator == "")
				{
					pthread_mutex_lock(&page3Mutex);
					vernCurrent->taken = true;
					vernCurrent->senator = "Vern";
					cout << "page" << vernX << " " << vernCurrent->senator << endl;
					pthread_mutex_unlock(&page3Mutex);
					freePageVern = true;
					break;
				}
				if (vernX == 4 && vernCurrent->taken == false && vernCurrent->senator == "")
				{
					pthread_mutex_lock(&page4Mutex);
					vernCurrent->taken = true;
					vernCurrent->senator = "Vern";
					cout << "page" << vernX << " " << vernCurrent->senator << endl;
					pthread_mutex_unlock(&page4Mutex);
					freePageVern = true;
					break;
				}
				if (vernX == 5 && vernCurrent->taken == false && vernCurrent->senator == "")
				{
					pthread_mutex_lock(&page5Mutex);
					vernCurrent->taken = true;
					vernCurrent->senator = "Vern";
					cout << "page" << vernX << " " << vernCurrent->senator << endl;
					pthread_mutex_unlock(&page5Mutex);
					freePageVern = true;
					break;
				}
				if (vernX == 6 && vernCurrent->taken == false && vernCurrent->senator == "")
				{
					pthread_mutex_lock(&page6Mutex);
					vernCurrent->taken = true;
					vernCurrent->senator = "Vern";
					cout << "page" << vernX << " " << vernCurrent->senator << endl;
					pthread_mutex_unlock(&page6Mutex);
					freePageVern = true;
					break;
				}
				vernX++;
				vernCurrent = vernCurrent->next;
			}
			vernX = 1;
			vernCurrent = first;
			if (freePageVern == false && vernExtraPage == 1)
			{
				//				cout << "No free Pages" << endl;
				while (vernX < 7 && !pageReplacedVern)
				{
					if (vernCurrent->r == 0 && vernCurrent->m == 0)
					{
						if (vernX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedVern = true;
							break;
						}
					}
					vernX++;
					vernCurrent = vernCurrent->next;
				}
				vernX = 1;
				vernCurrent = first;
				while (vernX < 7 && !pageReplacedVern)
				{
					if (vernCurrent->r == 0 && vernCurrent->m == 1)
					{
						if (vernX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedVern = true;
							break;
						}
					}
					vernX++;
					vernCurrent = vernCurrent->next;
				}
				vernX = 1;
				vernCurrent = first;
				while (vernX < 7 && !pageReplacedVern)
				{
					if (vernCurrent->r == 1 && vernCurrent->m == 0)
					{
						if (vernX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedVern = true;
							break;
						}
					}
					vernX++;
					vernCurrent = vernCurrent->next;
				}
				vernX = 1;
				vernCurrent = first;
				while (vernX < 7 && !pageReplacedVern)
				{
					if (vernCurrent->r == 1 && vernCurrent->m == 1)
					{
						if (vernX == 1)
						{
							pthread_mutex_lock(&page1Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page1Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 2)
						{
							pthread_mutex_lock(&page2Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page2Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 3)
						{
							pthread_mutex_lock(&page3Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page3Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 4)
						{
							pthread_mutex_lock(&page4Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page4Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 5)
						{
							pthread_mutex_lock(&page5Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page5Mutex);
							pageReplacedVern = true;
							break;
						}
						if (vernX == 6)
						{
							pthread_mutex_lock(&page6Mutex);
							cout << "page" << vernX << " " << vernCurrent->r << " " << vernCurrent->m << " " << vernCurrent->senator << " is being replaced" << endl;
							vernCurrent->r = -1;
							vernCurrent->m = -1;
							vernCurrent->senator = "Vern";
							pthread_mutex_unlock(&page6Mutex);
							pageReplacedVern = true;
							break;
						}
					}
					vernX++;
					vernCurrent = vernCurrent->next;
				}
				vernX = 1;
				vernCurrent = first;
			}
			vernExtraPage = -1;
		}
		pageReplacedVern = false;
		freePageVern = false;
		if (pthread_mutex_trylock(&balanceMutex) == 0 && doneVern == false)
		{
			while (!inVern.eof())
			{
				vernX = 1;
				vernCurrent = first;
				getline(inVern, incString, '\n');
				if (incString == "R")
				{
				}
				else if (incString == "W")
				{
					while (vernX <= 6)
					{
						if (vernCurrent->senator == "Vern")
						{
							foundVern = true;
							break;
						}
						else
						{
							vernCurrent = vernCurrent->next;
							vernX++;
						}
					}
					if (!foundVern)
					{
						cout << "Page fault in thread Vern" << endl;
						//run search for page to replace here
					}
					balance += tmpBalance;
					tmpBalance = 0;
					vernX = 1;
					vernCurrent = first;
					if (balance < 0)
					{
						while (vernX <= 6)
						{
							if (current->senator == "Vern")
							{
								current->r = 1;
								current->m = 1;
								cout << "page" << vernX << " " << current->senator << " " << current->r << " " << current->m << endl;
								break;
							}
							vernX++;
							current = current->next;
						}
					}
					else
					{
						while (vernX <= 6)
						{
							if (vernCurrent->senator == "Vern")
							{
								current->r = 1;
								cout << "page" << vernX << " " << vernCurrent->senator << " " << vernCurrent->r << " " << vernCurrent->m << endl;
								break;
							}
							vernX++;
							vernCurrent = vernCurrent->next;
						}
					}
					cout << "Balance after Vern: " << balance << endl;
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else if (incString == "")
				{
					pthread_mutex_unlock(&balanceMutex);
					break;
				}
				else
				{
					stringstream(incString) >> incAmt;
					tmpBalance += incAmt;
				}
			}
			if (inVern.eof())
			{
				doneVern = true;
				tmpBalance = 0;
				if (doneVern && doneVern && doneVern && doneVern && doneVern)
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
	srand(time(NULL));
	current = page1 = page2 = page3 = page4 = page5 = page6 = NULL;
	page1 = new page;
	page1->next = new page;
	page2 = page1->next;
	page2->prev = page1;
	page2->next = new page;
	page3 = page2->next;
	page3->prev = page2;
	page3->next = new page;
	page4 = page3->next;
	page4->prev = page3;
	page4->next = new page;
	page5 = page4->next;
	page5->prev = page4;
	page5->next = new page;
	page6 = page5->next;
	page6->prev = page5;
	page6->next = page1;
	page1->prev = page6;
	first = page1;
	last = page6;

	doneMichele = donePaul = doneRob = doneTim = doneVern = foundMichele = foundPaul = foundRob = foundTim = foundVern = freePageMichele = freePagePaul = freePageRob = freePageTim = freePageVern = pageReplacedMichele = pageReplacedPaul = pageReplacedRob = pageReplacedTim = pageReplacedVern = false;
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
