#include "s_shell.h"

/* g_environ: */

/**
 * g_environ - Write a function that returns the str arr.
 *
 * @in: The para struct.
 *
 * Return: It will return (in->environ_copy).
*/

char **g_environ(p_t *in)
{
	/* If condition: */
	if (!in->environ_copy || in->environ_c)
	{
		in->environ_copy = list_str(in->env);
		in->environ_c = 0;
	}
	return (in->environ_copy);
}

/* unse: */

/**
 * unse - Write a function that removes the var.
 *
 * @in: The para struct.
 * @v: The var.
 *
 * Return: It will return (in->environ_c).
*/

int unse(p_t *in, char *v)
{
	size_t index;
	list_t *n = in->environ_linked_list;
	char *s;

	index = 0;
	/* If condition: */
	if (!n || !v)
	{
		return (0);
	}
	/* While loop: */
	while (n)
	{
		s = s_with(n->str, v);
		if (s && *s == '=')
		{
			in->environ_c = remove_node_indx(&(in->environ_linked_list), index);
			index = 0;
			n = in->environ_linked_list;
			continue;
		}
		n = n->next;
		index++;
	}
	return (in->environ_c);
}

/* se: */

/**
 * se - Write a function that initialize a new var.
 *
 * @in: The para struct.
 * @v: The var.
 * @num: The value.
 *
 * Return: It will return (0).
*/

int se(p_t *in, char *v, char *num)
{
	list_t *n;
	char *s;
	char *bu = NULL;

	if (!v || !num)
		return (0);
	bu = malloc(s_len(v) + s_len(num) + 2);
	if (!bu)
		return (1);
	s_copy(bu, v);
	s_cat(bu, "=");
	s_cat(bu, num);
	n = in->environ_linked_list;
	while (n)
	{
		s = s_with(n->str, v);
		if (s && *s == '=')
		{
			free(n->str);
			n->str = bu;
			in->environ_c = 1;
			return (0);
		}
		n = n->next;
	}
	new_node_e(&(in->environ_linked_list), bu, 0);
	free(bu);
	in->environ_c = 1;
	return (0);
}
