#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node.
 * If parent already has a left-child, the new node takes its place, and the
 * old left-child is set as the left-child of the new node.
 *
 * @parent: pointer to the node to insert the left-child in.
 * @value: the value of the new node.
 *
 * Return: pointer to the new node, or NULL on failure or if parent is NULL.
 **/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	if (parent->left)
		node->left = parent->left;
	parent->left = node;
	node->right = NULL;
	node->n = value;
	return (node);
}
