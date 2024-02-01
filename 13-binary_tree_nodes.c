#include "binary_trees.h"

/**
 * postorder_visit - goes through the binary tree using post-order traversal
 * and counts the leaf nodes.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @nodes: number of leaf nodes traversed so far.
 *
 * Return: binary tree nodes.
 **/
int postorder_visit(const binary_tree_t *tree, int nodes)
{
	if (!tree)
		return (nodes);

	nodes = postorder_visit(tree->left, nodes);
	nodes = postorder_visit(tree->right, nodes);

	if ((tree) && (tree->left || tree->right))
		return (++nodes);

	return (nodes);
}
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 *
 * @tree: pointer to the root node of the tree for which the nodes are counted.
 *
 * Return: number of nodes with at least 1 child. 0 if tree is NULL.
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int nodes = 0;

	if (tree)
		nodes = postorder_visit(tree, nodes);

	return (nodes);
}
