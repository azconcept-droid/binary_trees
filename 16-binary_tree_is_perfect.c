#include "binary_trees.h"

/**
 * find_depth - find depth of leftmost leaf
 *
 * @tree: pointer to node to start from
 * Return: lenght of depth
 */
int find_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * is_perfect - tests if a binary tree is perfect
 *
 * @tree: pointer to root of tree
 * @d: depth of leftmost subtree
 * @level: level of trees
 * Return: 1 if perfect, 0 otherwuse.
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	/*if empty tree*/
	if (!tree)
		return (0);

	/**
	 * If leaf node, then its depth must be same as
	 * depth of all other leaves.
	 */
	if (!tree->left && !tree->right)
		if (d == level + 1)
			return (1);

	/*If internal node and one child is empty*/
	if (!tree->left || !tree->right)
		return (0);

	/*Left and right subtrees must be perfect.*/
	if (is_perfect(tree->left, d, level + 1) &&
	is_perfect(tree->right, d, level + 1))
		return (1);

	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is perfect and 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	d = find_depth(tree);

	return (is_perfect(tree, d, 0));
}
