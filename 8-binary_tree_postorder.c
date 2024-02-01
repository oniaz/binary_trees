#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using post-order
 * traversal.
 * If tree or func is NULL, does nothing.
 *
 * @tree: pointer to the root node of the tree to traverse.
 * @func: a pointer to a function that will be called on each visited node
 * during traversal, where the node value will be passed as a parameter.
 *
 * Return: nothing.
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, *func);
		binary_tree_postorder(tree->right, *func);
		func(tree->n);
	}
}
