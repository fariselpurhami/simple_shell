#include "shell.h"

/* definations */
#define MAX_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
char *gpath();
char **splitPath(char *path);
char *checkPath(char **dpath, char *argv0);
char *unePath(char *dpath, char *argv0);

/**
 * gpath - LET'S WRITE A FUNCTION RETRIEVE VALUE OF PATH ENVIRONMENT VARIABLE.
 * Return: POINTERS TO NULL-TERMINATED THAT CONTAINS VALUES OF PATH VARIABLES.
 */
char *gpath()
{
	char *s, **e = environ;
	unsigned int w = 0, j = 5, k = 0;

	while (e[w])
	{
		if (e[w][0] == 80 && e[w][3] == 72 && e[w][4] == 61)
		{
			s = _calloc(PATH_MAX, sizeof(char));
			if (s == NULL)
			{
				write(1, "Error: failed malloc gpath\n", 27);
				return (NULL);
			}

			while (e[w][j])
			{
				s[k] = e[w][j];
				k++;
				j++;
			}

			s[k] = '\0';
			return (s);
		}

		w++;
	}

	return (0);
}

/**
 * splitPath - LET'S WRITE FUNCTION SPLIT THE SPECIFIED PATH STRING INTO ARRAY.
 * @path: IT'S A NULL-TERMINATED STRING THAT CONTAINING THE PATH TO BE SPLITED.
 * Return: A POINTERS TO DYNAMICALLY ALLOCATED ARRAY OF NULL-TERMINATED STRING
 * EACH STRINGS CORRESPONDING TO A DIRECTORIES NAMES IN THE SPECEFIED PATHS IN,
 * LAST ELEMENT OF ARRAYS IS NULL, AND IF AN ERRORS OCCURS, NULL IS RETURNED.
 */
char **splitPath(char *path)
{
	int w = 0;
	char **d;
	char *carp;

	d = _calloc(PATH_MAX, sizeof(char));
	if (d == NULL)
	{
		write(1, "Error: failed malloc splitPath\n", 31);
		return (NULL);
	}

	carp = strtok(path, ":");
	while (carp)
	{
		d[w] = carp;
		carp = strtok(NULL, ":");
		w++;
	}

	d[w] = NULL;
	return (d);
}

/**
 * checkPath - LET'S WRITE A FUNCTION THAT SEARCH FOR DIRECTORIES IN THE PATH.
 * @dpath: IT'S A NULL-TERMINATED ARRAYS THATS SEARCH FOR DIRECTOIRES IN NULL.
 * @argv0: IT'S A NULL-TERMINATED STRINGS THAT CONTAINING NAMES OF EXEC FILES.
 * Return: A POINTERS TO NULL-TERMINATED  THAT CONTAINING PATH TO EXECUTABLES.
 */
char *checkPath(char **dpath, char *argv0)
{
	struct stat mao;
	char *completline;
	int w = 0;

	while (dpath[w])
	{
		completline = unePath(dpath[w], argv0);
	}

	if (stat(completline, &mao) == 0)
	{
		return (completline);
		w++;
	}

	return (NULL);
}

/**
 * unePath - LET'S WRITES FUNNTIONS THAT JOIN SPECIFIED DIRECTORY PATH STRING.
 * @dpath: IT'S A NULL-TERMINATED STRING THAT CONTANING THE DIRECTORY IN PATH.
 * @argv0: IT'S A NULL-TERMINATED STRING THAT CONTAINING THE EXECUATBLES FILE.
 * Return: A POINTER TO A NULL-TERMINATED THAT CONTAINING THE PATH EXECUTABLE.
 */
char *unePath(char *dpath, char *argv0)
{
	char *path_cmd;
	int dpathlen, argv0len, len;
	int w = 0;
	int j = 0;

	dpathlen = _strlen(dpath);
	argv0len = _strlen(argv0);
	len = dpathlen + argv0len;
	path_cmd = _calloc(len + 2, sizeof(char));
	if (path_cmd == NULL)
	{
		write(1, "Error: malloc catpath\n", 22);
		return (NULL);
	}

	while (dpath[w])
	{
		path_cmd[w] = dpath[w];
		w++;
	}

	path_cmd[w] = '/';
	w++;

	while (argv0[j])
	{
		path_cmd[w] = argv0[j];
		j++;
		w++;
	}

	path_cmd[w] = '\0';
	return (path_cmd);
}
