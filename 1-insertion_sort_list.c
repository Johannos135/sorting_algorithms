#include <stdio.h>
#include "sort.h"

/**
 * sorted_insert - insert in a sorted way
 * @list: listint_t list
 * @node: listint_t new node
 */
void sorted_insert(listint_t **list, listint_t *node)
{
	listint_t *current;

	if (*list == NULL)
	{
		*list = node;
	}
	else if ((*list)->n >= node->n)
	{
		node->next = *list;
		node->next->prev = node;
		*list = node;
	}
	else
	{
		current = *list;

		while (current->next != NULL &&
				current->next->n < node->n)
			current = current->next;

		node->next = current->next;

		if (current->next != NULL)
			node->next->prev = node;

		current->next = node;
		node->prev = current;
	}
}

/**
 * insertion_sort_list - sorts doubly linked list
 * in an ascending order using insertion algorithm.
 *
 * @list: doubly linked list entry
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *curr = *list;

	while (curr != NULL)
	{
		listint_t *next = curr->next;

		curr->prev = curr->next = NULL;

		sorted_insert(&sorted, curr);

		print_list(*list);

		curr = next;
	}
	*list = sorted;
}
