#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at leats 1 child in a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: number of nodes with at least 1 child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return ((tree->left || tree->right ? 1 : 0) +
			binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
}
