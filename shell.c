#include "shell.h"

/* definations */
#define MAX_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int execute(char line2[], int cont, char *v, char *t, char *n);
int count(char line2[], char c);

/**
 * execute - LET'S WRITE A FUNCTION THAT EXECUTES A COMMAND LINE INPUT.
 * @line2: IT'S EXECUTED COMMANDS LINES THAT IN THE COMMAND LINE INPUT.
 * @cont: IT'S EXECUTED THE NUMBERS OF THE COMMAND THAT WILL BE SO FAR.
 * @v: IT'S (V) FUNCTIONS THAT WILL BE THE NAME OF THE EXECUTE PROGRAM.
 * @t: IT'S (T) CURRENTS TIME OF THE HH:MM:SS THAT WILL BE FORMMATTING.
 * @n: IT'S (N) NUMBERS OF COMMANDS THAT WILL BE STORED IN THE HISTORY.
 * Return: THE EXIT STATUS OF LAST EXECUTED COMMANDS IN THIS FUNCTIONS.
 */
int execute(char line2[], int cont, char *v, char *t, char *n)
{
	char *path;
	char **dpath;
	char *copy = NULL;
	int flaqsc = 0, ex = 0;
	int lengthline2 = _strlen(line2);

	copy = _calloc(lengthline2 + 1, sizeof(char));
	path = gpath();
	dpath = splitPath(path);
	flaqsc = flaqs(line2);
	_strcpy(copy, line2);

	if (flaqsc == 0)
	{
		ex = run(line2, dpath, cont, v, t, n);
	}
	else
	{
		if (flaqsc == 1)
		{
			ex = scolon(copy, dpath, cont, v, t, n);
		}
		else
		{
			if (flaqsc == 3)
			{
				ex = OO(copy, dpath, cont, v, t, n);
			}
			else
			{
				if (flaqsc == 4)
				{
					ex = YY(copy, dpath, cont, v, t, n);
				}
			}
		}
	}

	free(copy);
	free(path);
	free(dpath);
	return (ex);
}

/**
 * count - LET'S WRITE FUNCTION THAT COUNT THE NUMBER OF THE OCCURENCES STRING.
 * @line2: IT'S A LINE STRINGS THAT WILL BE SEARCHING FOR NUMBERS OOCCURENECES.
 * @c: IT'S ( C) A CHARACTER OF THE STRING THAT WILL BE SEARCHED OF THE NUMBER.
 * Return: THE VALUE OF THE NUMBERS OF THE OCCURRENCESES IN A CHARACTER STRING.
 */
int count(char line2[], char c)
{
	int j = 0, k = 0;

	while (line2[j])
	{
		if (line2[j] == c)
		{
			k++;
		}

		j++;
	}

	return (k);
}
