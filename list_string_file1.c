#include "s_shell.h"

/* new_node: */

/**
 * new_node - Write a function that adds a new node.
 *
 * @p: The address.
 * @s: The string.
 * @index: The node index.
 *
 * Return: It will return (new_p).
*/

l_t *new_node(l_t **p, const char *s, int index)
{
	l_t *new_p;

	/* If condition: */
	if (!p)
	{
		return (NULL);
	}
	new_p = malloc(sizeof(l_t));
	/* If condition: */
	if (!new_p)
	{
		return (NULL);
	}
	m_set((void *)new_p, 0, sizeof(l_t));
	new_p->index = index;
	/* If condition: */
	if (s)
	{
		new_p->s = s_dup(s);
		if (!new_p->s)
		{
			free(new_p);
			return (NULL);
		}
	}
	new_p->next = *p;
	*p = new_p;

	return (new_p);
}

/* new_node_e: */

/**
 * new_node_e - Write a function that adds a node to the end.
 *
 * @p: The address.
 * @s: The string.
 * @index: The node index.
 *
 * Return: It will return (add_new_node).
*/

l_t *new_node_e(l_t **p, const char *s, int index)
{
	l_t *n;
	l_t *add_new_node;

	if (!p)
	{
		return (NULL);
	}
	n = *p;
	add_new_node = malloc(sizeof(l_t));
	if (!add_new_node)
	{
		return (NULL);
	}
	m_set((void *)add_new_node, 0, sizeof(l_t));
	add_new_node->index = index;
	if (s)
	{
		add_new_node->s = s_dup(s);
		if (!add_new_node->s)
		{
			free(add_new_node);
			return (NULL);
		}
	}
	if (n)
	{
		while (n->next)
		{
			n = n->next;
		}
		n->next = add_new_node;
	}
	else
	{
		*p = add_new_node;
	}
	return (add_new_node);
}

/* p_l_s: */

/**
 * p_l_s - Write a function that prints the string.
 *
 * @p: The pointer.
 *
 * Return: It will return (index).
*/

size_t p_l_s(const l_t *p)
{
	size_t index;

	index = 0;
	/* While loop: */
	while (p)
	{
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		index++;
	}
	return (index);
}

/* remove_node_indx: */

/**
 * remove_node_indx - Write a function that removes node.
 *
 * @p: The address.
 * @n_index: The node index.
 *
 * Return: It will return 1 or 0.
*/

int remove_node_indx(l_t **p, unsigned int n_index)
{
	unsigned int index;
	l_t *n;
	l_t *p_n;

	index = 0;
	/* If condition: */
	if (!p || !*p)
	{
		return (0);
	}
	/* If condition: */
	if (!n_index)
	{
		n = *p;
		*p = (*p)->next;
		free(n->str);
		free(n);
		return (1);
	}
	n = *p;
	/* While loop: */
	while (n)
	{
		if (i == n_index)
		{
			p_n->next = n->next;
			free(n->str);
			free(n);
			return (1);
		}
		i++;
		p_n = n;
		n = n->next;
	}
	return (0);
}

/* li_free: */

/**
 * li_free - Write a function that frees all the nodes.
 *
 * @p: The address.
*/

void li_free(l_t **p)
{
	l_t *nxt_n;
	l_t *n;
	l_t *h;

	if (!p || !*p)
	{
		return;
	}
	h = *p;
	n = h;
	while (n)
	{
		nxt_n = n->next;
		free(n->str);
		free(n);
		n = nxt_n;
	}
	*p = NULL;
}
