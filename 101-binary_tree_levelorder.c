#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverst a binary tree using level-order traverse
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t lev, lev_max;

	if (!tree || !func)
		return;

	lev_max = binary_tree_height(tree) + 1;

	for (lev = 1; lev <= lev_max; lev++)
		level_order(tree, func, lev);
}

/**
 * level_order - goes through a binary tree using post-order traverse
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @lev: level of the tree to call func upon
 */
void level_order(const binary_tree_t *tree, void (*func)(int), size_t lev)
{
	if (lev == 1)
		func(tree->n);
	else
	{
		level_order(tree->left, func, lev - 1);
		level_order(tree->right, func, lev - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0;
	size_t h_right = 0;

	if (!tree)
		return (0);

	h_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	h_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (h_right < h_left ? h_left : h_right);
}
