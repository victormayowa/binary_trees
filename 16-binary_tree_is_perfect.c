#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	size_t expected_nodes = 1;

	if (tree == NULL)
		return (0);
	while (height > 0)
	{
		expected_nodes *= 2;
		height--;
	}
	return (expected_nodes - 1 == binary_tree_size(tree));
}
