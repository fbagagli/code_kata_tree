#include "libtree.h"
#include "stddef.h"

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
