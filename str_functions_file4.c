#include "s_shell.h"

/* st1: */

/**
 * **st1 - Write a function that splits a string.
 *
 * @p: The string.
 * @d_s: The second string.
 *
 * Return: It will return (t).
*/

char **st1(char *p, char *d_s)
{
	char **t;
	int words, index1, index2, index3, index4;

	words = 0;
	if (p == NULL || p[0] == 0)
		return (NULL);
	if (!d_s)
		d_s = " ";
	for (index1 = 0; p[index1] != '\0'; index1++)
		if (!i_d(p[index1], d_s) && (i_d(p[index1 + 1], d_s) || !p[index1 + 1]))
			words++;

	if (words == 0)
		return (NULL);
	t = malloc((1 + words) * sizeof(char *));
	if (!t)
		return (NULL);
	for (index1 = 0, index2 = 0; index2 < words; index2++)
	{
		while (i_d(p[index1], d_s))
			index1++;
		index3 = 0;
		while (!i_d(p[index1 + index3], d_s) && p[index1 + index3])
			index3++;
		t[index2] = malloc((index3 + 1) * sizeof(char));
		if (!t[index2])
		{
			for (index3 = 0; index3 < index2; index3++)
				free(t[index3]);
			free(t);
			return (NULL);
		}
		for (index4 = 0; index4 < index3; index4++)
			t[index2][index4] = p[index1++];
		t[index2][index4] = 0;
	}
	t[index2] = NULL;
	return (t);
}

/* st2: */

/**
 * **st2 - Write a function that splits a string.
 *
 * @p: The string.
 * @d_s: The second string.
 *
 * Return: It will return (t).
*/

char **st2(char *p, char d_s)
{
	char **t;
	int words, index1, index2, index3, index4;

	words = 0;
	if (p == NULL || p[0] == 0)
		return (NULL);
	for (index1 = 0; p[index1] != '\0'; index1++)
		if ((p[index1] != d_s && p[index1 + 1] == d_s) ||
		    (p[index1] != d_s && !p[index1 + 1]) || p[index1 + 1] == d_s)
			words++;
	if (words == 0)
		return (NULL);
	t = malloc((1 + words) * sizeof(char *));
	if (!t)
		return (NULL);
	for (index1 = 0, index2 = 0; index2 < words; index2++)
	{
		while (p[index1] == d_s && p[index1] != d_s)
			index1++;
		index3 = 0;
		while (p[index1 + index3] != d_s && p[index1 + index3] &&
				p[index1 + index3] != d_s)
			index3++;
		t[index2] = malloc((index3 + 1) * sizeof(char));
		if (!t[index2])
		{
			for (index3 = 0; index3 < index2; index3++)
				free(t[index3]);
			free(t);
			return (NULL);
		}
		for (index4 = 0; index4 < index3; index4++)
			t[index2][index4] = p[index1++];
		t[index2][index4] = 0;
	}
	t[index2] = NULL;
	return (t);
}
