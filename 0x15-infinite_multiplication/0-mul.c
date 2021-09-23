
#include "holberton.h"
/**
 * _isnumber - checks if number
 *
 * @s: string
 *
 * Return: 1 if number, 0 if not
 */
int _isnumber(char *s)
{
int i, digit = 0;

for (i = 0; s[i] && !digit; i++)
{
if (s[i] < '0' || s[i] > '9')
digit++;
}
return (digit);
}


/**
 * intialize_mem -initialize
 *
 * @n: # of bytes
 *
 * Return: pointer
 */
char *intialize_mem(unsigned int n)
{
unsigned int i;
char *pointer;

pointer = malloc(n + 1);
if (pointer == 0)
return (0);
for (i = 0; i < n; i++)
pointer[i] = '0';
pointer[i] = '\0';
return (pointer);
}

/**
 * main - multiplies two numbers
 *
 * @argc: # of cmd line args
 * @argv: cmd line args
 * Return: No return
 */
int main(int argc, char **argv)
{
int i, jj;
int LL1, LL2;
int lFull;
int multiply;
int add_n;
int ten;
int ten2;
int tl;
int zer = 0;
char *res;
if (argc != 3 || _isnumber(argv[1]) != 0 || _isnumber(argv[2]) != 0)
printf("Error\n"), exit(98);
if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
printf("0\n"), exit(0);
LL1 = strlen(argv[1]), LL2 = strlen(argv[2]);
lFull = LL1 + LL2;
res = intialize_mem(lFull);
if (res == 0)
printf("Error\n"), exit(98);
for (i = LL2 - 1; i >= 0; i--)
{
ten = 0, ten2 = 0;
for (jj = LL1 - 1; jj >= 0; jj--)
{
tl = i + jj + 1;
multiply = (argv[1][jj] - '0') * (argv[2][i] - '0') + ten;
ten = multiply / 10;
add_n = (res[tl] - '0') + (multiply % 10) + ten2;
ten2 = add_n / 10;
res[tl] = (add_n % 10) + '0';
}
res[tl - 1] = (ten + ten2)+'0';
}
if (res[0] != '0')
zer = 1;
for (; zer < lFull; zer++)
printf("%c", res[zer]);
printf("\n");
free(res);
return (0);
}
