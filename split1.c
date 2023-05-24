#include "shell.h"

/* defination */
#define MAX_ARGS 32
#define BUFF_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024
#define T_CUT " \t\r\n\a"

/* prototypes */
char **split_command(char *line);

/**
 * split_command - LET'S WRITE A FUNCTIONS THAT SPLITS A GIVEN A COMMON
 * LINE INTO A SEPARATES ARGUMENTS THAT BE USING A SPECIFIED DELIMITERS.
 * @line: IT'S A PARAM LINE FROM A COMMONAD LINE THAT WILL BE TO SPLITS.
 * Return: IT'S ARRAY OF STRING THAT REPRESENTING THE SEPARATE ARGUMENT
 * AND LAST ELEMENT OF THE ARRAY WILL BE NULL, IF NO ARGUMENT WILL NULL.
**/
char **split_command(char *line)
{
	int w = 0;
	int buffer = BUFF_SIZE;
	char **tokens = malloc(buffer);
	char *token;

	if (!tokens)
	{
		write(STDERR_FILENO, "ish: allocation error\n",
		      strlen("ish: allocation error\n"));

		exit(EXIT_FAILURE);
	}

	token = strtok(line, T_CUT);
	while (token != NULL)
	{
		w++;
		tokens[w] = token;
	}

	if (w >= buffer)
	{
		tokens = realloc(tokens, buffer);
	}

	buffer += BUFF_SIZE;
	if (!tokens)
	{
		write(STDERR_FILENO, "ish: allocation error\n",
		      strlen("ish: allocation error\n"));

		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, T_CUT);
	tokens[w] = NULL;
	return (tokens);
}
