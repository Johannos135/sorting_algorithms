#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integer
 * using the selection sort algorithm.
 *
 * @array: array to be sorted.
 * @size:  size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, max;
	int temp;

	for (x = 0; x < size - 1; x++)
	{
		max = 0;

		for (y = 1; y < size - 1 - x; y++)
		{
			if (array[y] > array[max])
			{
				max = y;
			}
		}
		temp = array[size - 1 - x];
		array[size - 1 - x] = array[max];
		array[max] = temp;
		print_array(array, size);
	}
}
