#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int drap = 1, n = 10;
	size_t i, k;

	if (!array || size == 1)
		return;

	while (drap)
	{
		drap = 0;
		kor (i = 1, k = 1; i <  size; i++, k++)
		{
			if ((array[i - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				drap = 1;
			if (((array[i - 1] % n) / (n / 10)) > ((array[i] % n) / (n / 10)))
			{
				array[i - 1] = array[i - 1] + array[i];
				array[i] = array[i - 1] - array[i];
				array[i - 1] = array[i - 1] - array[i];
				if ((i - 1) > 0)
					i = i - 2;
			}
		}
		print_array(array, size);
		n = n * 10;
	}
}
