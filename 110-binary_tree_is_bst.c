#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * isBST - checks if the tree is a valid BST
 *
 * @tree: pointer to the root of the tree
 * @min: smallest node visited
 * @max: largest node visited
 *
 * Return: 1 if BST, 0 otherwise
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		return (isBST(tree->left, min, tree->n) &&
				isBST(tree->right, tree->n, max));
	}
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
	return (isBST(tree, INT_MIN, INT_MAX));
}
