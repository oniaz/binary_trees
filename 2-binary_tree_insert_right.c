#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another
 * node.
 * If parent already has a right-child, the new node takes its place, and the
 * old right-child is set as the right-child of the new node.
 *
 * @parent: pointer to the node to insert the right-child in.
 * @value: the value of the new node.
 *
 * Return: pointer to the new node, or NULL on failure or if parent is NULL.
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->right = NULL;
	if (parent->right)
	{
		node->right = parent->right;
		node->right->parent = node;
	}
	parent->right = node;
	node->left = NULL;
	node->n = value;
	return (node);
}
