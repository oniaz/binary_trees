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
	int perfect;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 128);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_left(root->right, 128);
	root->left->left = binary_tree_node(root->left, 10);
	binary_tree_insert_right(root->right, 54);
	binary_tree_insert_right(root->right->right, 1);
	binary_tree_insert_left(root->right->right, 2);
	binary_tree_insert_left(root->left->left, 3);
	binary_tree_insert_right(root->left->left, 4);

	binary_tree_print(root);
	printf("\n");

	const binary_tree_t *test = root;

	binary_tree_print(test);
	perfect = binary_tree_is_perfect(test);
	printf("Perfect: %d\n\n", perfect);

	return (0);
}
