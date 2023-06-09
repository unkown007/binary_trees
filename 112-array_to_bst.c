#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: pointer to first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (array == NULL)
		return (NULL);
	root = NULL;
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}