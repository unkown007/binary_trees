#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: pointer to the node
 *
 * Return: pointer to uncle node, NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent->parent->left &&
			(node->parent->parent->left->left == node ||
			node->parent->parent->left->right == node))
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
