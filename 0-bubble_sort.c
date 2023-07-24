#include "sort.h"
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

/**
 * bubble_sort - functionto sort using bubb;e sort
 * @array: Array ton be sorted
 * @size: size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
