#include "binary_trees.h"

#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: The height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (1 + (left_height > right_height ? left_height : right_height));
}

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
