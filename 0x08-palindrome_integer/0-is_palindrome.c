#include "palindrome.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - Checks whether or not a given unsigned
 *                integer is a palindrome.
 * @n: is the number to be checked
 * Return:  1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
unsigned long tmp = n, reversed = 0;

while (tmp > 0)
{
reversed *= 10;
reversed += tmp % 10;
tmp = tmp / 10;
}

if (n == reversed)
return (1);
else
return (0);
}
