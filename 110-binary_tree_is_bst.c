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
 * isBST - checks if the tree is a valid BST
 *
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if BST, 0 otherwise
 */
int isBST(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (tree->left && getMax(tree->left) > tree->n)
		return (0);
	if (tree->right && getMin(tree->right) < tree->n)
		return (0);
	if (!isBST(tree->left) || !isBST(tree->right))
		return (0);
	return (1);
}

/**
 * exists - check if a value exists in a tree
 *
 * @tree: pointer to the tree
 * @n: integer value
 *
 * Return: 1 if exists, 0 otherwise
 */
int exists(const binary_tree_t *tree, int n)
{
	if (tree == NULL)
		return (0);
	if (tree->n == n)
		return (1);
	return (exists(tree->left, n) || exists(tree->right, n));
}

/**
 * duplicated - check if there is duplicated values in the tree
 *
 * @tree: pointer to the tree
 *
 * Return: 1 if duplicated values exists, 0 otherwise
 */
int duplicated(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (exists(tree->left, tree->n) || exists(tree->right, tree->n))
		return (1);
	return (duplicated(tree->left) || duplicated(tree->right));
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
	if (tree == NULL)
		return (0);
	if (duplicated(tree))
		return (0);
	return (isBST(tree));
}
