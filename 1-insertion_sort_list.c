#include "sort.h"

/**
 * more - checks whether i is greater than j
 * @i: listint_t i
 * @j: listint_t j
 *
 * Return: 1 if true otherwise 0
 */
int more(listint_t *i, listint_t *j)
{
	return (*i > *j);
}

/**
 * insertion_sort_list - sorts doubly linked list
 * in an ascending order using insertion algorithm.
 *
 * @list: doubly linked list entry
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *j;

	if (list == NULL)
		return;

	j = *list;

	while (j)
	{
		while (j->next && more(j->n, j->next->n))
		{
			tmp = j->next;
			j->next = tmp->next;
			tmp->prev = j->prev;

			if (j->prev)
				j->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = j;

			j->prev = tmp;
			tmp->next = j;

			if (tmp->prev)
				j = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
		j = j->next;
	}
}
