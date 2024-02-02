#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	size_t leaves;

	root = binary_tree_node(NULL, 1);
	root->left = binary_tree_node(root, 2);
	binary_tree_insert_left(root->left, 3);
	binary_tree_insert_right(root->left, 4);
	binary_tree_insert_right(root->left->right, 5);
	binary_tree_insert_left(root->left->right->right, 6);
	binary_tree_insert_right(root->left->right->right, 7);
	binary_tree_insert_right(root->left->right->right->right, 8);
	binary_tree_insert_right(root->left->right->right->right->right, 9);
	root->right = binary_tree_node(root, 10);
	binary_tree_print(root);

	leaves = binary_tree_leaves(root);
	printf("Leaves in %d: %lu\n", root->n, leaves);

	return (0);
}
