#include <stdlib.h>
#include <stdio.h>
#include "libtree.h"
#include "libstack.h"

struct tree_node *create_node(int payload)
{
	struct tree_node *node =
		(struct tree_node *)malloc(sizeof(struct tree_node));
	if (!node) {
		printf("error allocating node!\n");
		return NULL;
	}
	node->left = NULL;
	node->right = NULL;
	node->payload = payload;
	return node;
}

void inorder_recursive(const struct tree_node *node)
{
	if (!node)
		return;
	inorder_recursive(node->left);
	printf("%d -> ", node->payload);
	inorder_recursive(node->right);
}

int tree_size(const struct tree_node *node)
{
	if (!node)
		return 0;
	int counter = 0;
	const struct tree_node *current = node;
	init_stack();
	while (current != NULL || occupation_stack() > 0) {
		if (current) {
			push_stack(current);
			current = current->left;
		} else {
			current = pop_stack();
			counter++;
			current = current->right;
		}
	}
	return counter;
}

int tree_max_depth(const struct tree_node *node)
{
	if (!node)
		return -1;
	int left = tree_max_depth(node->left);
	int right = tree_max_depth(node->right);
	return (left > right ? left : right) + 1;
}

void inorder_iterative(const struct tree_node *node)
{
	if (!node)
		return;
	const struct tree_node *current = node;
	init_stack();
	while (current != NULL || occupation_stack() > 0) {
		if (current) {
			push_stack(current);
			current = current->left;
		} else {
			current = pop_stack();
			printf("%d -> ", current->payload);
			current = current->right;
		}
	}
}

void preorder_recursive(const struct tree_node *node)
{
	if (!node)
		return;
	printf("%d -> ", node->payload);
	preorder_recursive(node->left);
	preorder_recursive(node->right);
}

void preorder_iterative(const struct tree_node *node)
{
	if (!node)
		return;
	const struct tree_node *current = node;
	init_stack();
	while (current != NULL || occupation_stack() > 0) {
		if (current) {
			push_stack(current);
			printf("%d -> ", current->payload);
			current = current->left;
		} else {
			current = pop_stack();
			current = current->right;
		}
	}
}

void postorder_recursive(const struct tree_node *node)
{
	if (!node)
		return;
	postorder_recursive(node->left);
	postorder_recursive(node->right);
	printf("%d -> ", node->payload);
}

void postorder_iterative(const struct tree_node *node)
{
	// tbd
}

void free_tree(struct tree_node *node)
{
	if (!node)
		return;

	// 1. Destroy the left subtree
	free_tree(node->left);
	// 2. Destroy the right subtree
	free_tree(node->right);
	// 3. Finally, destroy the parent (Post-Order)
	free(node);
}
