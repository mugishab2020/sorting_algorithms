#include "sort.h"
/**
 * merge_subarr - function to devid array in subarray for merging
 * @subarr: the subarray to merge
 * @buff: the integer var to be used
 * @front: the array fron front
 * @mid: the mid point of the aray
 * @back: the array from back
 *
 */
void merge_subarr(int *subarr, int *buff,
		size_t front, size_t mid, size_t back)
{
	size_t i = front, j = mid, k = 0;

	while (i < mid && j < back)
		buff[k++] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	while (i < mid)
		buff[k++] = subarr[i++];
	while (j < back)
		buff[k++] = subarr[j++];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front <= 1)
		return;

	mid = front + (back - front) / 2;

	merge_sort_recursive(subarr, buff, front, mid);
	merge_sort_recursive(subarr, buff, mid, back);
	merge_subarr(subarr, buff, front, mid, back);
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);

	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
