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

#include <stdio.h>

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

int lazyWalk(node *walkFrom, int totalWeight, int iterations); // function prototype for lazyWalk
