#include "sort.h"

void exchange_ints(int *first, int *second);
int l_partition(int *array, size_t size, int left, int right);
void l_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * l_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pvt).
 * @ints_ary: The array of integers.
 * @siz: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */

int l_partition(int *ints_ary, size_t siz, int left, int right)
{
	int *pvt, over, under;

	pvt = ints_ary + right;
	for (over = under = left; under < right; under++)
	{
		if (ints_ary[under] < *pvt)
		{
			if (over < under)
			{
				exchange_ints(ints_ary + under, ints_ary + over);
				print_array(ints_ary, siz);
			}
			over++;
		}
	}

	if (ints_ary[over] > *pvt)
	{
		exchange_ints(ints_ary + over, pvt);
		print_array(ints_ary, siz);
	}

	return (over);
}

/**
 * l_sort - Implement the quicksort algorithm through recursion.
 * @ints_ary: An array of integers to sort.
 * @siz: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Lomuto partition scheme.
 */

void l_sort(int *ints_ary, size_t siz, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = l_partition(ints_ary, siz, left, right);
		l_sort(ints_ary, siz, left, part - 1);
		l_sort(ints_ary, siz, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @ints_ary: An array of integers.
 * @siz: The size of the array.
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *ints_ary, size_t siz)
{
	if (ints_ary == NULL || siz < 2)
		return;

	l_sort(ints_ary, siz, 0, siz - 1);
}
