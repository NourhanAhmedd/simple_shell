#include "s_shell.h"

/* free_b: */

/**
 * free_b - Write a function that frees The pointer.
 *
 * @s: The pointer.
 *
 * Return: It will return 1 or 0.
*/

int free_b(void **s)
{
	/* If condition: */
	if (s && *s)
	{
		free(*s);
		*s = NULL;
		return (1);
	}

	return (0);
}
