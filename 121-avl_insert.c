#include <stdlib.h>
#include "binary_trees.h"

/**
 * height_t - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, 0 if the tree is NULL
 */
size_t height_t(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + height_t(tree->left) : 1;
	r = tree->right ? 1 + height_t(tree->right) : 1;
	return (l > r ? l : r);
}

/**
 * balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of the tree, 0 if the tree if NULL
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height_t(tree->left) - height_t(tree->right) : 0);
}

/**
 * insert - inserts a value in an AVL Tree
 *
 * @tree: pointer to the root node of the AVL tree
 * @parent: pointer to the parent node of the new node
 * @new: double pointer to the new created node
 * @value: integer value to insert
 *
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *insert(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int bl_factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*tree)->n == value)
		return (*new = *tree);
	else if ((*tree)->n > value)
	{
		(*tree)->left = insert(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = insert(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}

	bl_factor = balance(*tree);
	if (bl_factor > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bl_factor < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bl_factor > 1 && (*tree)->left->n < value)
	{
		binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bl_factor < -1 && (*tree)->right->n > value)
	{
		binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
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
	avl_t *node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert(tree, *tree, &node, value);
	return (node);
}
