#include "s_shell.h"

/* length_li: */

/**
 * length_li - Write a function that prints the length of linked list.
 *
 * @p: The pointer.
 *
 * Return: It will return (index).
*/

size_t length_li(const l_t *p)
{
	size_t index;

	index = 0;
	/* While loop: */
	while (p)
	{
		p = p->next;
		index++;
	}

	return (index);
}

/* list_str: */

/**
 * list_str - Write a function that returns an array.
 *
 * @p: The pointer.
 *
 * Return: It will return (a_s).
*/

char **list_str(l_t *p)
{
	char **a_s;
	char *s;
	l_t *n = p;
	size_t index1 = length_li(p);
	size_t index2;

	/* If condition: */
	if (!p || !index1)
	{
		return (NULL);
	}
	a_s = malloc(sizeof(char *) * (index1 + 1));
	/* If condition: */
	if (!a_s)
	{
		return (NULL);
	}
	/* For loop: */
	for (index1 = 0; n; n = n->next, index1++)
	{
		s = malloc(s_len(n->s) + 1);
		if (!s)
		{
			for (index2 = 0; index2 < index1; index2++)
			{
				free(a_s[index2]);
			}
			free(a_s);
			return (NULL);
		}
		s = s_copy(s, n->s);
		a_s[index1] = s;
	}
	a_s[index1] = NULL;
	return (a_s);
}

/* p_li: */

/**
 * p_li - Write a function that prints all elements of the linked list.
 *
 * @p: The pointer.
 *
 * Return: It will return (index).
*/

size_t p_li(const l_t *p)
{
	size_t index;

	index = 0;
	while (p)
	{
		_puts(conv_num(p->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		index++;
	}
	return (index);
}

/* node_st: */

/**
 * node_st - Write a function that prints the node with prefix.
 *
 * @n: The pointer.
 * @px: The string.
 * @nx: The next char.
 *
 * Return: It will return (NULL).
*/

l_t *node_st(l_t *n, char *px, char nx)
{
	char *s = NULL;

	/* While loop: */
	while (n)
	{
		s = s_with(n->str, px);
		/* If condition: */
		if (s && ((nx == -1) || (*s == nx)))
		{
			return (n);
		}
		n = n->next;
	}
	return (NULL);
}

/* node_indx: */

/**
 * node_indx - Write a function that gets the index of a node
 *
 * @p: The pointer 1.
 * @n: The pointer 2.
 *
 * Return: It will return (-1).
*/

ssize_t node_indx(l_t *p, l_t *n)
{
	size_t index;

	index = 0;
	/* While loop: */
	while (p)
	{
		/* If condition: */
		if (p == n)
			return (index);
		p = p->next;
		index++;
	}
	return (-1);
}
