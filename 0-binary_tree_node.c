#include "binary_trees.h"

/**
 * binary_tree_node -  creates a binary tree node.
 * @parent: pointer to the parent node of the node to be created.
 * @value: the value of the new node.
 *
 * Return: pointer ot the new node, or NULL on failure.
 **/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;
	return (node);
}
