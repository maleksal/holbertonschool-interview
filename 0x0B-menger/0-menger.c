
#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
 * menger - draw a 2D Menger Sponge
 *
 * @level: level of the spenge
 *
 * Return: void
 */
void menger(int level)
{
int index, j, max;

if (level < 0)
return;

for (index = 0, max = pow(3, level); index < max; index++)
{
for (j = 0; j < max; j++)
printf("%c", check_what_to_print(index, j));
printf("\n");
}
}

/**
 * check_what_to_print - Checks condition and return correct char
 * @col: row
 * @row: column
 *
 * Return: ' ' OR '#'
 */

int check_what_to_print(int col, int row)
{
for (; col && row; col /= 3, row /= 3)
{
if (col % 3 == 1 && row % 3 == 1)
return (' ');
}
return ('#');
}
