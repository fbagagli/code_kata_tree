#include <stdio.h>
#include <stdlib.h>

struct tree_node;

struct tree_node {
	struct tree_node *left;
	struct tree_node *right;
	int payload;
};

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
	if (node->left) {
		inorder_recursive(node->left);
	}
	printf("%d -> ", node->payload);
	if (node->right) {
		inorder_recursive(node->right);
	}
}

const struct tree_node *stack[100];
int i = 0;

void init_stack()
{
	i = 0;
}

int occupation_stack()
{
	return i;
}

int push_stack(const struct tree_node *node)
{
	stack[i] = node;
	return i++;
}

const struct tree_node *pop_stack()
{
	const struct tree_node *val;
	if (i > 0) {
		i--;
		val = stack[i];
	} else {
		val = NULL;
	}
	return val;
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

int main()
{
	// tree construction, no mem checks
	struct tree_node *root = create_node(5);
	struct tree_node *n3 = create_node(3);
	struct tree_node *n4 = create_node(4);
	root->left = n3;
	root->right = n4;
	struct tree_node *n1 = create_node(1);
	struct tree_node *n2 = create_node(2);
	n3->left = n1;
	n3->right = n2;

	// tree display
	printf("recursive inorder traversal: ");
	inorder_recursive(root);
	printf("\n");
	printf("iterative inorder traversal: ");
	inorder_iterative(root);
	printf("\n");
	free_tree(root);
	return 0;
}
