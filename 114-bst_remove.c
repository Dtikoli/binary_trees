#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * The deleted node must be replaced with its first in-order successor.
 * @root: root node
 * @value: value in node to look for and remove
 * Return: pointer to new root node of tree after removing desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *del_node, *new_node = NULL, *new_root;
	int status = 0; /* 1 if right, 0 if left */

	if (!root)
		return (NULL);

	del_node = search_val(root, value);
	if (!del_node)
		return (NULL);

	if (del_node->right)
	{
		new_node = del_node->right, status = 1;
		while (new_node->left)
			new_node = new_node->left;
	}
	else if (del_node->left)
		new_node = del_node->left;
	if (!new_node)
	{
		if (del_node->parent->left->n == del_node->n)
			del_node->parent->left = NULL;
		else
			del_node->parent->right = NULL;
		new_root = find_root(del_node);
		free(del_node);
	}
	else if (status == 1)
	{
		del_node->n = new_node->n;
		new_root = find_root(new_node);
		if (new_node->parent->left->n == new_node->n)
			new_node->parent->left = NULL;
		else
			new_node->parent->right = NULL;
		free(new_node);
	}
	else
	{
		del_node->n = new_node->n;
		del_node->left = del_node->left->left;
		if (del_node->left)
			del_node->left->parent = del_node;
		new_root = find_root(del_node);
		free(new_node);
	}
	return (new_root);
}

/**
 * search_val - Search for a value in a Binary Search Tree
 * @tree: pointer to root node of BST
 * @value: value to look for 9bst_t *bst_search(const bst_t *tree, int value)
 * Return: pointer to node containing value, else NULL
 */
bst_t *search_val(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (search_val(tree->left, value));
	else
		return (search_val(tree->right, value));
}

/**
 * find_root - find the root of a Binary Search Tree
 * @node: node in a BST
 * Return: pointer to root node, else NULL
 */
bst_t *find_root(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->parent)
		node = node->parent;

	return (node);
}
