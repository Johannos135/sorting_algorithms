#include "sort.h"

/**
 * more - checks whether i is greater than j
 * @i: integer i
 * @j: integer j
 *
 * Return: 1 if true otherwise 0
 */
int more(int i, int j)
{
	return (i > j);
}

/**
 * bubble_sort - function that sorts an array in
 * ascending order using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped = 1;

	for (i = 0; i < (size - 1) && swapped; i++)
	{
		swapped = 0;

		for (j = 0; j < (size - i - 1); j++)
		{
			if (more(array[j], array[j + 1]))
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	}
}
