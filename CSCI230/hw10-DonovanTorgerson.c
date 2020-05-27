/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	******************************************************
	HW-10	CS230		10 points	Due: Nov. 30
	******************************************************

	Modify hw9 such that you have multiple graph traversal
	methods available to the user. You already have the
	drunkard's (random) walk, so now add a simple greedy
	method (always take the arc with the lowest cost).
	Also, add a third method of your own (one you know
	of or that you designed yourself).

	Use a command line argument (argv, argc) to allow
	the user to select a traversal method: 0 - indicates
	the random walk, 1 - indicates the greedy method,
	and 2 - indicates the third method. Your output MUST
	clearly state what traversal method was used.

	For the random walk method you must now seed the
	random number generator to 12212012.

	Make sure your code clearly shows (exits with a
	warning) when you have failed to make it home (hit
	a dead end or fell into an infinite loop).

	EXTRA CREDIT (10 points):
	-------------------------
	Since all of these methods can fail (dead end or
	infinite loop), for extra credit add some backtracking.
	Since we would normally implement backtracking via
	recursion (which we don't have here), you can create
	a stack-like structure using another linked list
	(one that dynamically records your link traversals).
	With backtracking you should never get stuck at a
	dead end (infinite loops are still possible). To prove
	your backtracking works implement it with all three
	traversal methods and allow the user to engage the
	backtracking via a second command line argument option.
	For example:

	./hw10 0 - would implement the random walk without
			   backtracking.

	./hw10 0 1 - would implement the random walk with
			   backtracking.

	Make sure your email indicates that you did the extra
	credit!

	REQUIREMENTS:
	-------------
	1. Your program must run in Streibel 115/109 or on
	   Gandalf.aero.und.edu.

	2. Your full name must appear as a comment at the
	   beginning of your program.

	3. Your source code must be named hw10-yourname.c

	3. Email your source (subject hw10-yourname) to <<Redacted>>

*/

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

int randomWalk(node *walkFrom, int totalWeight, int iterations)
{
	if (strcmp(walkFrom->name, "Home") != 0) // Not home find the next place
	{
		int seed = rand() % 20;
		if (walkFrom->weights[0] == -5)
		{
			printf("walkfrom: %s\n", walkFrom->name);
			printf("weights are empty\n");
			return -128;
		}
		while (walkFrom->weights[seed] == -5 && iterations <= 15000)
		{
			seed = rand() % 20;
			iterations++;
		}
		if (iterations > 15000)
		{
			return -128;
		}
		else //Found a valid next path go there
		{
			totalWeight += walkFrom->weights[seed];
			//	  printf("going to: %s with weight: %d\n", walkFrom->connectsTo[seed]->name, walkFrom->weights[seed]);
			return randomWalk(walkFrom->connectsTo[seed], totalWeight, iterations);
		}
	}
	else // Home
	{
		return totalWeight;
	}
}

int greedyWalk(node *walkFrom, int totalWeight, int iterations)
{
	int min = -5, x = 0;
	if (walkFrom->weights[0] == -5)  // checks if weights are empty
	{
		if (strcmp(walkFrom->name, "Home") == 0)  // if empty and at home, return
		{
			return totalWeight;
		}
		else // if not home return back due to dead end
		{
			return -128;
		}
	}
	for (x = 0; x < 20; x++)  // find minimum weight
	{
		if (walkFrom->weights[x] != -5)
		{
			if (min == -5)
			{
				min = x;
			}
			else if (walkFrom->weights[x] < walkFrom->weights[min])
			{
				min = x;
			}
		}
	}
	if (iterations >= 15000)
	{
		return -128;
	}
	iterations++;
	totalWeight += walkFrom->weights[min];
	return greedyWalk(walkFrom->connectsTo[min], totalWeight, iterations);
}

int lazyWalk(node *walkFrom, int totalWeight, int iterations)
{
	int min = -5, x = 0;
	if (walkFrom->weights[0] == -5)  // checks if weights are empty
	{
		if (strcmp(walkFrom->name, "Home") == 0)  // if empty and at home, return
		{
			return totalWeight;
		}
		else // if not home return back due to dead end
		{
			return -128;
		}
	}

	if (iterations >= 15000)
	{
		return -128;
	}
	iterations++;
	totalWeight += walkFrom->weights[0];
	//  printf("going to: %s with weight: %d\n", walkFrom->connectsTo[0]->name, walkFrom->weights[0]);
	return lazyWalk(walkFrom->connectsTo[0], totalWeight, iterations);
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
		printf("Starting location is: %s\n", estStart);
		node *walkFrom = locateNode(firstEdge, estStart);
		if (strcmp(estStart, "Home") != 0)
		{
			if (option[0] == '0')
			{
				strcpy(name, "randomWalk");
				//	printf("option 0 randomWalk\n");
				test = randomWalk(walkFrom, totalWeight, iterations);
				//	printf("%d\n", test);
			}
			else if (option[0] == '1')
			{
				strcpy(name, "greedyWalk");
				//	printf("option 1 greedyWalk\n");
				test = greedyWalk(walkFrom, totalWeight, iterations);
				//	printf("%d\n", test);
			}
			else if (option[0] == '2')
			{
				strcpy(name, "lazyWalk");
				//	printf("option 2 lazyWalk\n");
				test = lazyWalk(walkFrom, totalWeight, iterations);
				//	printf("%d\n", test);
			}
		}
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
