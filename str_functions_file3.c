#include "s_shell.h"

/* s_ch: */

/**
 **s_ch - Write a function that locates the char.
 *
 *@p: The string.
 *@character: The char.
 *
 *Return: It will return (p).
*/

char *s_ch(char *p, char character)
{
	/* Do while loop: */
	do {
		/* If condition: */
		if (*p == character)
		{
			return (p);
		}
	} while (*p++ != '\0');

	return (NULL);
}

/* sn_copy: */

/**
 **sn_copy - Write a function that will copy the string.
 *
 *@r1: The dest.
 *@r2: The src.
 *@number: The number.
 *
 *Return: It will return (p).
*/

char *sn_copy(char *r1, char *r2, int number)
{
	char *p = r1;
	int index1 = 0;
	int index2;

	/* While loop: */
	while (r2[index1] != '\0' && index1 < number - 1)
	{
		r1[index1] = r2[index1];
		index1++;
	}
	/* If condition: */
	if (index1 < number)
	{
		index2 = index1;
		/* While loop: */
		while (index2 < number)
		{
			r1[index2] = '\0';
			index2++;
		}
	}

	return (p);
}

/* sn_cat: */

/**
 **sn_cat - Write a function that concatenates the strings.
 *
 *@r1: The dest.
 *@r2: The src.
 *@number: The number.
 *
 *Return: It will return (p).
*/

char *sn_cat(char *r1, char *r2, int number)
{
	char *p = r1;
	int index1 = 0;
	int index2 = 0;

	/* While loop: */
	while (r1[index1] != '\0')
	{
		index1++;
	}
	/* While loop: */
	while (r2[index2] != '\0' && index2 < number)
	{
		r1[index1] = r2[index2];
		index1++;
		index2++;
	}
	/* If condition: */
	if (index2 < number)
	{
		r1[index1] = '\0';
	}

	return (p);
}
