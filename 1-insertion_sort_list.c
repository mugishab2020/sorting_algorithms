#include "sort.h"
/**
 * insertion_sort_list - function to make insertion sort
 * @list: A pointer to the head of the doubly-linked list.
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
listint_t *curr, *sorted, *tmp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

for (curr = (*list)->next; curr != NULL; curr = tmp)
{
tmp = curr->next;
sorted = curr->prev;

while (sorted != NULL && sorted->n > curr->n)
{
if (curr->prev)
	curr->prev->next = curr->next;
if (curr->next)
	curr->next->prev = curr->prev;

if (sorted->prev)
	sorted->prev->next = curr;
else
	*list = curr;

curr->prev = sorted->prev;
curr->next = sorted;
sorted->prev = curr;
sorted = curr->prev;
print_list(*list);
}
}
}
