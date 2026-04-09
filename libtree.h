#ifndef LIBTREE_H
#define LIBTREE_H

struct tree_node;

struct tree_node {
	struct tree_node *left;
	struct tree_node *right;
	int payload;
};

struct tree_node *create_node(int payload);

void inorder_recursive(const struct tree_node *node);

void inorder_iterative(const struct tree_node *node);

void preorder_recursive(const struct tree_node *node);

void preorder_iterative(const struct tree_node *node);

void postorder_recursive(const struct tree_node *node);

int tree_size(const struct tree_node *node);

int tree_max_depth(const struct tree_node *node);

void free_tree(struct tree_node *node);

#endif
