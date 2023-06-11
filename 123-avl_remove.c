#include <stdlib.h>
#include "binary_trees.h"

/**
 * minValue - computes the lowest value of the tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the lowest value node, or NULL on failure
 */
avl_t *minValue(avl_t *tree)
{
	while (tree && tree->left)
		tree = tree->left;
	return (tree);
}

/**
 * balance_t - performe the balance in avl tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root
 */
avl_t *balance_t(avl_t *tree)
{
	avl_t *node = tree;
	int bfactor;

	bfactor = binary_tree_balance(tree);
	if (bfactor > 1)
	{
		if (tree->left->right && !tree->left->left)
			binary_tree_rotate_left(tree->left);
		node = binary_tree_rotate_right(tree);
	}
	else if (bfactor < -1)
	{
		if (tree->right->left && !tree->right->left)
			binary_tree_rotate_right(tree->right);
		node = binary_tree_rotate_left(tree);
	}
	return (node);
}

/**
 * avl_remove - removes a node from an AVL tree
 *
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node;

	if (root == NULL)
		return (root);
	if (root->n > value)
	{
		root->left = avl_remove(root->left, value);
		if (root->left)
			root->left->parent = root;
	}
	else if (root->n < value)
	{
		root->right = avl_remove(root->right, value);
		if (root->right)
			root->right->parent = root;
	}
	else
	{
		if (root->left == NULL)
		{
			node = root->right;
			free(root);
			return (node);
		}
		if (root->right == NULL)
		{
			node = root->left;
			free(root);
			return (node);
		}

		node = minValue(root->right);
		root->n = node->n;
		root->right = avl_remove(root->right, node->n);
		if (root->right)
			root->right->parent = root;
	}
	root = balance_t(root);
	return (root);
}
