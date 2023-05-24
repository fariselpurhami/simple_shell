#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
char *comments(char *line);

/**
 * comments - LET'S WRITE A FUNCTION THAT REMOVING THE COMMAND COMMENTS.
 * @line: IT'S A PARAM LINE FROM A COMMONAD LINE THAT WILL BE TO SPLITS.
 * Return: IT WILL RETURN THE CMD LINE.
**/
char *comments(char *line)
{
	int w = 0;
	int j = 0;
	char *compare = " \t\r\a";
	char aux;

	while (compare[j] != '\0')
	{
		if (line[0] == compare[j])
		{
			for (w = 0; line[w] != '\0'; w++)
			{
				aux = line[w + 1];
				line[w] = aux;
			}

		}

		j++;
	}

	for (w = 0; line[w] != '\0'; w++)
	{
		if (line[w] == '#')
		{
			line[w] = '\0';
			break;
		}
	}

	return (line);
}
