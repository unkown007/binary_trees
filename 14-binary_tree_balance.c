#include <stdlib.h>
#include "binary_trees.h"

/**
 * height - measures the hight of a binary tree
 *
 * @tree: pointer to the tree
 *
 * Return: height of the tree, or 0 if the tree is NULL
 */
int height(binary_tree_t *tree)
{
	int size_l, size_r;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	size_l = tree->left ? 1 + height(tree->left) : 0;
	size_r = tree->right ? 1 + height(tree->right) : 0;
	return ((size_l > size_r ? size_l : size_r));
}

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
	if (!tree->left && !tree->right)
		return (0);
	size_l = height(tree->left);
	size_r = height(tree->right);
	return (size_l - size_r);
}
