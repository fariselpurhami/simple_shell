#include "shell.h"

/* definations */
#define MAX_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
char *readc(void);
char *_cpy(char *dest, char *src);

/**
 * readc - LET'S WRITE A FUNCTIONS THAT READS A CHARACTERS FROM STANDARD INPUT.
 * Return: POINTER THE NULL-TERMINATED STRING THAT CONTAIN THE CHARACTER INPUT.
 */
char *readc(void)
{
	size_t bufsize = 0;
	ssize_t w = 0;
	char *line = NULL;

	w = getline(&line, &bufsize, stdin);
	if (w == -1)
	{
		exit(0);
	}

	return (line);
}


/**
 * _cpy - LET'S WRITE FUNCTION THAT COPIE THE STRING BY SRC TO BUFFER BY DEST.
 * @dest: IT'S POINTERS TO THE BUFFER STRING WHERE THE STRING IS TO BE COPIED.
 * @src: IT'S POINTERS WILL TO THE NULL-TERMINATED IN THE STRING TO BE COPIED.
 * Return: A POINTERS TO THE DESTINATION BUFFER.
 */
char *_cpy(char *dest, char *src)
{
	int w;

	for (w = 0; *(src + w) != '\n'; w++)
	{
		dest[w] = src[w];
	}

	dest[w] = '\0';
	return (dest);
}
