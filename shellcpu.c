#include "smulshell.h"

/**
 * getfunc - a function which selects a function based on the commands
 * @str: a command string pointer
 *
 * Return: returns 1 in success and -1 if it fails.
 */

int (*getfunc(char *str))(char **lines)
{
int i = 0;
selecte selector[] = {
{"ls", list_it},
{"l", list_it},
{"ll", list_it},
{"exit", extr},
{"echo", echofunc},
{"cd", chngdir},
{"cat", binexct},
{"pwd", pwdfunc},
{"env", envir},
{"printenv", envir},
{"/bin/printenv", envir},
{"/bin/env", envir},
{"mkdir", maker},
{NULL, NULL}};

while (!strcomp(selector[i].command, str) && (selector[i].command != NULL))
{
i++;
}

if (selector[i].command == NULL)
{
return (NULL);
}

return (selector[i].funcptr);
}

/**
 * shllprssr - a function which excutes the given commands
 * @lines: a pointer to an array of strings
 * @argv: a pointer to the array of arguments
 *
 * Return: returns 1 in success and -1 if it fails
 */

int shllprssr(char **lines, char **argv)
{
int check;
int i = 0;

if (!lines)
{
return (1); }
if (getfunc(lines[0]) == NULL)
{
i = bltncom(lines);
if (i != 0)
{
for (i = 0; lines[0][i] != '\0'; i++)
{
if (lines[0][i] == '/')
{
check = 1;
break; }}
if (check == 1)
{
write(1, argv[0], strleng(argv[0]));
write(1, ": ", 3);
write(1, lines[0], strleng(lines[0]));
write(1, ": No such file or directory\n", 28);
exit(EXIT_FAILURE); }
else
{
write(1, lines[0], strleng(lines[0]));
write(1, ": not found\n", strleng(": not found\n"));
exit(EXIT_FAILURE); }}
}
else
{
getfunc(lines[0])(lines); }
return (1);
}
