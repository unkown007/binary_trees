#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: pointer to the node insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp, *node;

	if (parent == NULL)
		return (NULL);
	tmp = parent->left;
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);
	parent->left = node;
	if (tmp != NULL)
	{
		node->left = tmp;
		tmp->parent = node;
	}
	return (node);
}
