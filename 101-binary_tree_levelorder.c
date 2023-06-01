#include <stdlib.h>
#include "binary_trees.h"

/**
 * height - measures the height of the tree
 *
 * @tree: pointer to the tree
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
 * current_level - print the current level of the tree
 *
 * @tree: pointer to the tree
 * @func: pointer to function to call each node
 * @level: level of the tree
 */
void current_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		current_level(tree->left, func, level - 1);
		current_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 *
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h, i;

	if (!tree || !func)
		return;
	h =  height(tree);
	for (i = 1; i <= h + 1; i++)
		current_level(tree, func, i);
}
