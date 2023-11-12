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
	void *temp;

	/* Freeing alias list */
	while (alias_h)
	{
		temp = alias_h->next;
		free(alias_h->name), free(alias_h->val);
		free(alias_h);
		alias_h = (Alias_t *)temp;
	}

	/* Freeing env list */
	while (env_h)
	{
		temp = env_h->next;
		free(env_h->name), free(env_h->val);
		free(env_h);
		env_h = (Env_t *)temp;
	}
}