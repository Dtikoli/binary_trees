#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 * Return: the generated array, NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *node_array = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	node_array = malloc(sizeof(int) * (*size));

	if (!node_array)
		return (NULL);

	for (i = 0; heap; i++)
		node_array[i] = heap_extract(&heap);

	return (node_array);
}
