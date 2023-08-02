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
	bst_t *node;

	node = bst_search(root, value);

	if (node)
	{
		if (binary_tree_is_leaf(node) == 1)
		{
			if (node == node->parent->left)
				node->parent->left = NULL;
			if (node == node->parent->right)
				node->parent->right = NULL;
			free(node);
			return (root);
		}
		if (node->right && node->right->left)
			root = right_left_case(node, root);
		else if (node->right)
			root = right_case(node, root);
		else
		{
			if (node->parent)
				node->parent->right = node->left;
			node->left->parent = node->parent;
			if (root == node)
				root = node->left;
			free(node);
		}
	}
	return (root);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
		leaf = 1;

	return (leaf);
}

/**
 * bst_search - searches for a value in a BST
 * @tree: pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: pointer to the node containing an int equal to `value`
 *         NULL if tree is NULL or if no match is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *snode = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (snode)
	{
		if (value == snode->n)
			return (snode);
		if (value < snode->n)
			snode = snode->left;
		else if (value > snode->n)
			snode = snode->right;
	}

	return (NULL);
}

/**
 * right_case - removes a node from a BST for node->right
 * @root: tree root
 * @node: node to delete
 * Return: pointer the tree root
 */
bst_t *right_case(bst_t *node, bst_t *root)
{
	node->right->left = node->left;
	node->right->parent = node->parent;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = node->right;
		if (node == node->parent->right)
			node->parent->right = node->right;
	}
	if (node->left)
		node->left->parent = node->right;
	if (root == node)
		root = node->right;
	free(node);

	return (root);
}

/**
 * right_left_case - removes a node from a BST for node->right->left
 * @root: tree root
 * @node: node to delete
 * Return: pointer the tree root
 */
bst_t *right_left_case(bst_t *node, bst_t *root)
{
	node->right->left->right = node->right;
	node->right->left->parent = node->parent;
	node->right->left->left = node->left;
	if (node->left)
		node->left->parent = node->right->left;
	node->right->parent = node->right->left;
	if (root == node)
		root = node->right->left;
	else
	{
		if (node == node->parent->left)
			node->parent->left = node->right->left;
		if (node == node->parent->right)
			node->parent->right = node->right->left;
	}
	node->right->left = NULL;
	free(node);

	return (root);
}

