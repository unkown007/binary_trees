#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	node = tree->right;
	tmp = node->left;
	node->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = node;
	node->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = node;
		else
			tmp->right = node;
	}
	return (node);
}
