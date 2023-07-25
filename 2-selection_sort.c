#include"sort.h"
/**
 * swap_ints - function to swap integer
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;

}
/**
 * selection_sort - function to sort using selection sort algorithm
 *@size: the size of the array
 *@array: the array to sort
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index;

	for (i = 0; i < size - 1; i++)
	{
		index = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[index])
				index = j;
		if (index != i)
		{
			swap_ints(&array[index], &array[i]);
			print_array(array, size);
		}
	}
}
