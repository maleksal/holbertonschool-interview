#include "search_algos.h"

/**
 * print_array - prints an array
 * @left: first el of the array
 * @right: last el of the array
 * @array: pointer to aim to the first element
 **/
void print_array(int *array, size_t left, size_t right)
{
printf("Searching in array: ");
for ( ; left < right; left++)
{
printf("%i, ", array[left]);
}
printf("%i\n", array[left]);
}

/**
 * advanced_binary - binary search function.
 * @array: pointer to the first element.
 * @size:  n of element in array.
 * @value: value to search for.
 *
 * Return: Index, otherwise return NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
size_t c_index, start_i = 0;
size_t end_i = size - 1;

if (!array)
return (-1);

for ( ; start_i <= end_i ; )
{
print_array(array, start_i, end_i);

c_index = (start_i + end_i) / 2;

if (array[c_index] == value && array[c_index - 1] != value)

return (c_index);

else if (array[c_index] < value)

start_i = c_index + 1;

else

end_i = c_index;
}
return (-1);
}
