#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * getMax - get the maximum value of the binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: maximum value, or 0 otherwise
 */
int getMax(binary_tree_t *tree)
{
	int max_l, max_r, value;

	if (tree == NULL)
		return (INT_MIN);
	max_l = getMax(tree->left);
	max_r = getMax(tree->right);
	if (max_l > max_r)
		value = max_l;
	else
		value = max_r;
	if (value < tree->n)
		value = tree->n;
	return (value);
}

/**
 * getMin - get the minimum value of the tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: minimum value, 0 otherwise
 */
int getMin(binary_tree_t *tree)
{
	int min_l, min_r, value;

	if (tree == NULL)
		return (INT_MAX);
	min_l = getMin(tree->left);
	min_r = getMin(tree->right);
	if (min_l > min_r)
		value = min_r;
	else
		value = min_l;
	if (value > tree->n)
		value = tree->n;
	return (value);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int min_r, max_l;

	if (tree == NULL)
		return (0);
	max_l = getMax(tree->left);
	min_r = getMin(tree->right);
	if (max_l > tree->n)
		return (0);
	if (min_r < tree->n)
		return (0);
	return (1);
}
