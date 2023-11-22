#include "sort.h"

void exchange_ints(int *first, int *second);
int hoare_partition(int *ary_int, size_t siz, int left, int right);
void hoare_sort(int *ary_int, size_t siz, int left, int right);
void quick_sort_hoare(int *ary_int, size_t siz);

/**
 * exchange_ints - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */

void exchange_ints(int *first, int *second)
{
	int impermanent;

	impermanent = *first;
	*first = *second;
	*second = impermanent;
}

/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @ary_int: The array of integers.
 * @siz: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */

int hoare_partition(int *ary_int, size_t siz, int left, int right)
{
	int pivot, above, below;

	pivot = ary_int[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (ary_int[above] < pivot);
		do {
			below--;
		} while (ary_int[below] > pivot);

		if (above < below)
		{
			exchange_ints(ary_int + above, ary_int + below);
			print_array(ary_int, siz);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @ary_int: An ary_int of integers to sort.
 * @siz: The siz of the ary_int.
 * @left: The starting index of the ary_int partition to order.
 * @right: The ending index of the ary_int partition to order.
 * Description: Uses the Hoare partition scheme.
 */

void hoare_sort(int *ary_int, size_t siz, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(ary_int, siz, left, right);
		hoare_sort(ary_int, siz, left, part - 1);
		hoare_sort(ary_int, siz, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an ary_int of integers in ascending
 *                    order using the quicksort algorithm.
 * @ary_int: An array of integers.
 * @siz: The siz of the array
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */

void quick_sort_hoare(int *ary_int, size_t siz)
{
	if (ary_int == NULL || siz < 2)
		return;

	hoare_sort(ary_int, siz, 0, siz - 1);
}