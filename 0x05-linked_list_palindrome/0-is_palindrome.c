# include "lists.h"


/**
 * iterater_list - iterrate over singly linked list.
 * @list: pointer to list.
 * @length: pointer to variable length
 * @head: pointer to linked list.
 */
void iterater_list(int *list, int *length, listint_t *head)
{
	int count = 0;
	listint_t *pointer = head;

	while (pointer != NULL)
	{
		list[count] = pointer->n;
		count++;
		pointer = pointer->next;

	}
	*length = count;
}


/**
 * is_palindrome - check if a singly linked list is palindrome
 * or not, an empty list is also considered a palindrome.
 *
 * @head: pointer to singly linked list.
 * Return: 0 if true, else 1
 */
int is_palindrome(listint_t **head)
{
	int list[200000];
	int length = 0;
	int n = 0;

	if (!*head)
		return (1);

	/* get elements */
	iterater_list(list, &length, *head);
	while (n < (length / 2))
	{
		if (list[n] != list[abs(n - length) - 1])
		{
			return (0);
		}
		n = n + 1;
	}
	return (1);
}

