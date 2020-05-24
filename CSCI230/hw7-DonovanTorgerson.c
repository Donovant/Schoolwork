/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw7.pdf

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct directory
{
	char circle[42];
	int start;
}dir[10];

struct FileAlloc
{
	int prev;
	char name[42];
	char phone[8];
	int next;
}FAT[100];

int freeFATloc(char *name, char *phone) //Finds first free loc in FAT array, fills it and returns it's index
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (FAT[i].prev == -1)
		{
			//	  printf("Name and phone to add are %s and %s\n", name, phone);
			strcpy(FAT[i].name, name);
			strcpy(FAT[i].phone, phone);
			//	  printf("Added %s to FAT[%d].name and %s to FAT[%d].phone\n", FAT[i].name, i, FAT[i].phone, i);
			//	  printf("in freeFATloc: FAT[%d].name = %s and FAT[%d].phone = %s\n", i, FAT[i].name, i, FAT[i].phone);
			//	  printf("in freeFATloc: phone = %s\n", phone);
			return i;
		}
	}
	printf("something failed");
	return -1;
}

int freeDIRloc(char *circle) //Finds first free loc in Directory array, fills it and returns it's index
{
	int x = 0, found = 0, idx = 0;
	for (x = 0; x < 10; x++)
	{
		if ((strcmp(circle, dir[x].circle)) == 0)
		{
			//	  printf("Found dir = %s at index = %d\n", circle, x);
			idx = x;
			found = 1;
			break;
		}
	}
	if (found == 0) // Directory not found, finding first open index
	{
		//    printf("Circle we are going to add: %s\n", circle);
		for (x = 0; x < 10; x++)
		{
			if (dir[x].start == -1)
			{
				//	    printf("first open index found for dir = %s at index = %d\n", circle, x);
				strcpy(dir[x].circle, circle);
				idx = x;
				dir[x].start = 9999;
				//		printf("dir[%d].circle = %s dir[%d].start = %d\n", x, dir[x].circle, x, dir[x].start);
				break;
			}
		}
	}
	//  printf("freeDIRloc idx = %d\n", idx);
	return idx;
}

int findLast(int index) //Finds last element of circle in FAT
{
	int x = index;
	if (FAT[x].next == -1)
	{
		return x;
	}
	else
	{
		x = FAT[x].next;
		return findLast(x);
	}
}

int delete(char *name, int index)
{
	int x = index;
	if (FAT[x].next == -1)
	{
		printf("found %s in FAT[%d] that matches %s\n", FAT[x].name, x, name);
		return x;
	}
	else
	{
		x = FAT[x].next;
		return delete(name, x);
	}
}

int query(int index)
{
	int x = index;
	if (FAT[x].next == -1)
	{
		printf("%d	%d	%s	%s	%d\n", x, FAT[x].prev, FAT[x].name, FAT[x].phone, FAT[x].next);
		return x;
	}
	else
	{
		x = FAT[x].next;
		printf("%d	%d	%s	%s	%d\n", x, FAT[x].prev, FAT[x].name, FAT[x].phone, FAT[x].next);
		return findLast(x);
	}
}

int main()
{
	char line[100] = " ";
	char circle[42] = " ";
	char name[42] = " ";
	char phone[42] = " ";
	char code[42] = " ";
	int lines = 0, x = 0, y = 0, z = 0, fatIndex = 0, dirIndex = 0, dirMax = 0, tmpIndex = 0, dirLoc = 0, currentLoc = 0;

	for (x = 0; x < 10; x++) //Intitalizes dir.start to -1
	{
		dir[x].start = -1;
	}

	for (x = 0; x < 100; x++) //Intitalizes FAT.prev and FAT.next to -1
	{
		FAT[x].prev = -1;
		FAT[x].next = -1;
	}

	FILE *file = fopen("hw7.data", "r");
	while (fgets(line, sizeof(line), file) != NULL) //Gets number of lines of file
	{
		lines++;
	}
	rewind(file);

	if (file != NULL)
	{
		for (x = 0; x < lines; x++)
		{
			if (fscanf(file, "%s%s%s%s", circle, name, phone, code) != EOF)
			{
				//		dirIndex = freeDIRloc(circle);
				//		printf("dirIndex = %d", dirIndex);
				if (strcmp(code, "a") == 0)  // Add to FAT
				{
					dirIndex = freeDIRloc(circle);
					fatIndex = freeFATloc(name, phone);
					if (dir[dirIndex].start == 9999)
					{
						//		    printf("Setting dir[%d].start(%d) to fatIndex(%d)\n", dirIndex, dir[dirIndex].start, fatIndex);
						dir[dirIndex].start = fatIndex;
						//			printf("after assigning dir[%d].start(%d) from fatIndex(%d)\n", dirIndex, dir[dirIndex].start);
						FAT[fatIndex].prev = -(dirIndex + 1000);
						//			printf("after assigning FAT[%d].prev to -(dirIndex(%d)+1000)\n", fatIndex, dirIndex);
					}
					else // if(
					{
						//		    printf("tmpIndex before call = %d\n", tmpIndex);
						tmpIndex = findLast(dir[dirIndex].start);
						//			printf("tmpIndex after call = %d	fatIndex = %d\n", tmpIndex, fatIndex);
						FAT[fatIndex].prev = tmpIndex;
						//			printf("after assigning FAT[%d].prev to %d from tmpIndex(%d)\n", fatIndex, FAT[fatIndex].prev, tmpIndex);
						FAT[tmpIndex].next = fatIndex;
						//			printf("after assigning FAT[%d].next to %d from fatIndex(%d)\n", tmpIndex, FAT[tmpIndex].next, fatIndex);
					}
				}
				if (strcmp(code, "d") == 0)  // Delete from FAT
				{
					printf("in 'd' code\n");
					for (x = 0; x < 10; x++)
					{
						if (strcmp(circle, dir[x].circle) == 0) // Finds our Circle of interest in order to traverse FAT in search of entry
						{
							dirLoc = x;
							break;
						}
					}
					z = delete(name, dirLoc);
					printf("z = %d\n", z);
					printf("FAT[%d].prev = %d\n", z, FAT[z].prev);
					printf("FAT[%d].next = %d\n", z, FAT[z].next);
					FAT[FAT[z].prev].next = FAT[z].next;
					FAT[FAT[z].next].prev = FAT[z].prev;
					//		printf("FAT[%d].prev = %d\n", z, FAT[z].prev);
					//		printf("FAT[%d].next = %d\n", z, FAT[z].next);
					strcpy(FAT[z].name, " ");
					FAT[z].prev = -1;
					FAT[z].next = -1;

				}
				if (strcmp(code, "q") == 0)  // Query FAT
				{
					printf("in 'q' code\n");
					for (x = 0; x < 10; x++)
					{
						if (strcmp(circle, dir[x].circle) == 0) // Finds our Circle of interest in order to traverse FAT in search of entry
						{
							dirLoc = x;
							break;
						}
					}
					z = query(dirLoc);
				}
			}
		}
	}
	//  int junk = 0;
	for (y = 0; dir[y].start != -1; y++)
	{
		printf("dir[%d]: %s\n", y, dir[y].circle);
	}
	for (y = 0; y < 100; y++) //for(y = 0; FAT[y].prev != -1; y++)
	{
		printf("%d	%s	%d	%d\n", y, FAT[y].name, FAT[y].prev, FAT[y].next);
		//    printf("FAT[%d].prev: %d FAT[%d].name: %s phone: %s FAT[%d].next: %d\n", y, FAT[y].prev, y, FAT[y].name, FAT[y].phone, y, FAT[y].next);    
	}
	return 0;
}
