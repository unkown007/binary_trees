#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int size_l, size_r;

	if (tree == NULL)
		return (0);
	size_l = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
	size_r = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
	return (size_l - size_r);
}
