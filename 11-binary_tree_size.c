#include "binary_trees.h"

/**
 * postorder_visit - goes through the binary tree using post-order traversal
 * and updates the size.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @size: number of nodes traversed so far.
 *
 * Return: binary tree size.
 **/
int postorder_visit(const binary_tree_t *tree, int size)
{
	if (!tree)
		return (size);

	size++;
	size = postorder_visit(tree->left, size);
	size = postorder_visit(tree->right, size);
	return (size);
}

/**
 * binary_tree_size - counts the nodes in the binary tree.
 *
 * @tree: pointer to the root node of the tree for which the size is measured.
 *
 * Return: binary tree size. 0 if tree is NULL.
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 0;

	if (tree)
		size = postorder_visit(tree, size);

	return (size);
}
