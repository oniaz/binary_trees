#include "binary_trees.h"

/**
 * postorder_visit - goes through the binary tree using post-order traversal
 * and counts the leaf nodes.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @leaves: number of leaf nodes traversed so far.
 *
 * Return: binary tree leaves.
 **/
int postorder_visit(const binary_tree_t *tree, int leaves)
{
	if (tree && !tree->left && !tree->right)
		return (++leaves);

	if (!tree)
		return (leaves);

	leaves = postorder_visit(tree->left, leaves);
	leaves = postorder_visit(tree->right, leaves);
	return (leaves);
}

/**
 * binary_tree_leaves - counts the leaf nodes in the binary tree.
 *
 * @tree: pointer to the root node of the tree for which the leaves are
 * counted.
 *
 * Return: binary tree leaves. 0 if tree is NULL.
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leaves = 0;

	if (tree)
		leaves = postorder_visit(tree, leaves);

	return (leaves);
}
