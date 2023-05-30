#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: integer value to store in the new node
 *
 * Return: pointer to the created node or NULL on failure or if parrent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (parent == NULL)
		return (NULL);
	tmp = parent->right;
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);
	parent->right = node;
	if (tmp != NULL)
	{
		node->right = tmp;
		tmp->parent = node;
	}
	return (node);
}
