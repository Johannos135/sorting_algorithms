#include "sort.h"

/**
 * counting_sort -Sorts an arrayof integers
 * in ascending order using the counting sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int n, i;
	int *stream, *coll;

	if (size < 2)
		return;

	for (n = i = 0; i < (int)size; i++)
		if (array[i] > n)
			n = array[i];

	stream = malloc(sizeof(int) * (n + 1));
	if (!stream)
		return;

	for (i = 0; i <= n; i++)
		stream[i] = 0;
	for (i = 0; i < (int)size; i++)
		stream[array[i]] += 1;
	for (i = 1; i <= n; i++)
		stream[i] += stream[i - 1];

	print_array(stream, (n + 1));
	coll = malloc(sizeof(int) * (size + 1));

	if (!coll)
	{
		free(stream);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		coll[stream[array[i]] - 1] = array[i];
		stream[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = coll[i];

	free(stream);
	free(coll);
}
