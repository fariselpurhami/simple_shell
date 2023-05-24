#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
void errors(int cont, char *var, char *type, char *name);

/**
 * errors - LET'S WRITE A FUNCTIONS
 * THAT WILL PRINTS A TYPE OF ERROR.
 * @cont: IT'S EXECUTED THE NUMBERS.
 * OF THE CMD THAT WILL BEEN SO FAR.
 * @var: IT'S VARIABLES OF THE CMDS.
 * @type: IT'S AN ERROR OF THE CMDS.
 * @name: IT'S THE NAME OF THE EXES.
**/
void errors(int cont, char *var, char *type, char *name)
{
	char *con, *a = "not found", *num;
	char *aux = ": ";
	char *st = NULL;
	int w;

	st = _calloc(200, sizeof(char));
	if (!_strcmp("exit", var))
	{
		a = "Illegal number: ";
		num = type;
	}
	else
	{
		num = "";
		con = _itoa(cont);
		_strcat(st, name);
		_strcat(st, aux);
		_strcat(st, con);
		_strcat(st, aux);
		_strcat(st, var);
		_strcat(st, aux);
		_strcat(st, a);
		_strcat(st, num);
		_strcat(st, "\n");
	}

	for (w = 0; st[w] != '\0'; w++)
	{
		;
		free(con);
		write(STDERR_FILENO, st, w);
		free(st);
	}
}
