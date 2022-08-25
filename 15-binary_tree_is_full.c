#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full else 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* if empty tree */
	if (tree == NULL)
		return (0);

	/*if leaf node*/
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/**
	 * If both left and right are not NULL,
	 * and left & right subtrees are full
	 */
	if ((tree->left) && (tree->right))
		if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
			return (1);

	return (0);
}
