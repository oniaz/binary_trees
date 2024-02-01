#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *
 * @tree: pointer to the node to measure the depth.
 *
 * Return: binary tree height. 0 if tree is NULL.
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
