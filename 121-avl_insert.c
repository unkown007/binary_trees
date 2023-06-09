#include <stdlib.h>
#include "binary_trees.h"

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
		return (*tree);
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

	bl_factor = binary_tree_balance(*tree);
	if (bl_factor > 1 && (*tree)->left->n > value)
	{
		/*if (tree->left->right)
			binary_tree_rotate_left(tree->left);*/
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bl_factor < -1 && (*tree)->right->n < value)
	{
		/*if (tree->right->left)
			binary_tree_rotate_right(tree->left); */
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
 * avl_balance - balance a AVL tree
 *
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node
 */
avl_t *avl_balance(avl_t *tree)
{
/*	int bl_factor; */

	if (tree == NULL)
		return (NULL);
	/*if (tree->left)
		avl_balance(tree->left);
	if (tree->right)
		avl_balance(tree->right);
	bl_factor = binary_tree_balance(tree);
	if (bl_factor > 1 && tree->left->n > value)
	{*/
		/*if (tree->left->right)
			binary_tree_rotate_left(tree->left);*/
/*		tree = binary_tree_rotate_right(tree);
	}
	else if (bl_factor < -1 && tree->right->n < value)
	{*/
		/*if (tree->right->left)
			binary_tree_rotate_right(tree->left); */
/*		tree = binary_tree_rotate_left(tree);
	}
	else if (bl_factor > 1 && tree->left->n < value)
	{
		binary_tree_rotate_left(tree->left);
		tree = binary_tree_rotate_right(tree);
	}
	else if (bl_factor < -1 && tree->right->n > value)
	{
		binary_tree_rotate_right(tree->right);
		tree = binary_tree_rotate_left(tree);
	}*/
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
	avl_t *node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert(tree, *tree, &node, value);
	/**tree = avl_balance(*tree);*/
	return (node);
}
