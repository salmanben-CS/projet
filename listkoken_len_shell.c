#include "lists.h"

/**
 * listtoken_len_shell - returns the number of elements in a listtoken_t list
 *
 * Description: Counts the number of elements in a linked listtoken_t list
 *
 * @head: points to the first node of the list
 *
 * Return: the number of elements in the list
 */
size_t listtoken_len_shell(const listtoken_t *head)
{
	int count = 0;
	const listtoken_t *current;

	if (head == NULL)
		return (0);

	current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
