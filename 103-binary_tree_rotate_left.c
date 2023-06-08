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
	binary_tree_t *node;

	if (tree == NULL)
		return (NULL);
	node = tree->right;
	tree->right = NULL;
	if (node->left)
	{
		tree->right = node->left;
		tree->right->parent = tree;
	}
	node->parent = tree->parent;
	tree->parent = node;
	node->left = tree;
	tree = node;
	if (tree->parent)
		tree->parent->left = tree;
	/* tree->parent = NULL; */
	return (tree);
}
