#ifndef SIMISHELL_H
#define SIMISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char **environ;
extern int errno;

/**
 * struct selectfunction - a struct array of functions
 * @command: a pointer to the caharacter of the command string
 * @funcptr: a pointer to a function
 */

typedef struct selectfunction
{
char *command;
int (*funcptr)(char **lines);
} selecte;

void sigintHandler(int sig_num __attribute__((unused)));
void prtprmpt(int i);
int extr(char *lines[]);
int binexct(char *lines[]);
int getstr(char *str);
int shllprssr(char **lines, char **argv);
char **brkstr(char *lines, char c);
int _getline(char **lines, size_t *lnth);
void farewell(void);
void description(void);
void printstar(void);
void printstr(char *s);
int strleng(char *s);
void copystr(char *src, char *dest);
int strcomp(char *str, char *equ);
void mixstr(char *src, char *dest);
int list_it(char **lines);
int (*getfunc(char *str))(char **lines);
int echofunc(char *lines[]);
int bltncom(char **lines);
int chngdir(char **lines);
int pwdfunc(char *lines[]);
int envir(char *lines[]);
int maker(char *lines[]);
char _getchar(void);
char *stringer(char *lines, int i, char *str, char c);

#endif
