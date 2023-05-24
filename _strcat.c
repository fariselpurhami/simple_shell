#include "shell.h"

/* defination */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
char *_strcat(char *dest, char *src);

/**
 * *_strcat - LET'S WRITE A FUNCTIONS THAT WILL CONCAT BETWEEN TWO STRINGS.
 * @dest: IT'S POINTERS OF THE STRING THE WILL BEEN RECEIVES THE FUNCTIONS.
 * @src: ITS A POINTERS OF TWO STRINGS.
 * Return: IT WILL RESTURN (DEST).
 **/
char *_strcat(char *dest, char *src)
{
	int w = 0;
	int j = 0;

	while (dest[w])
	{
		w++;
	}
	while (src[j])
	{
		dest[w] = src[j];
		w++;
		j++;
	}

	dest[w] = 0;
	return (dest);
}
