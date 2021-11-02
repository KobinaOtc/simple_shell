#include "smulshell.h"

/**
 * _getchar - a function that reads a character from the standard input
 *
 * Return: returns the read character
 */

char _getchar(void)
{
char *buf;
char c;
int i = 0;

buf = malloc(2);

if (!buf)
return (-1);

fflush(stdout);

i = read(1, buf, 1);
if (i == -1)
{
perror("Reading Char");
return (-1);
}
else if (i == 0)
{
write(1, "\n", 2);
fflush(stdout);
exit(1);
}

c = *buf;

return (c);
}

/**
 * _getline - a function to read a lines from the standard input
 * @lines: a pointer to a pointer of location to save the string
 * @lnth: the size of the characters read
 *
 * Return: returns the size of the read string
 */

int _getline(char **lines, size_t *lnth)
{
size_t limit = 25;
char *tmp;

lines[0] = malloc(25);
if (!lines[0])
return (-1);
*lnth = 0;

while (lines[0][*lnth - 1] != '\n')
{
lines[0][*lnth] = _getchar();
*lnth += 1;

if (*lnth > (limit - 3))
{
tmp = realloc(lines[0], limit + 10);
if (tmp)
lines[0] = tmp;
else
perror("Reallocation");
limit += 10;
}
}

return (*lnth);
}

/**
 * rpt_txt - a function to echo back any text you gave it
 * @lines: an array of command and arguments
 *
 * Return: returns 1 in success and -1 if it fails
 */

int rpt_txt(char *lines[])
{
int i = 1;

if (lines[i] == NULL)
{
write(1, "\n", 2);
return (1);
}

while (lines[i] != NULL)
{
write(1, lines[i], strleng(lines[i]));
i++;
if (lines[i] != NULL)
{
write(1, " ", 2);
}
}
write(1, "\n", 2);

return (1);
}
