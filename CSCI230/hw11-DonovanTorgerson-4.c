/*

	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	******************************************************
	HW - 11	CS230		40 points	Due : Dec. 7
	* *****************************************************

	For this assignment you will divide up HW - 10 and develop a
	Makefile to practice using the compiler and linker with
	libraries.All files will be strictly C code - no C++!

	Part 1 (10 points) :
		------------------
		Seperate HW - 10 into the following files :
	1. The MAIN routine(hw11 - yourname.c).
	2. The random walk(hw11 - A - yourname.c) and its header file
	(hw11 - A - yourname.h).
	3. The greedy walk(hw11 - B - yourname.c) and its header file
	(hw11 - B - yourname.h).
	4. The third walk(hw11 - C - yourname.c) and its header file
	(hw11 - C - yourname.h).

	Write a Makefile that compiles and links the above in 2!!!
	steps.You MUST call this Makefile "Makefile1".


	Part 2 (5 points) :
		------------------
		Write a Makefile that creates a STATIC library / archive
		(hw11 - lib - yourname.a) out of the associated c files(#2, 3, &
			4) and that compiles and links hw11 - yourname.c with your static
		library.You MUST call this Makefile "Makefile2".


		Part 3 (5 points) :
		------------------
		Write a Makefile that creates SHARED a library
		(hw11 - lib - yourname.so) out of the associated c files(#2, 3, &
			4) and that compiles and links hw11 - yourname.c with your shared
		library.You MUST call this Makefile "Makefile3".


		Part 4 (20 points) :
		------------------ -
		Modify hw11 - yourname.c to use the SHARED library
		(hw11 - lib - yourname.so) dynamically(using dlopen).Call
		this MAIN program hw11 - yourname - 4.c

		Write a Makefile that compiles and links hw11 - yourname - 4.c
		with your dynamic shared library.You MUST call this
		Makefile "Makefile4".

		Note that all of the functionallity must exist in this program
		as it did in hw10 to earn full credit.

		REQUIREMENTS:
	------------ -
	1. Your program must run in Streibel 115 / 109 or on
	Gandalf.aero.und.edu.

	2. Your full name must appear as a comment at the
	beginning of your program.

	3. Your source code files must be named as stated above.

	4. Create a tarball of your code and name it hw11 - yourname.tar.

	4. Email your tarball(subject hw11 - yourname) to
	<< Redacted >>

	*Submissions that do not follow the above requirements will
	NOT be graded and will receive 0 points.

*/

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct edgeStruct
{
	struct nodeStruct *connectsTo;
	struct edgeStruct *next;
};

typedef struct edgeStruct edge;

struct nodeStruct
{
	struct nodeStruct *connectsTo[20];
	char name[84];
	int weights[20];
};

typedef struct nodeStruct node;

edge newInsert(edge *firstEdge, char *incEstName)
{
	edge *newEdge;
	if (firstEdge->next == NULL)
	{
		newEdge = calloc(1, sizeof(edge));
		newEdge->connectsTo = calloc(1, sizeof(node));
		strcpy(newEdge->connectsTo->name, incEstName);
		firstEdge->next = newEdge;
		newEdge->next = NULL;
		return *newEdge;
	}
	else
	{
		return newInsert(firstEdge->next, incEstName);
	}
}

int findEmptyWeight(node *current, int x)
{
	if (current->weights[x] != -5)
	{
		x++;
		return findEmptyWeight(current, x);
	}
	else
	{
		return x;
	}
}

node * locateNode(edge *first, char *est)
{
	node *current = first->connectsTo; //get current location
	if (strcmp(current->name, est) != 0) //if the current locations does NOT contain the est name
	{
		current = locateNode(first->next, est); //Pass the next node into the locateNode
	}
	return current;
}

edge lastEdge(edge *firstEdge)
{
	if (firstEdge->next == NULL)
	{
		return *firstEdge;
	}
	else
	{
		return lastEdge(firstEdge->next);
	}
}

int destroy(edge *first)
{
	edge *current;
	current = first;
	if (current->next != NULL)
	{
		first = current->next;
		free(current->connectsTo);
		free(current);
		destroy(first);
	}
	first = NULL;
	free(first);
	return 0;
}

void constructor(node *first)
{
	int x = 0;
	for (x = 0; x < 20; x++)
	{
		first->weights[x] = -5;
	}
}

int main(int argc, char *argv[])
{
	int x = 0, count = 0, seed, tmp1 = 0, sortOpt = -5, iterations = 0, lines = 0, wt = 0;
	int totalWeight = 0;
	int test = 0;
	char code[42], estA[42], estB[42], estStart[42], incEstName[84], line[100], name[42], option[4], tmpName[42];
	strcpy(option, argv[1]);
	node *list;
	node *first;
	node *est1;
	node *est2;
	edge *firstEdge;

	int(*random)(nodeStruct, int, int);
	int(*greedy)(nodeStruct, int, int);
	int(*lazy)(nodeStruct, int, int);

	firstEdge = NULL;
	first = NULL;
	srand(12212012);  // srand(time(NULL));
	seed = rand() % 20;
	FILE *file = fopen("hw9.data", "r");
	if (file == NULL)
	{
		exit(0); //trap file not opened
	}
	while ((fscanf(file, "%s", incEstName) != EOF) && strcmp(incEstName, "STOP") != 0)
	{
		if (firstEdge == NULL)
		{
			firstEdge = calloc(1, sizeof(edge));
			firstEdge->connectsTo = calloc(1, sizeof(node));
			constructor(firstEdge->connectsTo);
			strcpy(firstEdge->connectsTo->name, incEstName);
			firstEdge->next = NULL;
		}
		else
		{
			constructor(newInsert(firstEdge, incEstName).connectsTo); // Inserts new edge and runs it's corresponding node through the weights constructor      
		}
	}
	while ((fscanf(file, "%s %s %d", estA, estB, &wt) != EOF) && strcmp(estA, "STOP") != 0 && strcmp(estB, "STOP") != 0 && wt != 0)
	{
		node *est1 = locateNode(firstEdge, estA);
		node *est2 = locateNode(firstEdge, estB);
		tmp1 = findEmptyWeight(est1, x);
		est1->connectsTo[tmp1] = est2;
		est1->weights[tmp1] = wt;
	}
	while (fscanf(file, "%s", estStart) != EOF)
	{
		void *library;
		library = dlopen("./hw11-lib-DonovanTorgerson.so", RTLD_NOW);

		random = dlsym(library, "randomWalk");
		greedy = dlsym(library, "greedyWalk");
		lazy = dlsym(library, "lazyWalk");
		if (library == NULL)
		{
			printf("%s\n", dlerror());
		}
		printf("Starting location is: %s\n", estStart);
		node *walkFrom = locateNode(firstEdge, estStart);
		if (strcmp(estStart, "Home") != 0)
		{
			if (option[0] == '0')
			{
				strcpy(name, "randomWalk");
				//	printf("option 0 randomWalk\n");
				//      void *library = dlopen("./hw11-lib-DonovanTorgerson.so", RTLD_NOW);
				//	  int (*value)(nodeStruct, int, int) = dlsym(library, "randomWalk");
				test = random(walkFrom, totalWeight, iterations);
				//	  test = randomWalk(walkFrom, totalWeight, iterations);
				//	  dlclose(library);
				//	printf("%d\n", test);
			}
			else if (option[0] == '1')
			{
				strcpy(name, "greedyWalk");
				//	printf("option 1 greedyWalk\n");
				test = greedy(walkFrom, totalWeight, iterations);
				//	printf("%d\n", test);
			}
			else if (option[0] == '2')
			{
				strcpy(name, "lazyWalk");
				//	printf("option 2 lazyWalk\n");
				test = lazy(walkFrom, totalWeight, iterations);
				//	printf("%d\n", test);
			}
		}
		dlclose(library);
		if (strcmp(estStart, "Home") == 0)
		{
			printf("\nYou are already home.\n");
		}
	}
	if (test == -128)
	{
		printf("\nERROR!!!\nInfinite Loop likely. Please try again\n");
	}
	else
	{
		printf("\nTo get %s from %s using the %s function cost %d\n", "Home", estStart, name, test);
	}
	destroy(firstEdge);
	fclose(file);
	return 0;
}
