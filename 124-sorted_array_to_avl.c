#include <stdlib.h>
#include "binary_trees.h"

/**
 * insert - insert a new element in an AVL tree
 *
 * @parent: parent node from previous recursion, or NULL for root
 * @lo: lowest index of the array
 * @hi: highest index of the array
 * @array: pointer to the first element of the array
 *
 * Return: pointer to the subtree's root node, or NULL on failure
 */
avl_t *insert(avl_t *parent, int *array, int lo, int hi)
{
	avl_t *root = NULL;
	int mid;

	if (!array)
		return (NULL);
	if (lo > hi)
		return (NULL);

	mid = (lo + hi) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);
	root->left = insert(root, array, lo, mid - 1);
	root->right = insert(root, array, mid + 1, hi);
	return (root);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (insert(NULL, array, 0, (int)size - 1));
}
