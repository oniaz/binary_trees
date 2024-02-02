#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a given node.
 *
 * @node: pointer to the node for which the sibling should be found.
 *
 * Return: pointer tot the sibling node. NULL if node is NULL or the parent
 * is NULL or node has no sibling.
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->right || !node->parent->left)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
