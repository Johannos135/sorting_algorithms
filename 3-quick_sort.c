#include "sort.h"

/**
 * _qsort - auxiliar function for the
 * quick_sort function
 *
 * @a: array to be sorted
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 */
void _quick(int *arr, int low, int high, int size)
{
	int i, p, w;
	int tmp;

	if (low < high)
	{
		p = high;
		w = low;
		for (i = low; i < high; i++)
		{
			if (arr[i] < arr[p])
			{
				if (i != w)
				{
					tmp = arr[i];
					arr[i] = arr[w];
					arr[w] = tmp;
					print_array(arr, size);
				}
				w++;
			}
		}
		if (w != p && arr[w] != arr[p])
		{
			tmp = arr[w];
			arr[w] = arr[p];
			arr[p] = tmp;
			print_array(arr, size);
		}
		_quick(arr, low, w - 1, size);
		_quick(arr, w + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	_quick(array, 0, size - 1, size);
}
