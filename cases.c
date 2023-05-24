#include "shell.h"

/* definations */
#define MAX_ARGS 32
#define BUFF_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int run(char line2[], char *dpath[], int cont, char *v, char *t, char *n);
int scolon(char copy[], char *dpath[], int cont, char *v, char *t, char *n);
int OO(char copy[], char *dpath[], int cont, char *v, char *t, char *n);
int YY(char copy[], char *dpath[], int cont, char *v, char *t, char *n);

/**
 * run - LET'S WRITES A FUNCTIONS THATS WILL BEEN EXECUTED THE COMMANDS.
 * @line2: IT'S A PARAM LINE FROM A COMMONAD LINE THAT WILL BE TO SPLIT.
 * @dpath: IT'SA POINTES OF THE STRINGS IN THE DIRECTOIRES OF THE PATHS.
 * @cont: IT'S EXECUTED THE NUMBER OF THE COMMAND THAT WILL BEEN SO FAR.
 * @v: IT'S (V) FUNCTIONS THAT WILL BE THE NAME OF THE EXECUTED PROGRAM.
 * @t: IT'S (T) CURRENTS TIME OF THE HH:MM:SS THATS WILL BE FORMMATTING.
 * @n: IT'S (N) NUMBERS OF COMMANDS THATS WILL BE STORED IN THE HISTORY.
 * Return: 0 ALWAYS ON SUCCESS
 */
int run(char line2[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int x = 0;
	int ex = 0;
	char *dpathcmd;
	char **argv = NULL;

	x = (count(line2, ' ')) + 2;
	argv = _calloc(x, sizeof(char *));
	splitSpace(argv, line2);
	dpathcmd = checkPath(dpath, argv[0]);

	if (dpathcmd == NULL)
	{
		free(dpathcmd);
		errors(cont, v, t, n);
	}
	else
	{
		ex = execve(dpathcmd, argv, environ);
	}

	free(argv);
	return (ex);
}

/**
 * scolon - LET'S WRITE A FUNCTIONS THAT EXECUTED BETWEEN TWO COMMANDS.
 * @copy: IT'S A POINTERS OF THE STRINGS THAT WILL BE COPY THE COMMAND.
 * @dpath: IT'S A POINTER OF THE STRING IN THE DIRECTOIRES OF THE PATH.
 * @cont: ITS EXECUTED THE NUMBER OF THE COMMAND THAT WILL BEEN SO FAR.
 * @v: IT'S (V) FUNCTION THAT WILL BE THE NAME OF THE EXECUTED PROGRAM.
 * @t: IT'S (T) CURRENT TIME OF THE HH:MM:SS THATS WILL BE FORMMATTING.
 * @n: IT'S (N) NUMBERS OF COMMANDS THAT WILL BE STORED IN THE HISTORY.
 * Return: 0 ALWAYS ON SUCCESS.
 */
int scolon(char copy[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int i = 0;
	int a = 0;
	int b = 0;
	int ex = 0;
	int status = 0;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, ";"), a = _strlen(ppp[0]), b = _strlen(ppp[1]);
	ex1 = _calloc(a, sizeof(char *)), ex2 = _calloc(b, sizeof(char *));
	_strcpy(ex1, ppp[0]), _strcpy(ex2, ppp[1]);
	i = (count(ex1, ' ')) + 2, argv1 = _calloc(i, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);

	if (dpathcmd == NULL)
	{
		errors(cont, v, t, n);
	}
	else
	{
		pid2 = fork();
	}

	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{errors(cont, v, t, n);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		if (pid2 < 0)
		{
			errors(cont, v, t, n);
			return (0);
		}
		else
		{
			do {wpid = waitpid(pid2, &status, WUNTRACED);

		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

		i = (count(ex2, ' ')) + 2;
		argv2 = _calloc(i, sizeof(char *));
		splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);

		if (dpathcmd == NULL)
		{
			errors(cont, v, t, n);
		}
		else
		{
			ex = execve(dpathcmd, argv2, environ);
		}

		return (ex);
	}
}

/**
 * OO - LET'S WRITES A FUNCTUON THAT WILL EXECUTED BETWEEN TWO COMMAND.
 * @copy: IT'S A POINTERS OF THE STRINGS THAT WILL BE COPY THE COMMAND.
 * @dpath: IT'S A POINTER OF THE STRING IN THE DIRECTOIRES OF THE PATH.
 * @cont: ITS EXECUTED THE NUMBER OF THE COMMAND THAT WILL BEEN SO FAR.
 * @v: IT'S (V) FUNCTION THAT WILL BE THE NAME OF THE EXECUTED PROGRAM.
 * @t: IT'S (T) CURRENT TIME OF THE HH:MM:SS THATS WILL BE FORMMATTING.
 * @n: IT'S (N) NUMBERS OF COMMANDS THAT WILL BE STORED IN THE HISTORY.
 * Return: 0 ALWAYS ON SUCCESS.
 */
int OO(char copy[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int x = 0;
	int a = 0;
	int b = 0;
	int ex = 0;
	int status = 0;

	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, "|");
	a = _strlen(ppp[0]), b = _strlen(ppp[1]);
	ex1 = _calloc(a, sizeof(char)), ex2 = _calloc(b, sizeof(char));
	_strcpy(ex1, ppp[0]), _strcpy(ex2, ppp[1]);
	x = (count(ex1, ' ')) + 2, argv1 = _calloc(x, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);

	if (dpathcmd == NULL)
	{
		errors(cont, v, t, n);
	}
	else
	{
		pid2 = fork();
	}

	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{
			errors(cont, v, t, n);
			return (0);
		}

		exit(EXIT_FAILURE);
	}
	else
	{
		if (pid2 < 0)
		{
			errors(cont, v, t, n);
			return (0);
		}
		else
		{
			do {wpid = waitpid(pid2, &status, WUNTRACED);

		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

		x = (count(ex2, ' ')) + 2, argv2 = _calloc(x, sizeof(char *));
		splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);

		if (dpathcmd == NULL)
		{
			errors(cont, v, t, n);
		}
		else
		{
			ex = execve(dpathcmd, argv2, environ);
		}
	}

	return (ex);
}


/**
 * YY - LET'S WRITES A FUNCTUON THAT WILL EXECUTED BETWEEN TWO COMMAND.
 * @copy: IT'S A POINTERS OF THE STRINGS THAT WILL BE COPY THE COMMAND.
 * @dpath: IT'S A POINTER OF THE STRING IN THE DIRECTOIRES OF THE PATH.
 * @cont: ITS EXECUTED THE NUMBER OF THE COMMAND THAT WILL BEEN SO FAR.
 * @v: IT'S (V) FUNCTION THAT WILL BE THE NAME OF THE EXECUTED PROGRAM.
 * @t: IT'S (T) CURRENT TIME OF THE HH:MM:SS THATS WILL BE FORMMATTING.
 * @n: IT'S (N) NUMBERS OF COMMANDS THAT WILL BE STORED IN THE HISTORY.
 * Return: 0 ALWAYS ON SUCCESS.
 */
int YY(char copy[], char *dpath[], int cont, char *v, char *t, char *n)
{
	int x = 0;
	int a = 0;
	int b = 0;
	int ex = 0;
	int status = 0;

	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, "|");
	a = _strlen(ppp[0]), b = _strlen(ppp[1]);
	ex1 = _calloc(a, sizeof(char)), ex2 = _calloc(b, sizeof(char));
	_strcpy(ex1, ppp[0]), _strcpy(ex2, ppp[1]);
	x = (count(ex1, ' ')) + 2, argv1 = _calloc(x, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);

	if (dpathcmd == NULL)
	{
		errors(cont, v, t, n);
	}
	else
	{
		pid2 = fork();
	}

	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{
			errors(cont, v, t, n);
			return (0);
		}

		exit(EXIT_FAILURE);
	}
	else
	{
		if (pid2 < 0)
		{
			errors(cont, v, t, n);
			return (0);
		}
		else
		{
			do {wpid = waitpid(pid2, &status, WUNTRACED);

		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

		x = (count(ex2, ' ')) + 2, argv2 = _calloc(x, sizeof(char *));
		splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);

		if (dpathcmd == NULL)
		{
			errors(cont, v, t, n);
		}
		else
		{
			ex = execve(dpathcmd, argv2, environ);
		}
	}

	return (ex);
}
