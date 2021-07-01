#include "binary_trees.h"

/**
 * heap_insert - Inserts a new Node
 * @root: root node
 * @value: value to insert
 * Return: The new allocated node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!(*root))
	{
		*root = new_node;
		return (new_node);
	}
}
