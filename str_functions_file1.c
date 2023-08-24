#include "s_shell.h"

/* s_len: */

/**
 * s_len - Write a function that returns the length of the string.
 *
 * @p: The string.
 *
 * Return: It will return (index).
*/

int s_len(char *p);
{
	int index;

	index = 0;
	/* If condition: */
	if (!p)
	{
		return (0);
	}
	/* While loop: */
	while (*p++)
	{
		index++;
	}

	return (index);
}

/* s_cat: */

/**
 * s_cat - Write a function that concatenates the strings.
 *
 * @r1: The dest.
 * @r2: The src.
 *
 * Return: It will return (p).
*/

char *s_cat(char *r1, char *r2)
{
	char *p = r1;

	/* While loop: */
	while (*r1)
	{
		r1++;
	}
	/* While loop: */
	while (*r2)
	{
		*r1++ = *r2++;
	}
	*r1 = *r2;

	return (p);
}

/* s_cmp: */

/**
 * s_cmp - Write a function that returns the comparison of the strings.
 *
 * @p1: The first str.
 * @p2: The second str.
 *
 * Return: It will return (*p1 < *p2 ? -1 : 1).
*/

int s_cmp(char *p1, char *p2)
{
	/* While loop: */
	while (*p1 && *p2)
	{
		/* If condition: */
		if (*p1 != *p2)
		{
			return (*p1 - *p2);
		}
		p1++;
		p2++;
	}
	/* If condition: */
	if (*p1 == *p2)
	{
		return (0);
	}
	else
	{
		return (*p1 < *p2 ? -1 : 1);
	}
}

/* s_with: */

/**
 * s_with - Write a function that returns the string h.
 *
 * @h: The string.
 * @n: The substring.
 *
 * Return: It will return ((char *)h);.
*/

char *s_with(const char *h, const char *n)
{
	/* While loop: */
	while (*n)
	{
		/* If condition: */
		if (*n++ != *h++)
		{
			return (NULL);
		}
	}

	return ((char *)h);
}
