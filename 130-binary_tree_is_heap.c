#include <stdlib.h>
#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * isheap - checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid MAX Binary Heap
 */
int isheap(const binary_tree_t *tree)
{
	if (!tree->left && !tree->right)
		return (1);
	if (tree->right == NULL)
		return (tree->n >= tree->left->n);
	if (tree->left->n <= tree->n && tree->right->n <= tree->n)
		return (isheap(tree->left) &&
				isheap(tree->right));
	return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid MAX Binary Heap
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_is_complete(tree) && isheap(tree));
}
