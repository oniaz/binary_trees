#include "binary_trees.h"

/**
 * update_max - updates the max value by picking the bigger of the two passed
 * ints.
 *
 * @a: first int.
 * @b: second int.
 *
 * Return: max int.
 **/
int update_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/**
 * get_height - traversese the tree and measures its height.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @c: current depth.
 * @max_height: max height reached for the tree.
 * Return: max height.
 **/
int get_height(const binary_tree_t *tree, int c, int max_height)
{
	if (!tree)
		return (update_max(c, max_height));

	c++;
	max_height = get_height(tree->left, c, max_height);
	max_height = get_height(tree->right, c, max_height);
	return (max_height);
}

/**
 * is_full - traverses the binray tree and checks if it's full.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @full: whether tree is full or not (1 -> full, 0 -> not full).
 *
 * Return: 1 if binary tree is full, 0 if if not.
 **/
int is_full(const binary_tree_t *tree, int full)
{
	if (!tree)
		return (full);

	full = is_full(tree->left, full);
	full = is_full(tree->right, full);

	if (full == 0)
		return (0);

	return ((!tree->left && !tree->right) || (tree->left && tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 *
 * @tree: pointer to the root node of the tree to be checked.
 *
 * Return: 1 if binary tree is perfect. 0 if if not or tree is NULL.
 **/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int perfect = 0;

	if (tree)
	{
		int full = 0;
		int bf = 0;

		full = is_full(tree, 1);
		bf += get_height(tree->left, 0, 0);
		bf -= get_height(tree->right, 0, 0);

		perfect = (full == 1 && bf == 0);
	}

	return (perfect);
}
