#include "sort.h"

/**
 * _fun_sort - auxiliar function for
 * shell_sort function
 *
 * @a: array to be sorted
 * @size: size of the array
 * @n: steps
 */
void _fun_sort(int *a, int size, int n)
{
	int tmp, i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				tmp = a[j];
				a[j] = a[j - n];
				a[j - n] = tmp;
			}
		}
	}
	print_array(a, size);
}

/**
 * shell_sort - function that sorts an array
 * of integers using the Shell sort algorithm
 *
 * @array: arrray to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t k = 1;

	while (k < size)
		k = (k * 3) + 1;

	while ((k = (k - 1) / 3) > 0)
		_fun_sort(array, size, k);
}
