#include <stdlib.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + height(tree->left) : 1;
	r = tree->right ? 1 + height(tree->right) : 1;
	return ((l > r ? l : r));
}

/**
 * isAVL - checks if a binary tree is a valid AVL Tree
 *
 * @tree: pointer to the root node of the tree
 * @min: smallest visited node
 * @max: largest visited node
 *
 * Return: 1 if the tree is a BST, 0 otherwise
 */
int isAVL(const binary_tree_t *tree, int min, int max)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < min || tree->n > max)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (isAVL(tree->left, min, tree->n) &&
				isAVL(tree->right, tree->n, max));
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
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if treeis a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (duplicated(tree))
		return (0);
	return (isAVL(tree, INT_MIN, INT_MAX));
}
