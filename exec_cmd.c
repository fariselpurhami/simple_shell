#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int execute_command(char **args, char *p, int cont, char *v, char *t, char *n);

/**
 * execute_command - LET'S WRITE A FUNCTIONS THAT WILL EXEC THE CMD.
 * @cont: IT EXECUTED THE NUMBER OF THE COMMAND THAT WILL BE SO FAR.
 * @v: IT (V) FUNCTION THAT WILL BE THE NAME OF THE EXECUTE PROGRAM.
 * @t: IT (T) CURRENT TIME OF THE HH:MM:SS THAT WILL BE FORMMATTING.
 * @n: IT'S (N) NUMBER OF COMMANDS THATS WILL STORED IN THE HISTORY.
 * @args: IT'S A POINTERS OF THE STRINGS THAT WILL ARGUMENT THE CMD.
 * @p:  IT'S (P) LINES OF COMMANDS THAT WILL STORED IN THE FUNCTION.
 * Return: IT WILL RETUNED THE INTEGERS.
**/
int execute_command(char **args, char *p, int cont, char *v, char *t, char *n)
{
	pid_t pid, wpid;
	int status;
	char us[128] = "/bin", *aux = "/b";
	(void)wpid;

	if (p[0] == aux[0] && p[1] == aux[1])
	{
		_strcpy(us, p);
	}
	else
	{
		_strcat(us, "/");
		_strcat(us, p);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(us, args, NULL) == -1)
		{
			errors(cont, v, t, n);
			return (0);
		}

		exit(EXIT_FAILURE);
	}
	else
	{
		if (pid < 0)
		{
			errors(cont, v, t, n);
			return (0);
		}
	}

	do {
		wpid = waitpid(pid, &status, WUNTRACED);

	} while (!WIFEXITED(status) && !WIFSIGNALED(status));


	return (1);
}
