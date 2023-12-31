#ifndef _SORT_
#define _SORT_

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
int more(int, int);
void bubble_sort(int *array, size_t size);
void sorted_insert(listint_t **list, listint_t *node);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void _quick(int *arr, int low, int high, int size);
void quick_sort(int *array, size_t size);
void _fun_sort(int *a, int size, int n);
void shell_sort(int *array, size_t size);
void swap_list(listint_t **ptr1, listint_t **ptr2, int n);
void topup_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void lower_sort(listint_t **ptr, listint_t **limit, listint_t **list);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void print_data(char *msg, int *ar, int from, int to);
void merge(int *ar, int low, int middle, int high, int *buff);
void _topdown(int *array, int low, int high, int *buffer);
void merge_sort(int *array, size_t size);
void swap_nums(int *arr, int a, int b);
void recursion_heap(int *arr, int i, size_t size, int limit);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif
