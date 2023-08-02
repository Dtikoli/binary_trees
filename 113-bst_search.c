#include "binary_trees.h"

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
