#include "main.h"

/**
 * digit_counter - Count the number of digits in a given number
 *
 * Description: This function counts the number of digits in the given number.
 *
 * @command_num: The number to be counted
 *
 * Return: The number of digits in the given number
 */
int digit_counter(size_t command_num)
{
	int digit_count = 0;

	if (command_num == 0)
		return (1);
	while (command_num != 0)
	{
		command_num /= 10;
		digit_count++;
	}

	return (digit_count);
}
