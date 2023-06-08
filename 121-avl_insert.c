#include <stdlib.h>
#include "binary_trees.h"

/**
 * insert - inserts a value in an AVL Tree
 *
 * @tree: pointer to the root node of the AVL tree
 * @value: integer value to insert
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *insert(avl_t **tree, int value)
{
	if (tree == NULL || *tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	if ((*tree)->n == value)
		return (NULL);
	if ((*tree)->n > value)
	{
		if ((*tree)->left == NULL)
			return ((*tree)->left =  binary_tree_node(*tree, value));
		return (insert(&(*tree)->left, value));
	}
	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
			return ((*tree)->right = binary_tree_node(*tree, value));
		return (insert(&(*tree)->right, value));
	}
	return (NULL);
}

/**
 * avl_balance - balance a AVL tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node
 */
avl_t *avl_balance(avl_t *tree)
{
	int bl_factor;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
		avl_balance(tree->left);
	if (tree->right)
		avl_balance(tree->right);
	bl_factor = binary_tree_balance(tree);
	if (bl_factor > 1)
	{
		if (tree->left->right)
			binary_tree_rotate_left(tree->left);
		tree = binary_tree_rotate_right(tree);
	}
	else if (bl_factor < -1)
	{
		if (tree->right->left)
			binary_tree_rotate_right(tree->left);
		tree = binary_tree_rotate_left(tree);
	}
	return (tree);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 *
 * @tree: pointer to the root node of the AVL tree
 * @value: integer value to insert
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (tree == NULL)
		return (NULL);
	node = insert(tree, value);
	*tree = avl_balance(*tree);
	return (node);
}
