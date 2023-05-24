#include "shell.h"

/* defination */
#define MAX_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
void splitSpace(char *argv[], char line2[]);
void split(char line2[], char *slicedCommand[], char c[]);

/**
 * splitSpace - LET'S WIRTE A FUNCTIONS THAT SPLITS A STRING
 * INTO SEPARATE INTO TOKEN THAT BASED ON A SPACE DELIMITERS.
 * @argv: IT'S (ARGV), POINTERS TO THE ARRAYS OF THE STRINGS.
 * @line2: IT'S (LINE2), OF THE STRING THAT WILL BE ON SPLIT.
 * Return: (VOID)
 */
void splitSpace(char *argv[], char line2[])
{
	int i = 0;
	char *puntero;

	puntero = strtok(line2, " ");
	while (puntero)
	{
		puntero = strtok(NULL, " ");
		argv[i] = puntero;
		i++;
	}
	argv[i] = NULL;
}

/**
 * split - LET'S WRITE A FUNCTION THAT SPLITS A STRING INTO TOKEN ON DELIMETER.
 * @line2: IT'S A STRINGS FUNCTIONS WILL TO BE SPLITS INTO TOKEN ON DELEIMETES.
 * @slicedCommand: IT'S A POINTERS FUNCTION THAT WILL TO THE ARRAYINGS STRINGS.
 * @c: IT'S AN DELIMETERS FUNCTIONS THATS WILL BE USING FOR SPLITS THE STRINGS.
 * Return: (VOID)
 */
void split(char line2[], char *slicedCommand[], char c[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, c);
	while (puntero)
	{
		puntero = strtok(NULL, c);
		slicedCommand[i] = puntero;
		i++;
	}
}
