#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
void *_calloc(unsigned int nmemb, unsigned int size);

/**
 * _calloc - LET'S WRITE A FUNCTION THAT ALLOCATED ARRAYS FOR MEMORY.
 * @nmemb: IT'S A POINTERS OF STRINGS THAT HAS A NUMBERS OF ELEMENTS.
 * @size: IT'S A SIZE OF BYTES OF THE ELEMENTS THAT WILL BE IN THE S.
 * Return: A POINTER TO MEMORIES THAT ALLOCATED IS SET TO ZERO IF IT.
 * ZERO NMEB - SIZE IS ZERO RETURN NULL IF MALLOC FAIL, _CALLOC NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	int x;
	int range;
	char *ch;
	void *e = NULL;

	range = nmemb * size;
	if (range == 0)
	{
		return (NULL);
	}

	e = malloc(range);
	if (e != NULL)
	{
		ch = (char *)e;
	}

	for (x = 0; x < range; x++)
	{
		ch[x] = 0;
		return (e);
	}

	return (e);
}
