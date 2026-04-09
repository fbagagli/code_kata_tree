#include <stdio.h>
#include "libtree.h"

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
	struct tree_node *n6 = create_node(6);
	n2->right = n6;

	// tree display
	printf("recursive inorder traversal: ");
	inorder_recursive(root);
	printf("\n");
	printf("iterative inorder traversal: ");
	inorder_iterative(root);
	printf("\n");
	printf("recursive preorder traversal: ");
	preorder_recursive(root);
	printf("\n");
	printf("iterative preorder traversal: ");
	preorder_iterative(root);
	printf("\n");
	printf("tree size: %d\n", tree_size(root));
	printf("tree max depth: %d\n", tree_max_depth(root));
	printf("recursive postorder traversal: ");
	postorder_recursive(root);
	printf("\n");
	free_tree(root);
	return 0;
}
