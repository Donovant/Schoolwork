/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw9.pdf

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
		//	constructor(newEdge->connectsTo);
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
		//	printf("name to be deleted: %s\n", current->next->connectsTo->name);
		first = current->next;
		free(current->connectsTo);
		free(current);
		destroy(first);
	}
	first = NULL;
	free(first);
	return 0;
}

int doTheWalk(edge *firstEdge, int totalWeight, char *estStart)
{
	node *walkFrom = locateNode(firstEdge, estStart);
	int seed = rand() % 20;
	//  printf("seed after setting: %d\n", seed);
	if (walkFrom->weights[seed] != -5)
	{
		//    printf("total weight of %d plus %d is ", totalWeight, walkFrom->weights[seed]);
		totalWeight += walkFrom->weights[seed];
		//	printf("%d\n", totalWeight);
		//	printf("walking from %s to %s with weight of %d\n", walkFrom->name, walkFrom->connectsTo[seed]->name, walkFrom->weights[seed]);
		walkFrom = locateNode(firstEdge, walkFrom->connectsTo[seed]->name);
		if ((strcmp(walkFrom->name, "Home") == 0) || totalWeight > 15000) // If we are home OR if we totalWeight is over 15000 (in which case an infinite loop is likely)
		{
			//	  printf("current location is: %s and totalWeight is %d. Returning to main\n", walkFrom->name, totalWeight);
			return totalWeight;  // I'm home, return totalWeight;
		}
		else
		{
			doTheWalk(firstEdge, totalWeight, walkFrom->name);
		}
	}
	else
	{
		doTheWalk(firstEdge, totalWeight, estStart);
	}
}

void constructor(node *first)
{
	int x = 0;
	for (x = 0; x < 20; x++)
	{
		first->weights[x] = -5;
		//	printf("name: %s wt: %d\n", first->name, first->weights[x]);
	}
}

int main()
{
	int x = 0, count = 0, seed, tmp1 = 0, totalWeight = 0;
	node *list;
	node *first;
	node *est1;
	node *est2;
	edge *firstEdge;
	firstEdge = NULL;
	first = NULL;
	char line[100];
	char code[42];
	char tmpName[42];
	int lines = 0, wt = 0;
	char incEstName[84];
	char estA[42];
	char estB[42];
	char estStart[42];
	srand(time(NULL));
	seed = rand() % 20;
	//  printf("seed is %d\n", seed); 
	FILE *file = fopen("hw9.data", "r");
	if (file == NULL)
	{
		exit(0); //trap file not opened
	}
	while (fgets(line, sizeof(line), file) != NULL) //Gets number of lines of file
	{
		lines++;
	}
	rewind(file);
	//  printf("line count: %d\n", lines);
	while ((fscanf(file, "%s", incEstName) != EOF) && strcmp(incEstName, "STOP") != 0)
	{
		//    printf("input string is : %s\n", incEstName);
		if (firstEdge == NULL)
		{
			firstEdge = calloc(1, sizeof(edge));
			firstEdge->connectsTo = calloc(1, sizeof(node));
			constructor(firstEdge->connectsTo);
			strcpy(firstEdge->connectsTo->name, incEstName);
			firstEdge->next = NULL;
			//	  printf("firstEdge->connectsTo->name: %s\n", firstEdge->connectsTo->name);
		}
		else
		{
			constructor(newInsert(firstEdge, incEstName).connectsTo); // Inserts new edge and runs it's corresponding node through the weights constructor
		}
	}
	while ((fscanf(file, "%s %s %d", estA, estB, &wt) != EOF) && strcmp(estA, "STOP") != 0 && strcmp(estB, "STOP") != 0 && wt != 0)
	{
		//    printf("x: %d\n", x);
		//    printf("input string is : %s %s %d\n", estA, estB, wt);
		node *est1 = locateNode(firstEdge, estA);
		//	printf("est1->name is: %s\n", est1->name);
		node *est2 = locateNode(firstEdge, estB);
		//	printf("est2->name is: %s\n", est2->name);
		tmp1 = findEmptyWeight(est1, x);   //   int findEmptyWeight(node *current, int x)
		est1->connectsTo[tmp1] = est2;
		est1->weights[tmp1] = wt;
		//	printf("%s weight to %s is %d\n", est1->name, est2->name, est1->weights[tmp1]);
	}

	while (fscanf(file, "%s", estStart) != EOF)
	{
		printf("Starting location is: %s\n", estStart);
		node *walkFrom = locateNode(firstEdge, estStart);
		if (estStart != "Home")
		{
			totalWeight = doTheWalk(firstEdge, totalWeight, estStart); // int doTheWalk(edge *firstEdge, int totalWeight, char *estStart)
		}
	}
	if (totalWeight > 15000)
	{
		//    printf("\nTo get %s from %s cost %d\n", "Home", estStart, totalWeight);
		printf("\nERROR!!!\nPlease try again\n");
	}
	else
	{
		//     printf("\nERROR!!!\nPlease try again\n");
		printf("\nTo get %s from %s cost %d\n", "Home", estStart, totalWeight);
	}
	destroy(firstEdge);
	fclose(file);
	return 0;
}
