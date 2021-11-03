#include "smulshell.h"

/**
* getstr - a function to read a string from  the cli
* @str: a string pointer
*
* Return: return 1 in success and -1 in failure
*/

int getstr(char *str)
{
char **lines;
size_t siz = 0;
signal(SIGINT, sigintHandler);
lines = malloc(24);
if (!lines)
{
return (-1);
}

if ((getline(lines, &siz, stdin)) == -1)
{
return (-1);
}

lines[0][siz] = '\0';

copystr(lines[0], str);

if (lines[0][siz - 2] == '\\')
{
do {
str[strleng(str) - 1] = ' ';
siz = 0;
prtprmpt(1);

if ((getline(lines, &siz, stdin)) == -1)
{
return (-1);
}
lines[0][siz] = '\0';

mixstr(lines[0], str);
} while (lines[0][siz - 2] == '\\');
}

free(lines);
return (1);
}

/**
* copystr - a function to copy to strings
* @src: the string to be copied
* @dest: the destination of the copied string
*
* Return: returns nothing (void)
*/

void copystr(char *src, char *dest)
{
int i = 0;
int j = 0;

if (!dest)
{
j = 0;
}

while (src[i] != '\0' && src[i] != '\n')
{
dest[j++] = src[i++];
}

dest[j] = '\0';
}

/**
* mixstr - a function to copy to strings and concatenate if
*	   the destination have a string already.
* @src: the string to be copied
* @dest: the destination of the copied string
*
* Return: returns nothing (void)
*/

void mixstr(char *src, char *dest)
{
int i = 0;
int j;

if (!dest)
{
j = 0;
}
else
{
j = strleng(dest);
}

while (src[i] != '\0' && src[i] != '\n')
{
dest[j++] = src[i++];
}

dest[j] = '\0';
}

/**
* brkstr - a function that breaks a long string in to arrauy of strings
* @lines: the string to be breakdown
* @c: a chacter specifier where to break the string
*
* Return: returns the array of the words.
*/

char **brkstr(char *lines, char c)
{
int i = 0, j = 0;
char **array, **tmp;

if (!lines || lines[0] == '\0')
{
return (NULL);
}
array = malloc(sizeof(*array) * 128);
if (array == NULL)
{
perror("Couldn't Allocate");
return (NULL); }
while (lines[i] != '\0')
{
if (j > 124)
{
tmp = realloc(array, sizeof(*array) * (i + 4));
if (tmp == NULL)
{
perror("Couldn't Reallocate");
return (NULL); }
else
{
array = tmp; }
}
if (lines[i] == c)
{
i++;
continue; }
array[j] = stringer(lines, i, array[j], c);
if (array[j] == NULL)
{
return (NULL); }
i += strleng(array[j++]);
}
array[j] = NULL;
return (array);
}

/**
* strleng - measures a length of a string
* @s: a string location pointer
*
* Return: returns length
*/

int strleng(char *s)
{
int lnth = 0;

while (s[lnth] != '\0')
{
lnth++;
}

return (lnth);
}
