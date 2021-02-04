#include "lists.h"

/**
 * check_cycle - check for cycle in doubly linked list
 * @list: pointer to head of dl
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *forward, *backword;

	if (list)
	{
		backword = list;
		forward = backword->next;
		while (backword && forward)
		{
			backword = backword->next;
			forward = forward->next;
			if (backword == forward)
				return (1);
		}
		return (0);
	}
	return (0);
}
