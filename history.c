#include "shell.h"

/* defination */
#define MAX_ARGS 32
#define BUFFER_SIZE 1024
#define MAX_ARG_LENGTH 64
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_itoa(int n);

/**
 * _strchr - LET'S WRITE A FUNCTION THAT LOCATE CHARACTERS IN A STRING.
 * @s: IT'S (S) A POINTERS TO THE STRING THAT GOING TO BE SEARCHED FOR.
 * @c: IT'S (C) A POINTERS CHARACTERSTICS TO BE LOCATED IN THE STRINGS.
 * Return: A POINTERS TO THE FIRST OCCURENECE OF THE CHARACTERS C IN S.
 */
char *_strchr(char *s, char c)
{
	unsigned int w = 0;

	while (*(s + w++))
	{
		if (s[w] == c)
		{
			return (&s[w]);
		}

		if (*(s + w) == c)
		{
			return (&s[w]);
		}
	}

	return (0);
}

/**
 * _strcmp -- LET'S WRITE A FUNCTIONS STRINGS
 * THATS WILL GOING BE COMBARING BETWEEN THEM.
 * @s1: IT'S A COMPARING FOR THE FIRST STRING.
 * @s2: ITS A COMPARING FOR THE SECOND STRING.
 * Return: 0 IF STRING ARE =,NEGATIVE IF < S2.
 */
int _strcmp(char *s1, char *s2)
{
	char a1;
	char a2;

	do {
		a1 = *s1++;
		a2 = *s2++;

		if (a1 == '\0')
			return (a1 - a2);
	} while (a1 == a2);

	return (a1 - a2);
}

/**
 * _strcpy - LET'S WRITE A FUNCTION THAT COPY
 * THE STRING POINTED TO BY SRC, INCLUDE NULL.
 * @dest: IT'S A POINTERS TO THE DESTENATIONS
 * ARRAY WHERE THE CONTENTS IS TO BEEN COPIED.
 * @src: ITS A POINTERS OF SOURCE COPIED DATA.
 * Return: IT WILL BE RETURN TO POINTERS DEST.
 */
char *_strcpy(char *dest, char *src)
{
	int w;

	for (w = 0; *(src + w) != '\0'; w++)
	{
		dest[w] = src[w];
	}

	dest[w] = '\0';

	return (dest);
}

/**
 * _strlen - LET'S WRITE A FUNCTION RETURNLENGTH OF STRINGS.
 * @s: IT'S (S) A POINTERS TO THE STRING THAT BEEN MEASURED.
 * Return: IT WILL BE RETURNED TO THE LENGTH OF THE STRINGS.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _itoa - LET'S WRITE A FUNCTION THAT CONVERT AN INTEGER TO STRINGS.
 * @n: IT'S A POINTER TO THE INTEGER THAT IS GOING TO BEEN CONVERTED.
 * Return: THE POINTERS TO THE RESULTING IN NULL-TERMINIATED STRINGS.
 */
char *_itoa(int n)
{
	int num;
	int last = n % 10;
	int digit;
	int exp = 1;
	int w = 1;
	int i = 0;
	char *buffer = NULL;

	n = n / 10;
	num = n;
	buffer = malloc(12 * sizeof(int));
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}

		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			buffer[i] = (digit + '0');
			i++;
			num = num - (digit * exp);
			exp = exp / 10;
			w++;
		}
	}

	buffer[i] = (last + '0');
	i++;
	buffer[i] = '\0';

	return (buffer);
}
