#include "sort.h"

void exch_node_ahead(listint_t **list, listint_t **s_cut, listint_t **grip);
void exch_node_behind(listint_t **list, listint_t **s_cut, listint_t **grip);
void cocktail_sort_list(listint_t **list);

/**
 * exch_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @s_cut: A pointer to the scut of the doubly-linked list.
 * @grip: A pointer to the current swapping node of the cocktail grip algo.
 */

void exch_node_ahead(listint_t **list, listint_t **s_cut, listint_t **grip)
{
	listint_t *gap = (*grip)->next;

	if ((*grip)->prev != NULL)
		(*grip)->prev->next = gap;
	else
		*list = gap;
	gap->prev = (*grip)->prev;
	(*grip)->next = gap->next;
	if (gap->next != NULL)
		gap->next->prev = *grip;
	else
		*s_cut = *grip;
	(*grip)->prev = gap;
	gap->next = *grip;
	*grip = gap;
}

/**
 * exch_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @s_cut: A pointer to the scut of the doubly-linked list.
 * @grip: A pointer to the current swapping node of the cocktail shaker algo.
 */

void exch_node_behind(listint_t **list, listint_t **s_cut, listint_t **grip)
{
	listint_t *gap = (*grip)->prev;

	if ((*grip)->next != NULL)
		(*grip)->next->prev = gap;
	else
		*s_cut = gap;
	gap->next = (*grip)->next;
	(*grip)->prev = gap->prev;
	if (gap->prev != NULL)
		gap->prev->next = *grip;
	else
		*list = *grip;
	(*grip)->next = gap;
	gap->prev = *grip;
	*grip = gap;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *s_cut, *grip;
	bool shaken_no_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (s_cut = *list; s_cut->next != NULL;)
		s_cut = s_cut->next;

	while (shaken_no_stirred == false)
	{
		shaken_no_stirred = true;
		for (grip = *list; grip != s_cut; grip = grip->next)
		{
			if (grip->n > grip->next->n)
			{
				exch_node_ahead(list, &s_cut, &grip);
				print_list((const listint_t *)*list);
				shaken_no_stirred = false;
			}
		}
		for (grip = grip->prev; grip != *list;
				grip = grip->prev)
		{
			if (grip->n < grip->prev->n)
			{
				exch_node_behind(list, &s_cut, &grip);
				print_list((const listint_t *)*list);
				shaken_no_stirred = false;
			}
		}
	}
}