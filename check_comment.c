#include "gosh.h"
/**
 * comment_checkr - replaces the trailing newline from fd_getline
 * and truncates comments from cmd if there is.
 * @cmd: the command
 * Return: void
 */
void check_comment(char *cmd)
{
	if (cmd)
	{
		if (*cmd == '#')
			*cmd = '\0';
	}
}
