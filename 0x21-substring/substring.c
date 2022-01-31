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
int _length, w_length, tmp_var_a, tmp_var_b = 0, k;
int *element, *found;
if (!s)
return (NULL);
*n = 0, _length = strlen(s), w_length = strlen(words[0]);
found = malloc(nb_words * sizeof(int));
element = malloc(_length * sizeof(int));
while (tmp_var_b <= _length - nb_words * w_length)
{
tmp_var_a = 0;
while (tmp_var_a < nb_words)
{
found[tmp_var_a] = 0;
tmp_var_a++;
}
tmp_var_a = 0;
while (tmp_var_a < nb_words)
{
for (k = 0; k < nb_words; k++)
{
if (found[k] == 0 &&
strncmp(s + tmp_var_b + tmp_var_a *w_length, words[k], w_length) == 0)
{
found[k] = 1;
break;
}
}
if (k != nb_words)
break;
tmp_var_a++;
}
if (tmp_var_a == nb_words)
element[(*n)++] = tmp_var_b;
tmp_var_b++;
}
free(found);
return (element);
}
