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
int main(int ac, char **av);

#endif /* SHELL_H */
