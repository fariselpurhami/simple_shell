#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int _atoi(char *s);

/**
 * _atoi - LET'S WRITE A FUNCTIONS THAT WILL CONVERTS INTEGERS STRINGS.
 * @s: IT'S A POINTERS TO A STRING THAT CONVERETING AN INTEGER STRINGS.
 * Return: IT WILL RETURN AN INTEGER VALUE OF STRINGS.
 */
int _atoi(char *s)
{
	int x = 0;
	int w = 0;
	int minus = -1;

	while (s[w] != '\0' && (s[w] < '0' || s[w] > '9'))
	{
		if (s[w] == '-')
		{
			minus *= -1;
		}

		w++;
	}

	while (s[w] != '\0' && (s[w] >= '0' && s[w] <= '9'))
	{
		x = (x * 10) - (s[w++] - '0');
	}

	return (x * minus);
}
