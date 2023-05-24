#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
int flaqs(char line2[]);
int space(char line2[]);

/**
 * flaqs - LET'S WRITE A FUNCTION SEARCHING IN CMD DELIMITERS.
 * @line2: IT'S (LINE2), OF THE STRING THAT WILL BE ON SPLITS.
 * Return: 1 ON SUCCESS, 0 OTHERWISE.
 */
int flaqs(char line2[])
{
	if (_strchr(line2, ';') != NULL)
	{
		return (1);
	}
	else
	{
		if (_strchr(line2, '#') != NULL)
		{
			return (2);
		}
		else
		{
			if (_strchr(line2, '|') != NULL)
			{
				return (3);
			}
			else
			{
				if (_strchr(line2, '&') != NULL)
				{
					return (4);
				}
				else
				{
					if (_strchr(line2, '$') != NULL)
					{
						return (5);
					}
				}
			}
		}
	}

	return (0);
}

/**
 * space - LET'S WRITE A FUNCTION SEARCH THE SPACE IN THE CMD.
 * @line2: IT'S (LINE2), OF THE STRING THAT WILL BE ON SPLITS.
 * Return: 1 ON SUCCESS, 0 OTHERWISE.
 */
int space(char line2[])
{
	if (_strchr(line2, ' ') != NULL)
	{
		return (1);
	}

	return (0);
}
