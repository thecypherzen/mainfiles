#include "gosh.h"

/**
 * free_structs - Frees the shell alias and env linked lists
 * on event of exit condition met(EOF)
 * @alias_h: ptr to head of alias list
 * @env_h: ptr to head of env list
 * Return: Void
 */
void free_structs(Alias_t *alias_h, Env_t *env_h)
{
	void *temp, *prev;
	
	while (alias_h)
	{
		prev = alias_h;
		temp = alias_h->next;
		free(((Alias_t *)prev)->name);
		free(((Alias_t *)prev)->val);
		alias_h = (Alias_t *)temp;
	}
	while (env_h)
	{
		prev = env_h;
		temp = env_h->next;
		free(((Env_t *)prev)->name);
		free(((Env_t *)prev)->val);
		env_h = (Env_t *)temp;
	}
}