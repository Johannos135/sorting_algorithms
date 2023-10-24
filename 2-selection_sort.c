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
		max = x;

		for (y = x + 1; y < size; y++)
		{
			if (array[max] > array[y])
			{
				max = y;
			}
		}

		if (x != max)
		{
			temp = array[size - 1 - x];
			array[size - 1 - x] = array[max];
			array[max] = temp;
			print_array(array, size);
		}
	}
}
