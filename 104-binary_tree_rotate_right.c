#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);
	node = tree->left;
	tmp = node->right;
	node->right = tree;
	tree->left = tmp;
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
