#include "gosh.h"

/**
 * throw_syntax_err - throws a syntax error if one exists
 * in command string entered.
 * @num: the number of arguments passed. Used to create the
 *       response string.
 * Return: 1 if error, 2 otherwise.
 */
int throw_syntax_err(int num, Info shell, ...)
{
	va_list chars;
	char *err_token;
	int i;

	err_token = (char *)malloc(num + 1);
	if (!err_token)
		return (NORMAL_FAIL);
	
	va_start(chars, shell);
	for (i = 0; i < num; i++)
		err_token[i] = va_arg(chars, int);
	err_token[i] = '\0';
	va_end(chars);
	
	fprintf(stderr, "%s: %d: %s: \"%s\" unexpected\n", 
		shell.name, *(shell.count), "Syntax error", err_token);
	
	free(err_token);
	return (SYNTAX_ERR);
}