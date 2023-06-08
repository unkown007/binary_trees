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
	binary_tree_t *node;

	if (tree == NULL)
		return (NULL);
	node = tree->left;
	tree->left = NULL;
	if (node->right)
	{
		tree->left = node->right;
		node->right->parent = tree;
	}
	node->parent = tree->parent;
	tree->parent = node;
	node->right = tree;
	tree = node;
	if (tree->parent)
		tree->parent->right = tree;
	/* tree->parent = NULL; */
	return (tree);
}
