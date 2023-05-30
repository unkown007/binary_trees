#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree node
 *
 * @parent: pointer to the parrent node of the node to create
 * @value: integer value to put in the new node
 *
 * Return: return a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tmp;

	tmp = malloc(sizeof(binary_tree_t));
	if (tmp == NULL)
		return (NULL);
	tmp->n = value;
	tmp->parent = tmp->left = tmp->right = NULL;
	if (parent)
		tmp->parent = parent;
	return (tmp);
}
