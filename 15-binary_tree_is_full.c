#include "binary_trees.h"

/**
 * visit - traverses the binray tree and checks if it's full.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @full: whether tree is full or not (1 -> full, 0 -> not full).
 *
 * Return: 1 if binary tree is full, 0 if if not.
 **/
int visit(const binary_tree_t *tree, int full)
{
	if (!tree)
		return (full);

	full = visit(tree->left, full);
	full = visit(tree->right, full);

	if (full == 0)
		return (0);

	return ((!tree->left && !tree->right) || (tree->left && tree->right));
}

/**
 * binary_tree_is_full - checks if a binary tree is full.
 *
 * @tree: pointer to the root node of the tree to be checked.
 *
 * Return: 1 if binary tree is full. 0 if if not or tree is NULL.
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 0;

	if (tree)
		full = visit(tree, 1);

	return (full);
}
