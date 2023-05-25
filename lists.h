#ifndef LISTS_H_
#define LISTS_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listtoken_s - singly linked list
 * @token: pointer to a token
 * @token_length: length of the token
 * @next: points to the next node
 *
 * Description: Singly linked list node structure for tokens
 */
typedef struct listtoken_s
{
    char *token;
    int token_length;
    struct listtoken_s *next;
} listtoken_t;

size_t print_listtoken_shell(const listtoken_t *head);
size_t listtoken_len_shell(const listtoken_t *head);
listtoken_t *nodetoken_end(listtoken_t **head, char *token);
void freeshell_listtoken(listtoken_t **head);

#endif
