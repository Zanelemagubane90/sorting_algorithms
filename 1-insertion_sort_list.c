#include "sort.h"

/**
 * exchnage_nodes - exchnage two nodes in a listint_t doubly-linked list.
 * @hdd: A indicator  to the head of the doubly-linked list.
 * @first: A indicator  to the first node to exchnage.
 * @second: The second node to exchnage.
 */

void exchnage_nodes(listint_t **hdd, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *first;
	second->prev = (*first)->prev;
	second->next = *first;
	if ((*first)->prev != NULL)
		(*first)->prev->next = second;
	else
		*hdd = second;
	(*first)->prev = second;
	*first = second->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A indicator  to the head of a doubly-linked list of integers.
 * Description: This Prints the list after each exchnage.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *inter, *inset, *impermanent;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (inter = (*list)->next; inter != NULL; inter = impermanent)
	{
		impermanent = inter->next;
		inset = inter->prev;
		while (inset != NULL && inter->n < inset->n)
		{
			exchnage_nodes(list, &inset, inter);
			print_list((const listint_t *)*list);
		}
	}
}
