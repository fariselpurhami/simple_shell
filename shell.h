#ifndef shell_l
#define shell_l

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>

/* decleration */
extern char **environ;

/* prototypes */
char **split_command(char *line);
void splitSpace(char *argv[], char line2[]);
void split(char line2[], char *slicedCommand[], char c[]);
int execute(char line2[], int cont, char *v, char *t, char *n);
int count(char line2[], char c);
int salir(char *line, char *line2, int cont, char **com, char *name, int e);
char *readc(void);
char *_cpy(char *dest, char *src);
char *gpath();
char **splitPath(char *path);
char *checkPath(char **dpath, char *argv0);
char *unePath(char *dpath, char *argv0);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_itoa(int n);

#endif /* SHELL_H */
