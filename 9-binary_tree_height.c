#include "binary_trees.h"

/**
 * get_longest_child - Get longest child from parent
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: deepest dept from parent
 */
size_t get_longest_child(const binary_tree_t *tree)
{
	size_t left_child = 0, right_child = 0;

	if (tree == NULL)
		return (0);

	left_child =  1 + get_longest_child(tree->left);
	right_child =  1 + get_longest_child(tree->right);

	return (left_child < right_child ? right_child : left_child);
}

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of tree or 0 If tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height;

	height = get_longest_child(tree) - 1; /*counting from index 0*/

	return (height);
}
