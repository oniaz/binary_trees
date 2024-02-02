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
 * get_depth - measures the depth of a node in a binary tree.
 *
 * @tree: pointer to the node to measure the depth.
 *
 * Return: node depth. 0 if tree is NULL.
 **/
int get_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree && tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
/**
 * is_full - traverses the binray tree and checks if it's full.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @full: whether tree is full or not (1 -> full, 0 -> not full).
 * @tree_height: height of the tree.
 *
 * Return: 1 if binary tree is full, 0 if if not.
 **/
int is_full(const binary_tree_t *tree, int full, int tree_height)
{
	if (!tree)
		return (full);

	full = is_full(tree->left, full, tree_height);
	full = is_full(tree->right, full, tree_height);

	if (full == 0)
		return (0);
	if ((!tree->left && !tree->right) && get_depth(tree) != tree_height)
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
		int tree_height;

		tree_height = get_height(tree->left, 0, 0);
		full = is_full(tree, 1, tree_height);
		bf += get_height(tree->left, 0, 0);
		bf -= get_height(tree->right, 0, 0);

		perfect = (full == 1 && bf == 0);
	}

	return (perfect);
}
