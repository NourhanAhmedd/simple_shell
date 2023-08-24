#include "s_shell.h"

/* the_hist: */

/**
 * the_hist - Write a function that displays the hist.
 *
 * @in: The para struct.
 *
 * Return: It will return (0).
*/

int the_hist(p_t *in)
{
	p_li(in->hist_n);
	return (0);
}

/* us_al: */

/**
 * us_al - Write a function that sets string
 *
 * @in: The para struct.
 * @s: The string.
 *
 * Return: It will return (r).
*/

int us_al(p_t *in, char *s)
{
	int r;
	char *t, a;

	t = s_ch(s, '=');
	/* If condition: */
	if (!t)
	{
		return (1);
	}
	a = *t;
	*t = 0;
	r = remove_node_indx(&(in->al_n),
		node_indx(in->al_n, node_st(in->al_n, s, -1)));
	*t = a;
	return (r);
}

/* s_al: */

/**
 * s_al - Write a function that sets alias.
 *
 * @in: The para struct.
 * @s: The string.
 *
 * Return: Always 0 on success, 1 on error
*/

int s_al(p_t *in, char *s)
{
	char *t;

	t = s_ch(s, '=');
	/* If condition: */
	if (!t)
	{
		return (1);
	}
	/* If condition: */
	if (!*++t)
	{
		return (us_al(in, s));
	}
	us_al(in, s);
	return (new_node_e(&(in->al_n), s, 0) == NULL);
}

/* p_al: */

/**
 * p_al - Write a function that prints the alias.
 *
 * @n: The node.
 *
 * Return: It will return 1 or 0.
*/

int p_al(l_t *n)
{
	char *c = NULL;
	char *s = NULL;

	/* If condition: */
	if (n)
	{
		s = s_ch(n->str, '=');
		/* For loop: */
		for (c = n->str; c <= s; c++)
		{
			_putchar(*c);
		}
		_putchar('\'');
		_puts(s + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/* the_alias: */

/**
 * the_alias - Write a function that prints the alias.
 *
 * @in: The para struct.
 *
 *  Return: It will return (0).
*/

int the_alias(p_t *in)
{
	char *s = NULL;
	l_t *n = NULL;
	int index;

	index = 0;
	/* If condition: */
	if (in->arguement_c == 1)
	{
		n = in->al_n;
		/* While loop: */
		while (n)
		{
			p_al(n);
			n = n->next;
		}
		return (0);
	}
	/* For loop: */
	for (index = 1; in->arguement_value[index]; index++)
	{
		s = s_ch(in->arguement_value[index], '=');
		if (s)
			s_al(in, in->arguement_value[index]);
		else
			p_al(node_st(in->al_n, in->arguement_value[index], '='));
	}
	return (0);
}
