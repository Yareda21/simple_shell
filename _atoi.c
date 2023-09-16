#include "shell.h"

/**
 * interactive - check if the shell is interactive
 * @info: struct address
 *
 * Return: 1 -interactive mode, otherwise 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checking a delimeter
 * @c: charactor
 * @delim: string delimeter
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim++ == c)
		{
			return (1);
		}
	return (0);
	}
}

/**
 * _isalpha - alphabetic character checker
 * @c: input character
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoi - asci to an integer
 * @s: the input string to be converted
 * Return: 0 - no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int j;
	int sign = 1;
	int flag = 0;
	int output;
	unsigned int result = 0;

	for (j = 0; s[j] != '\0' && flag != 2; j++)
	{
		if (s[j] == '-')
			sign *= -1;

		if (s[j] >= '0' && s[j] <= '9')
		{
			flag = 1;
			result = result * 10;
			result = result + (s[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
	{
		output = -result;
	}
	else
	{
		output = result;
	}

	return (output);
}

