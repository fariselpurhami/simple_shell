#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int _fork(char *l, char **com, char *l2, int c, char *n);

/**
 * _fork - LET'S WRITE A FUNCTIONS
 * THAT WILL IN PROCESS THAT FORKS.
 * @l2: IT'S A SECOND COMMAND LINE.
 * @l: IT'S A FIRST COMMAND FREE L.
 * @c: -IT'S A NUMBERS OF THE CMDS.
 * @com: ---IT'S AN COMMANDS LINES
 * @n: IT'S NAME OF THE EXEC FILES.
 * Return: IT RETURNS THE INTEGERS.
**/
int _fork(char *l, char **com, char *l2, int c, char *n)
{
	pid_t pid = 0, wpid;

	int status = 0;

	pid = fork();

	(void)wpid;

	if (pid == 0)
	{
		if (execute(l2, c, com[0], com[1], n) == -1)
		{
			errors(c, com[0], com[1], n);
			free(l), free(l2), free(com);
			return (0);
		}

		exit(EXIT_FAILURE);
	}
	else
	{
		if (pid < 0)
		{
			errors(c, com[0], com[1], n);
			return (0);
		}
		else
		{
			do {
				wpid = waitpid(pid, &status, WUNTRACED);

			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}

		return (1);
	}
}
