#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"


/**
 * slide_line - slides and merges an array of integers
 * @line: array
 * @size: size of array
 * @direction: direction
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
int ri = size - 1, rj, rprev = 0, rcurr;

if ((direction != 0 && direction != 1) || ((line == NULL || size < 1)))
return (0);

if (direction == 1)
{
for (rj = size - 1; rj >= 0; rj--)
{
rcurr = line[rj];
if (!rcurr)
continue;
if (!rprev)
rprev = rcurr;
else if (rprev == rcurr)
{
line[ri--] = rcurr << 1;
rprev = 0;
}
else
{
line[ri--] = rprev;
rprev = rcurr;
}
}
if (rprev)
line[ri--] = rprev;
while (ri >= 0)
line[ri--] = 0;
}

if (direction == 0)
slide_left(line, size);
return (1);
}

/**
 * slide_left - slide to left
 * @line: input array
 * @size: size of the int array
 */
void slide_left(int *line, size_t size)
{
int li = 0, lj, lprev = 0, lcurr;
for (lj = 0; lj < (int)size; lj++)
{
lcurr = line[lj];
if (!lcurr)
continue;
if (!lprev)
lprev = lcurr;
else if (lprev == lcurr)
{
line[li++] = lcurr << 1;
lprev = 0;
}
else
{
line[li++] = lprev;
lprev = lcurr;
}
}
if (lprev)
line[li++] = lprev;
while (li < (int)size)
line[li++] = 0;
}
