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
 * binary_tree_balance - measures the balance factor of a binary tree.
 *
 * @tree: pointer to the root node of the tree for which the balance factor is
 * measured.
 *
 * Return: balance factor. If tree is NULL, returns 0.
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	int bf = 0;

	if (tree)
	{
		int left = 0, right = 0;

		left = get_height(tree->left, 0, 0);
		right = get_height(tree->right, 0, 0);
		/* printf("left: %d - right: %d\n", left, right); */
		bf = (left - right);
	}

	return (bf);
}
