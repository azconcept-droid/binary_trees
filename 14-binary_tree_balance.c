#include "binary_trees.h"

/**
 * get_left_height - Get height of left subtree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: the height of tree
 */
size_t get_left_height(const binary_tree_t *tree)
{
	size_t left_child_height = 0;

	if (tree == NULL)
		return (0);

	left_child_height =  1 + get_left_height(tree->left);

	return (left_child_height);
}

/**
 * get_right_height - Get height of right subtree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: the height of tree
 */
size_t get_right_height(const binary_tree_t *tree)
{
	size_t right_child_height = 0;

	if (tree == NULL)
		return (0);

	right_child_height =  1 + get_right_height(tree->right);

	return (right_child_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the binary tree or 0 otherwise.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t b_factor, left_tree, right_tree;

	if (tree == NULL)
		return (0);

	left_tree = get_left_height(tree) - 1;
	right_tree =  get_right_height(tree) - 1;

	b_factor = left_tree - right_tree; /*Balance tree factor*/

	return (b_factor);
}
