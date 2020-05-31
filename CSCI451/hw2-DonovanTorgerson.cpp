/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw2.txt

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	int count = 0, ExitCode = 1;
	pid_t PID;
	while (1)
	{
		PID = fork();
		if (PID == 0)  // If its the child
		{
			if (count == 0)
			{
				execl("/usr/bin/gcalctool", "/usr/bin/gcalctool", NULL);
			}
			else if (count == 1)
			{
				execl("/usr/bin/glxgears", "/usr/bin/glxgears", NULL);
			}
			else
			{
				execl("/usr/bin/gnome-character-map", "/usr/bin/gnome-character-map", NULL);
			}
		}
		else // If its the parent
		{
			if (count <= 1)
			{
				count++;
			}
			else
			{
				count = 0;
			}
			usleep(1500000);
			kill(PID, SIGTERM);
			waitpid(PID, &ExitCode, 0);
		}
	}
	return 0;
}