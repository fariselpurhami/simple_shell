#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
void _env(char **com);

/**
 * _env - LET'S WRITE A FUNCTIONS
 * THAT PRINTS THE ENVS VARIABLES.
 * @com: IT'S AN COMMANDDING LINE.
**/
void _env(char **com)
{
	int w;
	char *s = *environ;

	if (com[1] != NULL)
	{
		return;
	}

	for (w = 0; s; w++)
	{
		write(STDIN_FILENO, s, _strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + w);
	}
}
