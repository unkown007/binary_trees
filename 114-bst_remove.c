#include <stdlib.h>
#include "binary_trees.h"

/**
 * minValue -  get minimum value of the tree
 *
 * @tree: pointer to root node of the tree
 *
 * Return: pointer to he node with the minimum value
 */
bst_t *minValue(bst_t *tree)
{
	bst_t *current;

	current = tree;
	while (current && current->left != NULL)
		current = current->left;
	return (current);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree
 * @value: value to remove
 *
 * Return: pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	if (root == NULL)
		return (root);
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			node = root->right;
			free(root);
			return (node);
		}
		else if (root->right == NULL)
		{
			node = root->left;
			free(root);
			return (node);
		}

		node = minValue(root->right);
		root->n = node->n;
		root->right = bst_remove(root->right, node->n);
		if (root->right)
			root->right->parent = root;
	}
	return (root);
}
