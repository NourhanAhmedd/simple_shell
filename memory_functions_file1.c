#include "s_shell.h"

/* m_set: */

/**
 **m_set - Write a function that fills with a const byte.
 *
 *@p: The pointer.
 *@a: The bytes.
 *@c: The number of bytes.
 *
 *Return: It will return (p).
*/

char *m_set(char *p, char a, unsigned int c)
{
	unsigned int index;

	/* For loop: */
	for (index = 0; index < c; index++)
	{
		p[index] = a;
	}

	return (p);
}

/* file_free: */

/**
 * file_free - Write a function that frees the string.
 * @s: The string.
*/

void file_free(char **s)
{
	char **p = s;

	/* If condition: */
	if (!s)
	{
		return;
	}
	/* While loop: */
	while (*s)
	{
		free(*s++);
	}
	free(p);
}

/* re_all: */

/**
 * re_all - Write a function that reallocates a block.
 *
 * @t: The pointe.
 * @s1: The old size.
 * @s2: The new size.
 *
 * Return: It will return (s).
*/

void *re_all(void *t, unsigned int s1, unsigned int s2)
{
	char *s;

	/* If condition: */
	if (!t)
	{
		return (malloc(s2));
	}
	if (!s2)
	{
		return (free(t), NULL);
	}
	if (s2 == s1)
	{
		return (t);
	}
	s = malloc(s2);
	if (!s)
	{
		return (NULL);
	}
	s1 = s1 < s2 ? s1 : s2;
	/* While loop: */
	while (s1--)
	{
		s[s1] = ((char *)t)[s1];
	}
	free(t);
	return (s);
}
