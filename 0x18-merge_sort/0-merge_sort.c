#include "sort.h"

/**
 * merge - merge the sublist into the list
 * @start: start index
 * @mid: middle index
 * @end: end index
 * @array: array to be sorted
 * @temp_array: temp array that holds values
 *
 * Return: void
 */
void merge(int *array, int *temp_array, size_t start, size_t mid, size_t end)
{
size_t i = start;
size_t j = mid;
size_t k = start;
size_t idx;

printf("Merging...\n");
printf("[left]: ");
print_array(temp_array + start, mid - start);
printf("[right]: ");
print_array(temp_array + mid, end - mid);

while (i < mid && j < end && k < end)
{
if (temp_array[i] <= temp_array[j])
array[k] = temp_array[i++];
else
array[k] = temp_array[j++];
k++;
}
while (i < mid)
array[k++] = temp_array[i++];

while (j < end)
array[k++] = temp_array[j++];

for (idx = start; idx < end; idx++)
temp_array[idx] = array[idx];

printf("[Done]: ");
print_array(array + start, end - start);
}

/**
 * acctual_mergesort - split array recursively and merge them back
 * @start: start
 * @end: end
 * @array: array to be sorted
 * @temp_array: temp array hold values
 *
 * Return: void
 */

void acctual_mergesort(int *array, int *temp_array, size_t start, size_t end)
{
size_t mid;

if (end - start < 2)
return;

mid = (start + end) / 2;
acctual_mergesort(array, temp_array, start, mid);
acctual_mergesort(array, temp_array, mid, end);
merge(array, temp_array, start, mid, end);
}

/**
 * intcpy - Generate a copy of a src array.
 * @src: src array
 * @len: size of the array
 *
 * Return: void
 */
int *intcpy(int const *src, size_t len)
{
size_t i;
int *p = malloc(len * sizeof(int));

for (i = 0; i < len; i++)
{
p[i] = src[i];
}
return (p);
}

/**
 * merge_sort - sorts an array of integers
 * @array: array
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
int *temp_array;

temp_array = intcpy(array, size);
acctual_mergesort(array, temp_array, 0, size);
free(temp_array);
}
