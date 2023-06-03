#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: pointer to the root node of the BST
 * @value: integer value to search
 *
 * Return: pointer to the node containing a value equals to value,
 * or NULL otherwise;
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *) tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	if (tree->n < value)
		return (bst_search(tree->right, value));
	return (NULL);
}
