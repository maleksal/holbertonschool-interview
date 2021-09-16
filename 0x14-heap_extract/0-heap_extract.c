
#include "binary_trees.h"

/**
* bin_tree_hight - measure height of binary tree
* @tree: tree pointer
* Return: height
*/

int bin_tree_hight(heap_t *tree)
{
size_t left, right;

if (!tree)
return (0);
if (!tree->left && !tree->right)
return (0);

right = bin_tree_hight(tree->right) + 1;
left = bin_tree_hight(tree->left) + 1;

if (left > right)
return (left);
else
return (right);
}

/**
* last_node - returns last node
* @tree: pointer
* @height: tree height
* @current: current height
* Return: node node in the heap
*/

heap_t *last_node(heap_t *tree, int height, int current)
{
heap_t *temp;

if (current >= (height - 1))
{
if (tree->right != NULL)
return (tree->right);
return (tree->left);
}

temp = last_node(tree->right, height, current + 1);
if (temp != NULL)
return (temp);
return (last_node(tree->left, height, current + 1));
}

/**
* heapify - heapify max binary heap
* @node: binary tree
*/

void heapify(heap_t *node)
{
int value;
heap_t *temp_var1, *temp_var2;

if (!node)
return;

temp_var1 = node;

while (1)
{
if (!temp_var1->left)
break;

if (!temp_var1->right)
temp_var2 = temp_var1->left;

else
{
if (temp_var1->left->n > temp_var1->right->n)
temp_var2 = temp_var1->left;
else
temp_var2 = temp_var1->right;
}

if (temp_var1->n > temp_var2->n)
break;

value = temp_var1->n;
temp_var1->n = temp_var2->n;
temp_var2->n = value;
temp_var1 = temp_var2;
}
}


/**
* heap_extract - extracts root node of max binary heap
* @root: pointer to root node
* Return: 0 on fail; otherwise value of root
*/

int heap_extract(heap_t **root)
{
heap_t *temp;
int tree_height, value;

if (root == NULL || *root == NULL)
return (0);

value = (*root)->n;
temp = *root;
tree_height = bin_tree_hight(*root) + 1;

if (tree_height == 1)
{
temp = *root;
*root = NULL;
free(temp);
return (value);
}
temp = last_node(*root, tree_height, 1);
(*root)->n = temp->n;

if (temp->parent->right == temp)
temp->parent->right = NULL;
else if (temp->parent->left == temp)
temp->parent->left = NULL;

free(temp);
heapify((*root));

return (value);
}
