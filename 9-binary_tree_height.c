#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root of the tree
 *
 * Return: size of tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t size_l, size_r;

	if (tree == NULL)
		return (0);
	size_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	size_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return ((size_l > size_r) ? size_l : size_r);
}
