#include "s_shell.h"

/* e_p: */

/**
 * e_p - Write a function that prints an input.
 *
 * @p: The string.
*/

void e_p(char *p)
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
		e_p_char(p[index]);
		index++;
	}
}

/* e_p_char: */

/**
 * e_p_char - Write a function that writes the char.
 *
 * @s: The char.
 *
 * Return: It will return (1).
*/

int e_p_char(char s)
{
	static char bu[W_BUFFER_S];
	static int index;

	/* If condition: */
	if (s == BUFFER_F || index >= W_BUFFER_S)
	{
		write(2, bu, index);
		index = 0;
	}
	/* If condition: */
	if (s != BUFFER_F)
	{
		bu[index++] = s;
	}
	return (1);
}

/* put_f: */

/**
 * put_f - Write a function that writes the char.
 *
 * @ch: The char.
 * @f: The file.
 *
 * Return: It will return (1).
*/

int put_f(char ch, int f)
{
	static char bu[W_BUFFER_S];
	static int index;

	/* If condition: */
	if (ch == BUFFER_F || index >= W_BUFFER_S)
	{
		write(f, bu, index);
		index = 0;
	}
	/* If condition: */
	if (ch != BUFFER_F)
	{
		bu[index++] = ch;
	}
	return (1);
}

/* puts_f: */

/**
 * puts_f - Write a function that prints an input.
 *
 * @s: The str.
 * @f: The file.
 *
 * Return: It will return (index).
*/

int puts_f(char *s, int f)
{
	int index;

	index = 0;
	/* If condition: */
	if (!s)
	{
		return (0);
	}
	/* While loop: */
	while (*s)
	{
		index = index + put_f(*s++, f);
	}
	return (index);
}
