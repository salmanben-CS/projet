#include "main.h"

/**
 * rev_string - reverses a string
 * @str: the string to be reversed
 *
 * Description: This function reverses the characters in a string in-place.
 *
 * Return: void
 */
void rev_string(char *str)
{
	int i, len;
	char tmp;

	len = 0;
	while (str[len] != '\0')
		len++;
	len--;
	for (i = 0; i < len; i++, len--)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
}

/**
 * _itoa - converts an integer to a string
 * @command_num: the number to be converted
 *
 * Description: This function converts an integer to its string representation.
 * It dynamically allocates memory for the resulting string and returns a
 * pointer to it.
 *
 * Return: a pointer to the string representation of the integer
 */
char *_itoa(size_t command_num)
{
	char *str = malloc(sizeof(char) * (32 + 1));
	int i = 0;

	do {
		str[i++] = command_num % 10 + '0';
		command_num /= 10;
	} while (command_num > 0);
	str[i] = '\0';
	rev_string(str);

	return (str);
}
