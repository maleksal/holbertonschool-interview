#include "sort.h"

/**
 * radix_sort - Sorts an array of using the LSD radix sort algorithm
 * @array: Array.
 * @size: Size of arrray.
 * Return: nothing
 */

void radix_sort(int *array, size_t size)
{
int max_n, n, i, *resulting_array;
int count_array[10] = {0};

if (!array || size <= 1)
return;

/* Find max number */
max_n = max(array, size);

for (n = 1; max_n / n > 0; n *= 10)
{
memset(count_array, 0, 10 * sizeof(int));
resulting_array = malloc(sizeof(int) * (int)size);
if (!resulting_array)
return;

for (i = 0; i < (int)size; i++)
count_array[(array[i] / n) % 10]++;

for (i = 1; i < 10; i++)
count_array[i] += count_array[i - 1];

for (i = (int)size - 1; i >= 0; i--)
{
resulting_array[count_array[(array[i] / n) % 10] - 1] = array[i];
count_array[(array[i] / n) % 10]--;
}

for (i = 0; i < (int)size; i++)
array[i] = resulting_array[i];
free(resulting_array);

print_array(array, size);
}
}

/**
 * max - get max n from array of intergers
 * @array: array to search
 * @size: size of array
 * Return: max n
 */
int max(int *array, size_t size)
{
size_t i = 0;
int max_number = 0;

while (i < size)
{
if (array[i] > max_number)
max_number = array[i];
i++;
}
return (max_number);
}
