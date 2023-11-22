#include "sort.h"

void blend_subarr(int *sb_ary, int *bff_r, size_t fore_r, size_t midd_r,
		size_t rear_r);
void blend_sort_recursive(int *sb_ary, int *bff_r, size_t fore_r, size_t rear_r);
void merge_sort(int *array, size_t siz);

/**
 * blend_subarr - Sort a subarray of integers.
 * @sb_ary: A subarray of an array of integers to sort.
 * @bff_r: A buffer to store the sorted subarray.
 * @fore_r: A front index of the array.
 * @midd_r: A middle index of the array.
 * @rear_r: A rear index of the array.
 */

void blend_subarr(int *sb_ary, int *bff_r, size_t fore_r, size_t midd_r,
		size_t rear_r)
{
	size_t z, x, y = 0;

	printf("Merging...\n[left]: ");
	print_array(sb_ary + fore_r, midd_r - fore_r);

	printf("[right]: ");
	print_array(sb_ary + midd_r, rear_r - midd_r);

	for (z = fore_r, x = midd_r; z < midd_r && x < rear_r; y++)
		bff_r[y] = (sb_ary[z] < sb_ary[x]) ? sb_ary[z++] : sb_ary[x++];
	for (; z < midd_r; z++)
		bff_r[y++] = sb_ary[z];
	for (; x < rear_r; x++)
		bff_r[y++] = sb_ary[x];
	for (z = fore_r, y = 0; z < rear_r; z++)
		sb_ary[z] = bff_r[y++];

	printf("[Done]: ");
	print_array(sb_ary + fore_r, rear_r - fore_r);
}

/**
 * blend_sort_recursive - Implement the merge sort algorithm through recursion.
 * @sb_ary: A subarray of an array of integers to sort.
 * @bff_r: A buffer to store the sorted result.
 * @fore_r: A front index of the subarray.
 * @rear_r: A rear_r index of the subarray.
 */

void blend_sort_recursive(int *sb_ary, int *bff_r, size_t fore_r, size_t rear_r)
{
	size_t midd_r;

	if (rear_r - fore_r > 1)
	{
		midd_r = fore_r + (rear_r - fore_r) / 2;
		blend_sort_recursive(sb_ary, bff_r, fore_r, midd_r);
		blend_sort_recursive(sb_ary, bff_r, midd_r, rear_r);
		blend_subarr(sb_ary, bff_r, fore_r, midd_r, rear_r);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @ary_int: An array of integers.
 * @siz: A size of the array.
 * Description: Implements the top-DESCENDING merge sort algorithm.
 */

void merge_sort(int *ary_int, size_t siz)
{
	int *bff_r;

	if (ary_int == NULL || siz < 2)
		return;

	bff_r = malloc(sizeof(int) * siz);
	if (bff_r == NULL)
		return;

	blend_sort_recursive(ary_int, bff_r, 0, siz);

	free(bff_r);
}