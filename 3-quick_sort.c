#include "sort.h"
/**
 * lomuto_partition - makes the array in two part for finding pivot
 * @array: that we are handling
 * @l: the low element
 * @h: the highest element
 * @size: of the array to sort
 * Return: 0 for success
 */

int lomuto_partition(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = l, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swap_ints(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}
/**
 * quick_sort_help - functioon for helping the quick sort
 * @array: the arrray we are handling
 * @l: the low element
 * @h: the biggest element
 * @size: of the array
 *
 */
void quick_sort_help(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = lomuto_partition(array, size, l, h);
		quick_sort_help(array, size, l, i - 1);
		quick_sort_help(array, size, i + 1, h);
	}
}
/**
 * quick_sort - function for finishing sorting
 * @array: the array that we are sorting
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_help(array, size, 0, size - 1);
}
/**
 * swap_ints - function to swap integers
 * @a: first number
 * @b: The second number to swap
 */
void swap_ints(int *a, int *b)
{
	int tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}
