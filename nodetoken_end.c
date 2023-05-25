#include "lists.h"

/**
 * nodetoken_end - Add a new node at the end of a listtoken_t list
 *
 * Description: This function adds a new node to the end of a linked list.
 *
 * @head: Pointer to a pointer that points to the first node
 * @token: The token to add
 *
 * Return: The address of the new element, or NULL if it failed
 */
listtoken_t *nodetoken_end(listtoken_t **head, char *token)
{
	listtoken_t *new_node, *last_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listtoken_t));
	if (new_node == NULL)
		return (NULL);

	new_node->token = token;
	new_node->token_length = strlen(token);
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}

	return (last_node);
}
