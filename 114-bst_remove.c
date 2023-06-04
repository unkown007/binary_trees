#include <stdlib.h>
#include "binary_trees.h"

/**
 * rm - removes a node from a Binary Search Tree
 *
 * @node: pointer to the node of the tree
 */
void rm(bst_t *node)
{
	bst_t *temp;

	temp = node;
	if (!node->left && !node->right)
	{
		node->left->parent = node->right;
		node->right->parent = node->parent;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = node->right;
			else
				node->parent->right = node->right;
		}
		else
			node = node->right;
	} else if (!node->left)
	{
		node->right->parent = node->parent;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = node->right;
			else
				node->parent->right = node->right;
		} else
			node = node->right;
	} else if (!node->right)
	{
		node->left->parent = node->parent;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = node->left;
			else
				node->parent->right = node->left;
		} else
			node = node->left;
	}
	free(temp);
}

/**
 * minValue -  get minimum value of the tree
 *
 * @tree: pointer to root node of the tree
 *
 * Return: pointer to he node with the minimum value
 */
bst_t *minValue(bst_t *tree)
{
	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL)
		return (tree);
	return (minValue(tree->left));
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
	}
	return (root);
}
