#include "lists.h"


/**
 * insert_node - inserts a new node in a singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	/* initialize variables */
	listint_t *n_pointer = *head;
	listint_t *new_node;

	if (!*head)
		return (add_nodeint_end(head, number));

	/* create new node */
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;

	/* insert at 0*/
	if (n_pointer->n > number)
	{
		*head = new_node;
		new_node->next = n_pointer;
		return (new_node);
	}

	while (n_pointer && n_pointer->next)
	{

		if (n_pointer->next->n > number)
			break;

		/* move next node */
		n_pointer = n_pointer->next;
	}

	new_node->next = n_pointer->next;
	n_pointer->next = new_node;
	return (new_node);

}
