#include "binary_trees.h"

/**
 * array_to_bst - builds BST from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 * Return: pointer to the root node of the created BST, NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
