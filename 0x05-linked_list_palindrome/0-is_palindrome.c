# include "lists.h"


/**
 * iterater_list - iterrate over singly linked list.
 * @list: pointer to list.
 * @length: pointer to variable length
 * @SIZE: size of list.
 * @head: pointer to linked list.
 */
void iterater_list(int *list, int *length, int SIZE, listint_t *head)
{
	int count = 0;
	listint_t *pointer = head;

	while (pointer != NULL)
	{
		if (count > SIZE)
		{
			SIZE = (SIZE + 20);
			list = realloc(list, SIZE);
		}
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
	int *list;
	int SIZE = 20;
	int length = 0;
	int n = 0;

	if (!*head)
		return (1);

	/* get elements */
	list = malloc(sizeof(int) * SIZE);
	memset(list, 0, sizeof(*list));
	iterater_list(list, &length, SIZE, *head);
	while (n < (length / 2))
	{
		if (list[n] != list[abs(n - length) - 1])
		{
			free(list);
			return (0);
		}
		n = n + 1;
	}
	free(list);
	return (1);
}

