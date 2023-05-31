#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_level - measures the level of a node
 *
 * @node: pointer to the node
 *
 * Return: level of the node
 */
size_t get_level(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (node->parent ? 1 + get_level(node->parent) : 0);
}

/**
 * common_ancestor - finds lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the common ancestor, NULL otherwise
 */
binary_tree_t *common_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);
	return (common_ancestor(first->parent, second->parent));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node, or NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t node1_level, node2_level;

	if (!first || !second)
		return (NULL);
	node1_level = get_level(first);
	node2_level = get_level(second);
	while (first && node1_level > node2_level)
	{
		first = first->parent;
		node1_level = node1_level - 1;
	}
	while (second && node1_level < node2_level)
	{
		second = second->parent;
		node2_level = node2_level - 1;
	}
	return (common_ancestor(first, second));
}
