#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes with at least 1 child or 0 otherwise
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t total_nodes, count = 0, left_node = 0, right_node = 0;

	if (!tree)
		return (0);

	right_node = binary_tree_nodes(tree->right);
	left_node = binary_tree_nodes(tree->left);

	if (!tree->left && tree->right)
		count++;
	else if (tree->left && !tree->right)
		count++;
	else if (tree->left && tree->right)
		count++;

	total_nodes = right_node + left_node + count;
	return (total_nodes);
}
