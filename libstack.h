#ifndef LIBSTACK_H
#define LIBSTACK_H

#include "libtree.h"

void init_stack();
int occupation_stack();
int push_stack(const struct tree_node *node);
const struct tree_node *pop_stack();

#endif
