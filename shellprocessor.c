#include "smulshell.h"

/**
* extr - a function to exit from the program
* @lines: an array of command and arguments
*
* Return: no return
*/

int extr(char *lines[])
{
int i = 0;
if (lines[1] == NULL)
{
exit(EXIT_SUCCESS); }
else if (atoi(lines[1]) > 0)
{
i = atoi(lines[1]); }
free(lines);
exit(i);
}

/**
* chngdir - a function to change a directory
* @lines: an array of commands and arguments
*
* Return: returns 0 in success and -1 if it fails
*/

int chngdir(char **lines)
{
if (lines[1] == NULL)
{
chdir(getenv("HOME"));
}
else if (chdir(lines[1]) == -1)
{
write(1, lines[0], strleng(lines[0]));
write(1, ": ", 3);
write(1, ": cd", strleng(": cd"));
write(1, ": can't cd to ", strleng(": can't cd to "));
write(1, lines[1], strleng(lines[1]));
write(1, "\n", 2);
return (-1);
}

free(lines);
return (1);
}

/**
* prtprmpt - a function to display the enter command character
* @i: an integer value to indicate which icon to display
*
* Return: void
*/

void prtprmpt(int i)
{
if (i == 0)
{
write(1, "KOTM-B$ ", strleng("KOTM-B$ "));
}
else if (i == 1)
{
write(1, "kotm-b> ", strleng("kotm-b> "));
}
}
