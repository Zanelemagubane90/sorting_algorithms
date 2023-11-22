#include "sort.h"

void exchange_ints(int *first, int *second);
void bitonic_merge(int *ary_int, size_t siz, size_t dawn, size_t sequ,
		char flow);
void bitonic_seq(int *ary_int, size_t siz, size_t dawn, size_t sequ, char flow);
void bitonic_sort(int *ary_int, size_t siz);

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
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @ary_int: An array of integers.
 * @siz: The size of the array.
 * @dawn: The starting index of the sequence in array to sort.
 * @sequ: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */

void bitonic_merge(int *ary_int, size_t siz, size_t dawn, size_t sequ,
		char flow)
{
	size_t i, jump = sequ / 2;

	if (sequ > 1)
	{
		for (i = dawn; i < dawn + jump; i++)
		{
			if ((flow == ASCENDING && ary_int[i] > ary_int[i + jump]) ||
			    (flow == DESCENDING && ary_int[i] < ary_int[i + jump]))
				exchange_ints(ary_int + i, ary_int + i + jump);
		}
		bitonic_merge(ary_int, siz, dawn, jump, flow);
		bitonic_merge(ary_int, siz, dawn + jump, jump, flow);
	}
}

/**
 * bitonic_sequ - Convert an array of integers into a bitonic sequence.
 * @ary_int: An array of integers.
 * @siz: The size of the array.
 * @dawn: The starting index of a block of the building bitonic sequence.
 * @sequ: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */

void bitonic_seq(int *ary_int, size_t siz, size_t dawn, size_t sequ, char flow)
{
	size_t cut = sequ / 2;
	char *str = (flow == ASCENDING) ? "ASCENDING" : "DESCENDING";

	if (sequ > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequ, siz, str);
		print_array(ary_int + dawn, sequ);

		bitonic_seq(ary_int, siz, dawn, cut, ASCENDING);
		bitonic_seq(ary_int, siz, dawn + cut, cut, DESCENDING);
		bitonic_merge(ary_int, siz, dawn, sequ, flow);

		printf("Result [%lu/%lu] (%s):\n", sequ, siz, str);
		print_array(ary_int + dawn, sequ);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @ary_int: An array of integers.
 * @siz: The size of the array.
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */

void bitonic_sort(int *ary_int, size_t siz)
{
	if (ary_int == NULL || siz < 2)
		return;

	bitonic_seq(ary_int, siz, 0, siz, ASCENDING);
}