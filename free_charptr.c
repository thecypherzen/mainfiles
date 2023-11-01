#include "gosh.h"
/**
 * free_charptr - frees a ptr to char if it is not NULL
 * @ptr: the character pointer
 * Return: Always void
 */
void free_charptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}