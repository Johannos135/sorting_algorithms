#include "sort.h"

/**
 * swap_list - swaps the elements of the list
 *
 * @ptr1: pointer 1
 * @ptr2: pointer 2
 * @n: n is set to 0 for topup and set to 1 for dec
 */
void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *pt, *tmp;

	pt = *ptr1;
	tmp = *ptr2;

	pt->next = tmp->next;
	tmp->prev = pt->prev;

	if (tmp->next)
		tmp->next->prev = pt;

	if (pt->prev)
		pt->prev->next = tmp;

	pt->prev = tmp;
	tmp->next = pt;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = pt;
}

/**
 * topup_sort - puts the bigger numbers to the end
 *
 * @ptr: represents pointer to the bigger number
 * @limit: represents limit of the list
 * @list: represents list of integers
 */
void topup_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *pt;

	pt = *ptr;

	while (pt != *limit && pt->next != *limit)
	{
		if (pt->n > pt->next->n)
		{
			swap_list(&pt, &(pt->next), 0);
			if (pt->prev == NULL)
				*list = pt;
			print_list(*list);
		}
		pt = pt->next;
	}

	*limit = pt;
	*ptr = pt;
}

/**
 * lower_sort - puts the smaller numbers at the beginning
 *
 * @ptr: represents a pointer to the smaller number
 * @limit: represents limit of the list
 * @list: represents list of integers
 */
void lower_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *pt;

	pt = *ptr;

	while (pt != *limit && pt->prev != *limit)
	{
		if (pt->n < pt->prev->n)
		{
			swap_list(&(pt->prev), &pt, 1);
			if (pt->prev->prev == NULL)
				*list = pt->prev;
			print_list(*list);
		}
		pt = pt->prev;
	}

	*limit = pt;
	*ptr = pt;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order using the
 * Cocktail sorting algorithm
 *
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		topup_sort(&ptr, &limit1, list);
		lower_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}
