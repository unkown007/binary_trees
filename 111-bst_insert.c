#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST
 * @value: integer value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL || *tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	if ((*tree)->n == value)
		return (NULL);
	if ((*tree)->n > value)
	{
		if ((*tree)->left == NULL)
			return ((*tree)->left = binary_tree_node(*tree, value));
		return (bst_insert(&(*tree)->left, value));
	}
	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
			return ((*tree)->right = binary_tree_node(*tree, value));
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}
