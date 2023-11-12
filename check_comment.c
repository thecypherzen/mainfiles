#include "gosh.h"
/**
 * comment_checkr - replaces the trailing newline from fd_getline
 * and truncates comments from cmd if there is.
 * @cmd: the command
 * Return: void
 */
void check_comment(char *cmd)
{
	size_t len;
	char *comment;

	if (cmd)
	{
		len = strlen(cmd);
		cmd[len - 1] = '\0';
		comment = strchr(cmd, '#');
		if (comment)
			*comment = '\0';
	}
	else
		perror("NULL POINTER");
}
