#include "smulshell.h"

/**
 * copyarray - a function to copy string array to another string array variable
 * @lines: a string array to be copied
 * 
 * Return: returns the copied array
 */

char **copyarray(char **lines)
{
char **array;
int i = 1;

array = malloc(64);
if (!array)
return (NULL);

while (lines[i] != NULL)
{
array[(i - 1)] = malloc(32);
if (!array[(i - 1)])
return (NULL);

copystr(lines[i], array[(i - 1)]);
i++;
}

return (array);
}

/**
 * sigintHandler - a function to handle the ctrl-c signal
 * @sig_num: an integer signal indicator
 *
 * Return: void function
 */

void sigintHandler(int sig_num __attribute__((unused)))
{
signal(SIGINT, sigintHandler);
write(1, "\n", 2);
prtprmpt(0);
fflush(stdout);
}

/**
 * main - a the main function of the shell
 * @argc: the number of arguments given
 * @argv: an array of given argument strings
 *
 * Return: returns an integer
 */

int main(int argc __attribute__((unused)), char **argv)
{
char *lines;

lines = malloc(256);
if (!lines)
{
perror("Allocation");
exit(1);
}

if (!isatty(STDIN_FILENO))
{
if (getstr(lines) == (-1))
{
write(1, "\n", 2);
exit(1);
}
if (shllprssr(brkstr(lines, ' '), argv) == -1)
{
perror("Error");
}

exit(0);
}

do {
prtprmpt(0);
if (getstr(lines) == (-1))
{
write(1, "\n", 2);
exit(0);
}

if ((shllprssr(brkstr(lines, ' '), argv)) == -1)
{
perror("Error");
}
} while (1);

return (0);
}
