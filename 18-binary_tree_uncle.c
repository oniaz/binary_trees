#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle node of a given node.
 *
 * @node: pointer to the node for which the uncle should be found.
 *
 * Return: pointer to the uncle node. NULL if node is NULL or has no uncle.
 **/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent ||
			!node->parent->parent->left || !node->parent->parent->right)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
