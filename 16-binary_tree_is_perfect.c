#include <stdlib.h>
#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if the tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int size_l, size_r;

	if (tree == NULL)
		return (0);
	size_l = tree->left ? 1 + height(tree->left) : 0;
	size_r = tree->right ? 1 + height(tree->right) : 0;
	return (size_l > size_r ? size_l : size_r);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if ((!tree->left && !tree->right) ||
			((binary_tree_is_perfect(tree->left) == 1 &&
			  binary_tree_is_perfect(tree->left)) &&
			 height(tree->left) == height(tree->right)))
		return (1);
	return (0);
}
