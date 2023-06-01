#include <stdlib.h>
#include "binary_trees.h"

/**
 * nNodes - measures the number of nodes of the tree
 *
 * @tree: pointer to the tree
 *
 * Return: number of nodes of the tree, or 0 if the tree is NULL
 */
int nNodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + nNodes(tree->left) + nNodes(tree->right));
}

/**
 * isComplete - checks if the tree if complete or not
 *
 * @tree: pointer to the tree
 * @index: index of tree node
 * @nodes: number of nodes
 *
 * Return: 1 if the level is full, 0 otherwise
 */
int isComplete(const binary_tree_t *tree, int index, int nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= nodes)
		return (0);
	return (isComplete(tree->left, (index * 2) + 1, nodes) &&
			isComplete(tree->right, (index * 2) + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: pointer to the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int n;

	n = nNodes(tree);
	return (isComplete(tree, 0, n));
}
