#include "s_shell.h"

/* the_chain: */

/**
 * the_chain - Write a function that returns if the char is a chain or not.
 *
 * @in: The para struct.
 * @bu: The buffer.
 * @s: The address.
 *
 * Return: It will return 1 or 0.
*/

int the_chain(l_t *in, char *bu, size_t *s)
{
	size_t index;

	index = *s;
	if (bu[index] == '|' && bu[index + 1] == '|')
	{
		bu[index] = 0;
		index++;
		in->cmd_b_t = C_OR;
	}
	else if (bu[index] == '&' && bu[index + 1] == '&')
	{
		bu[index] = 0;
		index++;
		in->cmd_b_t = C_AND;
	}
	else if (bu[index] == ';')
	{
		bu[index] = 0;
		in->cmd_b_t = C_CHAIN;
	}
	else
	{
		return (0);
	}
	*s = index;
	return (1);
}

/* chck_ch: */

/**
 * chck_ch - Write a function that checks the last status.
 *
 * @in: The para struct.
 * @bu: The buffer.
 * @s: The address.
 * @index1: The index.
 * @length: The buffer length.
*/

void chck_ch(l_t *in, char *bu, size_t *s, size_t index1, size_t length)
{
	size_t index2;

	index2 = *s;
	/* If condition */
	if (in->cmd_b_t == C_AND)
	{
		/* If condition */
		if (in->st)
		{
			bu[index1] = 0;
			index2 = length;
		}
	}
	/* If condition */
	if (in->cmd_b_t == C_OR)
	{
		if (!in->st)
		{
			bu[index1] = 0;
			index2 = length;
		}
	}
	*s = index2;
}

/* rep_ali: */

/**
 * rep_ali - Write a function that replaces the aliases.
 *
 * @in: The param struct.
 *
 * Return: It will return 1 or 0.
*/

int rep_ali(l_t *in)
{
	int index;
	char *s;
	list_t *n;

	/* For loop */
	for (index = 0; index < 10; index++)
	{
		n = node_st(in->al_n, in->arguement_value[0], '=');
		/* If condition */
		if (!n)
		{
			return (0);
		}
		free(in->arguement_value[0]);
		s = s_ch(n->str, '=');
		/* If condition */
		if (!s)
		{
			return (0);
		}
		s = s_dup(s + 1);
		/* If condition */
		if (!s)
		{
			return (0);
		}
		in->arguement_value[0] = s;
	}
	return (1);
}

/* rep_v: */

/**
 * rep_v - Write a function that replaces the var.
 *
 * @in: The para struct.
 *
 * Return: It will return 1 or 0.
*/

int rep_v(l_t *in)
{
	int index;
	list_t *n;

	index = 0;
	for (index = 0; in->arguement_value[index]; index++)
	{
		/* If condition */
		if (in->arguement_value[index][0] != '$' || !in->arguement_value[index][1])
			continue;
		if (!s_cmp(in->arguement_value[index], "$?"))
		{
			rep_str(&(in->arguement_value[index]),
				s_dup(conv_num(in->st, 10, 0)));
			continue;
		}
		if (!s_cmp(in->arguement_value[index], "$$"))
		{
			rep_str(&(in->arguement_value[index]),
				s_dup(conv_num(getpid(), 10, 0)));
			continue;
		}
		n = node_st(in->environ_linked_list, &in->arguement_value[index][1], '=');
		if (n)
		{
			rep_str(&(in->arguement_value[index]),
				s_dup(s_ch(n->str, '=') + 1));
			continue;
		}
		rep_str(&in->arguement_value[index], s_dup(""));
	}
	return (0);
}

/* rep_str: */

/**
 * rep_str - Write a function that replaces the str.
 *
 * @o_add: The old address.
 * @n_str: The new str.
 *
 * Return: It will return 1 or 0.
*/

int rep_str(char **o_add, char *n_str)
{
	free(*o_add);
	*o_add = n_str;
	return (1);
}
