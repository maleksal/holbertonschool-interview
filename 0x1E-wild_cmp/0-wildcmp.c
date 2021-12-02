#include "holberton.h"

/**
 * wildcmp - compares two strings.
 * @s1: string 1
 * @s2: string 2 can contain the special character *
 * Return: 1 if strings can be identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
return (1);

if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));

if (*s2 == '*')
{
if (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2))
return (1);
else
return (0);
}
return (0);
}
