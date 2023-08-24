#include "s_shell.h"

/* s_copy: */

/**
 * s_copy - Write a function that prints copy of the string.
 *
 * @r1: The dest.
 * @r2: The src.
 *
 * Return: It will return (r1).
*/

char *s_copy(char *r1, char *r2)
{
	int index;

	index = 0;
	/* If condition: */
	if (r1 == r2 || r2 == 0)
	{
		return (r1);
	}
	/* While loop: */
	while (r2[index])
	{
		r1[index] = r2[index];
		index++;
	}
	r1[index] = 0;

	return (r1);
}

/* s_dup: */

/**
 * s_dup - Write a function that duplicates the string.
 *
 * @p: The string.
 *
 * Return: pointer to the duplicated string
*/

char *s_dup(const char *p)
{
	int len;
	char *r;

	len = 0;
	/* If condition: */
	if (p == NULL)
	{
		return (NULL);
	}
	/* While loop: */
	while (*p++)
	{
		len++;
	}
	r = malloc(sizeof(char) * (len + 1));
	/* If condition: */
	if (!r)
	{
		return (NULL);
	}
	/* For loop: */
	for (len++; len--;)
	{
		r[len] = *--p;
	}

	return (r);
}

/* _puts: */

/**
 *_puts - Write a function that prints the string.
 *
 *@p: The string.
*/

void _puts(char *p)
{
	int index;

	index = 0;
	/* If condition: */
	if (!p)
	{
		return;
	}
	/* While loop: */
	while (p[index] != '\0')
	{
		_putchar(p[index]);
		index++;
	}
}

/* _putchar: */

/**
 * _putchar - Write a function that prints the character to stdout.
 *
 * @character: The character.
 *
 * Return: It will return (1).
*/

int _putchar(char character)
{
	static char buffer[W_BUFFER_S];
	static int index;

	/* If condition: */
	if (character == BUFFER_F || index >= W_BUFFER_S)
	{
		write(1, buffer, index);
		index = 0;
	}
	/* If condition: */
	if (character != BUFFER_F)
	{
		buffer[index++] = character;
	}

	return (1);
}
