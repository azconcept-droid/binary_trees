#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: pointer to the node to find the sibling
 * Return: a pointer to the sibling node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/*If node is NULL or the parent is NULL*/
	if (!node || !node->parent)
		return (NULL);

	/*if sibling is at the left*/
	if (node->parent->right && node->parent->right->n == node->n)
		return (node->parent->left);

	/*if sibling is at the right*/
	if (node->parent->left && node->parent->left->n == node->n)
		return (node->parent->right);

	return (NULL);
}
