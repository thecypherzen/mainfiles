#include "gosh.h"

/**
 * sig_handler - handles signal interrupts
 * @sig: the signal received
 * Return: void, but exits with a status.
 */ 
void sig_handler(int sig)
{
	int n;
	
	if (sig == SIGINT)
	{
		n = write(1, "^C\n", 3);
		if (n < 0)
			exit(1);
	}
	exit(128 + sig);
}