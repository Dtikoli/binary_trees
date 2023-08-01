#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 * Return: pointer to the ancestor node, NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t d_first, d_second;

	if (!first || !second)
		return (NULL);

	d_first = binary_tree_depth(first);
	d_second = binary_tree_depth(second);

	while (d_first > d_second)
	{
		first = first->parent;
		d_first--;
	}
	while (d_second > d_first)
	{
		second = second->parent;
		d_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree)
	{
		if (tree->parent)
			depth++;
		tree = tree->parent;
	}

	return (depth);
}
