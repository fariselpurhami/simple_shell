#include "shell.h"

/* definations */
#define MAX_COMMAND_LENGTH 512
#define MAX_FILENAME_LENGTH 256
#define MAX_TEXT_CONTENT_LENGTH 1024

/* prototypes */
void sigintHandler(int sig_num);

/**
 * sigintHandler -  LET'S WRITE A FUNCTIONS THAT HANDLING THE SIGNITS.
 * @sig_num: ITS HANDLER TO SIGNIT THAT WILL CATHING IT FOR NEXT TIME.
 * Return: 0 ALWAYS ON SUCCESS.
 */
void sigintHandler(int sig_num)
{
	(void)sig_num;

	signal(SIGINT, sigintHandler);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}
