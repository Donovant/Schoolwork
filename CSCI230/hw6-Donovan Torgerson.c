/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	******************************************************
	HW-6	CS230	20 points	Due: October 12
	******************************************************

	Write a program to generate a A tag cloud (see
	http://en.wikipedia.org/wiki/File:Web_2.0_Map.svg)

	The program must use a command-line argument
	(argv and argc) to specify a filename to be loaded
	(hw6.data). After checking for a valid command-line
	entry, your program must open the file and read in
	each word to see how many words there are. Then, using
	a dynamically allocated array of structures, re-read in
	each word and store it in the dynamically allocated
	array of structures. Use rewind to rewind the file.
	Do NOT close and reopen the file.

	Once you have each word stored, scan the array of structures
	to find out how many repeating words their are. Or more
	importantly, how many times does each word appear.

	Sort the array of structures such that the top 10 occurring
	words can be determined and listed on the screen. So the
	output would look like this:

	word1	occurences
	word2	occurences
	  .	    .
	  .	    .
	  .	    .

	Note the even spacing, this is required and accomplished by
	including a tab "\t" in the printf statement.


	NOTES:
	------
	1) The struct must hold an int and a char[50].

	2) Some words will have their first character uppercase due to
	   being at the beginning of a sentence, so you must correct for
	   uppercase first characters.

	3) Some words will have punctuation marks for their last character,
	   so you must remove those punctuation marks.

	REQUIREMENTS:
	-------------
	1. Your program must run in Streibel 115/109 or on Gandalf.aero.und.edu.

	2. Your full name must appear as a comment at the beginning of your
	   program.

	3. Your source code must be named hw6-yourname.c

	4. Email your source (subject hw6-yourname) to <<Redacted>>

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct wordStruct
{
	char word[50];
	int count;
}tmp, *w;

int main(int argc, char *argv[])
{
	int d, e, i, max, n, p = 0, r, s, sort = 1, t, x = 0, y = 0, lineCount = 0;
	size_t wordCount = 0;
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		exit(0); // trap file not opened
	}
	while ((n = fscanf(file, "%*50s")) != EOF)	 // Specifies max string length of 50 characters. If a word 
	{	 					// is more then 50 characters long it will be split into 2 words.
		wordCount++;
	}
	void *_tmp = realloc(w, (wordCount * sizeof(struct wordStruct)));
	w = _tmp;
	rewind(file);

	for (i = 0; i < wordCount; i++)  // Fill the array
	{
		fscanf(file, "%s", w[i].word);
	}

	for (x = 0; x < wordCount; x++)  // If first letter of the word is lowercase it converts to uppercase.
	{
		if ((w[x].word[0] >= 97) && (w[x].word[0] <= 122))
		{
			w[x].word[0] -= 32;
		}
	}

	for (x = 0; x < wordCount; x++)  // Remove . , and ? from the end of strings that contain them.
	{
		for (y = 0; w[x].word[y] != '\0'; y++)
		{
			if ((w[x].word[y] == '.') || (w[x].word[y] == ',') || (w[x].word[y] == '?'))
			{
				w[x].word[y] = '\0';
			}
		}
	}

	for (r = 0; r < wordCount; r++)  // Count occurances of same word
	{
		w[r].count = 1;
		for (s = r + 1; s < wordCount; s++)
		{
			while (strcmp(w[r].word, w[s].word) == 0)
			{
				w[r].count++;
				for (t = s; t < wordCount; t++)
				{
					strcpy(w[t].word, w[t + 1].word);
				}
				wordCount--;
			}
		}
	}
	s = 0;

	while (sort)  // sort the array 
	{
		sort = 0;
		s++;
		for (r = 0; i < wordCount - s; r++)
		{
			if (w[r].count < w[r + 1].count)
			{
				tmp = w[r];
				w[r] = w[r + 1];
				w[r + 1] = tmp;
				sort = 1;
			}
		}
	}
	for (d = 0; d < wordCount; d++)
	{
		max = d;
		for (e = d + 1; e < wordCount; e++)
		{
			if (w[e].count > w[max].count)
			{
				max = e;
			}
		}
		tmp = w[d];
		w[d] = w[max];
		w[max] = tmp;
	}

	for (i = 0; i < 10; i++)  // Print top 10 words
	{
		printf("%s	%d\n", w[i].word, w[i].count);
	}
	free(w);
	return 0;
}
