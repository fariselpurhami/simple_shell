#include "shell.h"

/* definations */
#define MAX_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int salir(char *line, char *line2, int cont, char **com, char *name, int e);

/**
 * salir - LET'S WRITE FUNCTION THAT WILL EXIT PROGRAM WITH SPECEFIED CODE.
 * @line: IT'S A POINTER TO THE BUFFER STRING THAT CONTAIN THE USER INPUTS.
 * @line2: ITS A POINTER TO THE BUFFER STRING THAT CONTAIN THE USER INPUTS.
 * @cont: IT'S CONT THAT WILL BE EXECUTED IN NUMBER OF ALL COMMANDS SO FAR.
 * @com: IT'S ARRAY OF STRING THAT WILL CONTAINED THE TOKENIZED USER INPUT.
 * @name: IT WILL BE NAME OF THE SHELL PROGRAM,IT IS THE NAME OF THE SHELL.
 * @e: IT'S EXIT CODES THAT WILL BE USED FOR EXITING THE SHELL PROGRAMMING.
 * Return: THE INTEGERS VALUES THAT WILL BE IN THE EXITING SPECEFIED CODES.
*/
int salir(char *line, char *line2, int cont, char **com, char *name, int e)
{
	int i = 0;
	int w = 1;

	if (com[1] == NULL)
	{
		free(line);
		free(line2);
		free(com);
		exit(e);
	}
	for (; com[1][i] != '\0'; i++)
	{
		w = _isdigit(com[1][i]);
		if (w == 0)
		{
			break;
		}
		if (w == 1)
		{
			e = _atoi(com[1]);
		}
		else
		{
			e = 2;
			if (e >= 0 && e + 1 > 0 && e != 2)
			{
				free(line);
				free(com);
				exit(e);
			}
			else
			{
				errors(cont, com[0], com[1], name);
			}
		}
	}

	return (e);
}
