#include "smulshell.h"

/**
* list_it - a function which excutes the /bin/ls program to list files
* @lines: an array of command and arguments
*
* Return: returns 1 in success and -1 if it fails
*/

int list_it(char *lines[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}

if (child == 0)
{
execve("/bin/ls", lines, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(lines);

return (1);
}

/**
* binexct - a function which excutes the /bin/cat program to show text files
* @lines: an array of command and arguments
*
* Return: returns 1 in success and -1 if it fails
*/

int binexct(char *lines[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}
if (child == 0)
{
execve("/bin/cat", lines, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(lines);

return (1);
}

/**
* bltncom - a function to excute when unlisted command entered
* @lines: is a pointer to pointer of characters
*
* Return: returns an integer
*/

int bltncom(char **lines)
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}

if (child == 0)
{
execve(lines[0], lines, NULL);
if (errno != 0)
{
return (errno);
}
}
else
{
waiter = wait(&status);

if (waiter == -1)
{
perror("Waiting");
}
}

free(lines);
return (0);
}

/**
* pwdfunc - a function which prints the current path
* @lines: an array of command and arguments
*
* Return: returns 1 in success and -1 if it fails
*/

int pwdfunc(char *lines[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
perror("Forking");

if (child == 0)
{
execve("/bin/pwd", lines, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
perror("Waiting");
}
free(lines);
return (1);
}

/**
* echofunc - a function which echo back any text
* @lines: an array of command and arguments
*
* Return: returns 1 in success and -1 if it fails
*/

int echofunc(char *lines[])
{
int status;
pid_t waiter, child;

child = fork();
if (child == -1)
{
perror("Forking");
}
if (child == 0)
{
execve("/bin/echo", lines, NULL);
}
else
{
waiter = wait(&status);
if (waiter == -1)
{
perror("Waiting");
}
}
free(lines);

return (1);
}
