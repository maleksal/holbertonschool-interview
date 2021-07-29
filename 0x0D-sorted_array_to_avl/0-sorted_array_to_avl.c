#include "binary_trees.h"

/**
 * build_avl_node - creates the avl array
 * @array: a pointer to the first element.
 * @parr: a pointer to the parent element.
 * @first: the number of the first element.
 * @last: the number of the last element.
 *
 * Return: a pointer to the root node.
 */

avl_t *build_avl_node(int *array, avl_t *parr, int first, int last)
{
avl_t *node = NULL;

int mid = (first + last) / 2;

if (first > last)
return (NULL);

node = (struct binary_tree_s *)malloc(sizeof(struct binary_tree_s));

if (!node)
return (NULL);

node->n = array[mid];
node->parent = parr;
node->left = NULL;
node->right = NULL;

if (mid != first)
node->left = build_avl_node(array, node, first, mid - 1);

if (mid != last)
node->right = build_avl_node(array, node, mid + 1, last);

return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree.
 * @array: a pointer to the first element.
 * @size: the number of element in the array.
 *
 * Return: a pointer to the root node.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *root = NULL;

if (array && size)
{
root = build_avl_node(array, NULL, 0, (int)size - 1);
return (root);
}
return (NULL);
}
