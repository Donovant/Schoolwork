/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Exact instructions not available, but the goal was to create
	and traverse a tree.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode {
	char  name;
	int   value;
	struct treeNode *leftPtr;
	struct treeNode *rightPtr;
};
typedef struct treeNode tree;

/********************************************************/
/* MAIN                                                 */
/********************************************************/
int main(int argc, char *argv[]) {
	int   target;
	tree *next;
	tree *root;
	tree *Left, *LLeft, *RLeft;
	tree *Right, *LRight, *RRight;
	tree *Leaf1, *Leaf2, *Leaf3, *Leaf4, *Leaf5, *Leaf6, *Leaf7, *Leaf8;

	// Check for command line arguments.
	if (argc == 1) {
		printf("ERROR - No command line arguments.\n");
		exit(0);
	}

	// Create root layer.
	root = (tree *)malloc(sizeof(tree));
	root->name = 'A';
	root->value = 4;

	// Create layer 1.
	Left = (tree *)malloc(sizeof(tree));
	Left->name = 'B';
	Left->value = 2;
	root->leftPtr = Left;

	Right = (tree *)malloc(sizeof(tree));
	Right->name = 'C';
	Right->value = 6;
	root->rightPtr = Right;

	// Create layer 2.
	LLeft = (tree *)malloc(sizeof(tree));
	LLeft->name = 'D';
	LLeft->value = 1;
	Left->leftPtr = LLeft;

	LRight = (tree *)malloc(sizeof(tree));
	LRight->name = 'E';
	LRight->value = 3;
	Left->rightPtr = LRight;

	RLeft = (tree *)malloc(sizeof(tree));
	RLeft->name = 'F';
	RLeft->value = 5;
	Right->leftPtr = RLeft;

	RRight = (tree *)malloc(sizeof(tree));
	RRight->name = 'G';
	RRight->value = 7;
	Right->rightPtr = RRight;

	// Create leaf layer.
	Leaf1 = (tree *)malloc(sizeof(tree));
	Leaf1->name = '1';
	Leaf1->value = 999;
	LLeft->leftPtr = Leaf1;

	Leaf2 = (tree *)malloc(sizeof(tree));
	Leaf2->name = '2';
	Leaf2->value = 999;
	LLeft->rightPtr = Leaf2;

	Leaf3 = (tree *)malloc(sizeof(tree));
	Leaf3->name = '3';
	Leaf3->value = 999;
	LRight->leftPtr = Leaf3;

	Leaf4 = (tree *)malloc(sizeof(tree));
	Leaf4->name = '4';
	Leaf4->value = 999;
	LRight->rightPtr = Leaf4;

	Leaf5 = (tree *)malloc(sizeof(tree));
	Leaf5->name = '5';
	Leaf5->value = 999;
	RLeft->leftPtr = Leaf5;

	Leaf6 = (tree *)malloc(sizeof(tree));
	Leaf6->name = '6';
	Leaf6->value = 999;
	RLeft->rightPtr = Leaf6;

	Leaf7 = (tree *)malloc(sizeof(tree));
	Leaf7->name = '7';
	Leaf7->value = 999;
	RRight->leftPtr = Leaf7;

	Leaf8 = (tree *)malloc(sizeof(tree));
	Leaf8->name = '8';
	Leaf8->value = 999;
	RRight->rightPtr = Leaf8;

	// Traverse tree.
	target = atoi(argv[1]);
	next = root;
	while (1) {
		printf("Visited node: %c\n", next->name);
		if (next->value == 999) exit(1);
		if (target <= next->value) next = next->leftPtr;
		else next = next->rightPtr;
	}


	return 0;
}
