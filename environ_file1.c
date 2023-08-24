#include "s_shell.h"

/* the_e: */

/**
 * the_e - Write a function that prints the env.
 *
 * @info: The para struct.
 *
 * Return: It will return (0)
*/

int the_e(p_t *info)
{
	p_l_s(info->environ_linked_list);
	return (0);
}

/* g_e: */

/**
 * g_e - gets the value of an environ variable
 *
 * @in: The para struct.
 * @n: The env name.
 *
 * Return: It will return (NULL).
*/

char *g_e(p_t *in, const char *n)
{
	char *s;
	l_t *n_node = in->environ_linked_list;

	/* While loop: */
	while (n_node)
	{
		s = s_with(n_node->str, n);
		/* If condition: */
		if (s && *s)
		{
			return (s);
		}
		n_node = n_node->next;
	}
	return (NULL);
}

/* the_se: */

/**
 * the_se - Write a function that initializes a var.
 *
 * @in: The para struct.
 *
 * Return: It will return 0 or 1.
*/

int the_se(p_t *in)
{
	/* If condition: */
	if (in->arguement_c != 3)
	{
		e_p("Incorrect number of arguements\n");
		return (1);
	}
	/* If condition: */
	if (se(in, in->arguement_value[1], in->arguement_value[2]))
	{
		return (0);
	}
	return (1);
}

/* the_unse: */

/**
 * the_unse - Write a function that removes the var.
 *
 * @in: The para struct.
 *
 *  Return: It will return 0 or 1.
*/

int the_unse(p_t *in)
{
	int index;

	/* If condition: */
	if (in->arguement_c == 1)
	{
		e_p("Too few arguements.\n");
		return (1);
	}
	/* For loop: */
	for (index = 1; index <= in->arguement_c; index++)
	{
		unse(in, in->arguement_value[index]);
	}
	return (0);
}

/* p_elist: */

/**
 * p_elist - populates env linked list
 *
 * @in: The para struct.
 *
 * Return: It will return (0).
*/

int p_elist(p_t *in)
{
	size_t index;
	list_t *n = NULL;

	/* For loop: */
	for (index = 0; environ_copy[index]; index++)
	{
		new_node_e(&n, environ_copy[index], 0);
	}
	in->environ_linked_list = n;
	return (0);
}
