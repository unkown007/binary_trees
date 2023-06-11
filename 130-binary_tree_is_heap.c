#include <stdlib.h>
#include "binary_trees.h"

/**
 * isheap - checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid MAX Binary Heap
 */
int isheap(const binary_tree_t *tree)
{
	if (!tree)
		return (1);
	if (!tree->left && tree->right)
		return (0);
	if (tree->left && tree->left->n >= tree->n)
		return (0);
	if (tree->right && tree->right->n >= tree->n)
		return (0);
	return (isheap(tree->left) &&
			isheap(tree->right));
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
	return (isheap(tree));
}
