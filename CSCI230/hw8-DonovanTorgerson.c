/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	******************************************************
	HW-8	CS230		10 points	Due: Nov. 5
	******************************************************

	Write a program that uses a pointer-based linked
	list. You should use the following struct (declared
	as a global):

	   struct node {
		  char name[42];
		  struct node *next;
	   };

	Note that no other variables can be global.

	To populate your linked list open the hw8.data file and
	read in the contents. The file format is as follows:
	name op_code
	  For example:
	  Vlad a
	  Cullen a
	  Morticia a
	  Ophelia a
	  Smurf a
	  Morticia d

	The name will be a string. The op_code will be a character
	('a' or 'd'), where 'a' indicates that you should add this
	person to the linked-list, 'd' indicates that you should
	delete this person from the linked-list. Note that when
	you add a person you must add them in increasing order. I.e.
	we are adding them as an insertion sort (no, you cannot presort
	the list). This MUST be seperate functions (adding and deleting).

	You also need to provide output that proves your program works.
	After the last data item has been processed, your program must
	display the contents of the linked-list. This MUST be a seperate
	function.

	Your program must also correctly free all links of the list
	on termination. This MUST be a seperate function.

	EXTRA CREDIT (10 points):
	-------------------------

	Instead of creating a single link linked-list, create a doubly
	linked linked list. Populate the list accordingly and display
	the contents of the list from both directions (your must clearly
	state which display is which). Also note in your email, that you
	did the extra credit.

	The extra credit grading is atomic - it either works (+10 points)
	or it doesn't (0 points).

	REQUIREMENTS:
	-------------
	1. Your program must run in Streibel 115/109 or on Gandalf.aero.und.edu.

	2. Your full name must appear as a comment at the beginning of your
	   program.

	3. Your source code must be named hw8-yourname.c

	3. Email your source (subject hw8-yourname) to <<Redacted>>

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct nodeStruct
{
	struct nodeStruct *back;
	char name[42];
	struct nodeStruct *next;
};

typedef struct nodeStruct node;

node *findLast(node *first) //Finds last node and returns pointer to last element
{
	int length = 0;
	node *current;
	current = first;
	while (current->next != NULL)
	{
		length++;
		current = current->next;
	}
	return current;
}

int insertNode(node *first, char *name)
{
	node *current; // pointer to traverse array
	node *prev; // pointer to previous node
	current = first;
	while (1)
	{
		if (strcmp(current->name, name) == 0)
		{
			return 0;
		}
		if (current->next == NULL)
		{
			current->next = calloc(1, sizeof(node));
			strcpy(current->next->name, name);
			current->next->back = current;
			prev->next = current;
			current->next->next = NULL;
			return 1;
		}
		if ((strcmp(current->name, name) < 0) && ((strcmp(current->next->name, name) > 0)))
		{
			node *newNode;
			newNode = calloc(1, sizeof(node));
			strcpy(newNode->name, name);
			newNode->next = current->next;
			current->next->back = newNode;
			current->next = newNode;
			newNode->back = current;
			return 1;
		}
		prev = current;
		current = current->next;
	}
}

int removeNode(node *first, char *name)
{
	node *current; // pointer to traverse array
	node *prev; // pointer to previous node
	node *tmp; // temporary pointer
	current = first;
	tmp = NULL;
	while (1)
	{
		if (current->next == NULL)
		{
			return 0;
		}

		if (strcmp(current->next->name, name) == 0)
		{
			tmp = current->next->next;
			tmp->back = current;
			free(current->next);
			current->next = tmp;
			return 1;
		}
		prev = current;
		current = current->next;
	}
}

int printForward(node *first)
{
	if (first == NULL)
	{
		return 0;
	}
	printf("%s\n", first->name);
	printForward(first->next);
	return 1;
}

int printBackward(node *first)
{
	if (first == NULL)
	{
		return 0;
	}
	printf("%s\n", first->name);
	printBackward(first->back);
	return 1;
}

int destroy(node *first)
{
	if (first == NULL)
	{
		return 0;
	}
	destroy(first->next);
	free(first);
}

int main()
{
	node *list;
	node *first;
	first = NULL;
	char line[100];
	char code[42];
	char tmpName[42];
	FILE *file = fopen("hw8.data", "r");
	while (fscanf(file, "%s %s", tmpName, code) != EOF)
	{
		tmpName[0] = toupper(tmpName[0]);
		if (strcmp(code, "a") == 0) // Add to array
		{
			if (first == NULL)
			{
				first = calloc(1, sizeof(node));
				strcpy(first->name, tmpName);
				first->back = NULL;
			}
			else if (strcmp(first->name, tmpName) > 0)
			{
				node *newFirst;
				newFirst = calloc(1, sizeof(node));
				newFirst->next = first;
				first->back = newFirst;
				first = newFirst;
				strcpy(first->name, tmpName);
				first->back = NULL;
			}
			else
			{
				insertNode(first, tmpName);
			}
		}
		else if (strcmp(code, "d") == 0) // Delete from array
		{
			if (first != NULL)
			{
				if ((strcmp(first->name, tmpName) == 0))
				{
					if (first->next == NULL)
					{
						free(first);
						first->next->back = NULL;
					}
					else
					{
						node *oldFirst;
						oldFirst = first;
						first = first->next;
						first->back = NULL;
						free(oldFirst);
					}
				}
				else
				{
					removeNode(first, tmpName);
				}
			}
		}
	}
	printf("List from front to back:\n");
	printForward(first);
	printf("\n\nList from back to front:\n");
	printBackward(findLast(first));
	destroy(first);
	fclose(file);
	return 0;
}
