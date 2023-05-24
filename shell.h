#ifndef SHELL_H 
#define SHELL_H 

/* headers */
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <signal.h>
#include <stdint.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
/*===================*/

/* decleration */
extern char **environ;
/*===================*/

/* prototypes */
char *readc(void);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int count(char line2[], char c);
char *_cpy(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
/*==================================*/

int flaqs(char dig[]);
int space(char dig[]);
void splitSpace(char *argv[], char line2[]);
void split(char line2[], char *slicedCommand[], char c[]);
int OO(char copy[], char *dpath[], int cont, char *v, char *t, char *n);
int YY(char copy[], char *dpath[], int cont, char *v, char *t, char *n);
int run(char line[], char *dpath[], int cont, char *v, char *t, char *n);
int scolon(char copy[], char *dpath[], int cont, char *v, char *t, char *n);
/*========================================================================*/

void sigintHandler(int sig_num);
char _strtokmao(char *line, char *delim);
int execute(char line2[], int cont, char *v, char *t, char *n);
/*============================================================*/

char *gpath();
char **splitPath(char *path);
char *unePath(char *dpath, char *argv0);
char *checkPath(char **dpath, char *argv0);
/*========================================*/

void _env(char **com);
int salir(char *line, char *line2, int cont, char **com, char *name, int e);
/*========================================================================*/

int _atoi(char *s);
char *_itoa(int n);
int _isdigit(int c);
char *comments(char *line);
char **split_command(char *line);
void *_calloc(unsigned int nmemb, unsigned int size);
void errors(int cont, char *var, char *com, char *name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _fork(char *l, char **com, char *l2, int c, char *n);
int execute_command(char **args, char *p, int cont, char *v, char *t, char *n);
/*===========================================================================*/

#endif /* SHELL_H */
