#include "palindrome.h"


/**
 * calculate_length - get length of integer
 * @n: is the number to be checked
 * Return: length of integer
 */

int calculate_length(unsigned long n)
{
int length;
unsigned long tmp = n;

while (tmp != 0)
{
tmp /= 10;
length++;
}
return (length);
}


/**
 * is_palindrome - Checks whether or not a given unsigned
 *                integer is a palindrome.
 * @n: is the number to be checked
 * Return:  1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{

/* Get length of a number */
int length = calculate_length(n);
int array[length];
int idx = 0;

unsigned long tmp = n;
unsigned long reversed_int;

/* split numbers and add them to array */
while (tmp != 0)
{
array[idx] = tmp % 10;
tmp /= 10;
idx++;
}

/* reset idx */
idx = 0;

/* turn array of numbers into an int */
while (idx < length)
{
reversed_int = 10 * reversed_int + array[idx];
idx++;
}

if (reversed_int == n)
{
return (1);
}
return (0);
}
