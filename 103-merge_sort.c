#include <stdio.h>
#include "sort.h"

/**
 * print_data - prints all the data
 *
 * @msg: message to print
 * @ar: array to return
 * @from: input
 * @to: output
 */
void print_data(char *msg, int *ar, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, ar[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge - helper function
 *
 * @ar: array
 * @low: low index
 * @middle: middle
 * @high: high index
 * @buff: buffer
 */
void merge(int *ar, int low, int middle, int high, int *buff)
{
	int var_low, var_midl, i;

	var_low = i = low;
	var_midl = middle + 1;

	printf("Merging...\n");
	print_data("left", ar, low, middle);
	print_data("right", ar, middle + 1, high);

	while (var_low <= middle && var_midl <= high)
	{
		if (ar[var_low] < ar[var_midl])
			buff[i++] = ar[var_low++];
		else
			buff[i++] = ar[var_midl++];
	}

	while (var_low <= middle)
		buff[i++] = ar[var_low++];

	while (var_midl <= high)
		buff[i++] = ar[var_midl++];

	for (i = low; i <= high; i++)
		ar[i] = buff[i];

	print_data("Done", ar, low, high);
}
/**
 * _topdown - top-down the merge
 *
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @buffer: buffer
 */
void _topdown(int *array, int low, int high, int *buffer)
{
	int midle;

	if (low < high)
	{
		midle = (low + high - 1) / 2;
		_topdown(array, low, midle, buffer);
		_topdown(array, midle + 1, high, buffer);
		merge(array, low, midle, high, buffer);
	}
}
/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the merge sort algorithm
 *
 * @array: array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	_topdown(array, 0, size - 1, buffer);
	free(buffer);
}
