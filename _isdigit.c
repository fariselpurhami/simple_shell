#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int _isdigit(int c);

/**
 * _isdigit - LET'S WRITE A FUNCTIONS THAT PRINTS A DIGIT IF IT IS ONE.
 * @c: IT'S A POINTER OF STRING THAT THE CHARACTER IS SAY IT'S A DIGIT.
 * Return: 0 ALWAYS IF COMPILATION ON SUCCESS.
 */
int _isdigit(int c)
{
	if (c > 47 && c < 58)
	{
		return (1);
	}

	return (0);
}
