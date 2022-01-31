#include "substring.h"


/**
* find_substring - function that finds all the possible
*   substrings containing a list of words, within a given string.
* @s: is the string to scan
* @words: is the array of words all substrings must be a
*       concatenation arrangement of
* @nb_words: is the number of elements in the array words
* @n: holds the address at which to store the
*        number of elements in the returned array.
* Return: allocated array, storing each index
*   in s at which a substring was found, else NULL
*/


int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int this_idx, c, l, wl, str, i, j, k;
int *matching, *array;

if (s && words && n && nb_words != 0)
{
l = strlen(s);
wl = strlen(words[0]);
array = malloc(l *sizeof(int));
matching = malloc(nb_words * sizeof(int));
if (array && matching)
{
for (i = c = 0; i <= l - nb_words * wl; i++)
{
memset(matching, 0, nb_words * sizeof(int));
for (j = 0; j < nb_words; j++)
{
for (k = 0; k < nb_words; k++)
{
this_idx = i + j * wl;
str = strncmp(s + this_idx, *(words + k), wl);
if (!*(matching + k) && !str)
{
*(matching + k) = 1;
break;
}
}
if (k == nb_words)
break;
}
if (j == nb_words)
*(array + c) = i, c += 1;
}
}
else
return (NULL);
free(matching);
*n = c;
return (array);
}
else
return (NULL); }
