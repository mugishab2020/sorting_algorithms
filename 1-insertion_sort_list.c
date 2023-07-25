#include "sort.h"
/**
 * insertion_sort_list - function to make insertion sort
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *sorted, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (curr = (*list)->next; curr != NULL; curr = tmp) {
        tmp = curr->next;
        sorted = curr->prev;

        while (sorted != NULL && sorted->n > curr->n) {
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
/*
**
 * swap_nodes - function to swap the nodes of the list
 * @h: a pointer to the head of the doubly-linked list.
 * @n1: a pointer to the first node to swap.
 * @n2: The second node to swap.
 *
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
*/
