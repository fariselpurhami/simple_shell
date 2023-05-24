#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * _realloc - LET'S WRITE A FUNCTION THAT BLOCK A MEMORY REALLOCATED.
 * @ptr: IT'S A POINTER OF STRINGS THAT ALLOCATED POINTER PREVIOUSLY.
 * @old_size: IT'S A POINTER OF THE STRING THAT HAVE THE SIZE OF PTR.
 * @new_size: IT'S A POINTERS OF THE STRINGS THAT HAVE THE NEW SIZES.
 * Return: IT WILL RETURN THE NULL OR PTR.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
	}

	if (new_size == old_size)
	{
		return (ptr);
	}

	free(ptr);
	ptr = malloc(new_size);
	return (ptr);
}
