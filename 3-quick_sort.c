#include "sort.h"

void swap(int *array, size_t size, int *a, int *b);
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi);

/**
 * quicksort - Sorts an integer array using the quicksort algorithm
 * with Lomuto partitioning scheme.
 * @array: The array to sort.
 * @size: The size of the array.
 * @lo: The low index of the sort range.
 * @hi: The high index of the sort range.
 *
 * Return: void
 */
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	if (lo < hi)
	{
		size_t p = lomuto_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - Calls the quicksort function to sort an integer array.
 * @array: The integer array to sort.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}

/**
 * swap - Swaps two integer values in an array.
 * @array: The array containing the values to swap.
 * @size: The size of the array.
 * @a: Address of first value.
 * @b: Address of second value.
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - Partitions an integer array using
 * the Lomuto partitioning scheme.
 * @array: The integer array to partition.
 * @size: The size of the array.
 * @lo: The low index of sort range.
 * @hi: The high index of sort range.
 *
 * Return: void
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = lo; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}
