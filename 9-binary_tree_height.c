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
 * postorder_visit - goes through the binary tree using post-order traversal
 * and updates the max height.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @c: current depth.
 * @max_height: max height reached for the tree.
 * Return: max height.
 **/
int postorder_visit(const binary_tree_t *tree, int c, int max_height)
{
	if (!tree)
		return (update_max(c, max_height));

	c++;
	max_height = postorder_visit(tree->left, c, max_height);
	max_height = postorder_visit(tree->right, c, max_height);
	return (max_height);
}

/**
 * binary_tree_height - measures the height of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: binary tree height.0 If tree is NULL.
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	int max_height = 0;

	if (tree)
		max_height = postorder_visit(tree, -1, -1);

	return (max_height);
}
