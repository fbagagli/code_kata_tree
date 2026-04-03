### Week 1, Session 1: The Foundation & In-Order Traversal

**Objective:** Establish the basic binary tree structures and implement both
recursive and iterative in-order traversals, along with proper memory teardown. 

**Requirements:**

1.  **The Structure:** Define a `struct tree_node` containing an integer payload
    and pointers to left and right children. 
2.  **The Allocator:** Write `struct tree_node* create_node(int value)`.
3.  **Recursive Traversal:** Write `void inorder_recursive(const struct
    tree_node* root)`. It should print the node values to `stdout`.
4.  **Iterative Traversal:** Write `void inorder_iterative(const struct
tree_node* root)`. 
    * *Constraint:* You cannot use recursion. You must manage your own stack.
      For this session, you may implement a simple fixed-size array-based stack
      (e.g., max depth 100) to keep the 40-minute time box manageable, or write
      a dynamic one if you are feeling fast.
5.  **The Teardown:** Write `void free_tree(struct tree_node* root)` to safely
deallocate the entire tree.

**Edge Cases & Pitfalls to Handle:**
* What happens if a `NULL` root is passed to your traversals or your free
  function?
* How does your allocator handle `malloc` failures? (Standard `abort()`,
  returning `NULL`, or logging?). Choose a strategy and be consistent.
* Ensure your `free_tree` function doesn't result in a use-after-free scenario. 

**Testing Your Code:** Write a small `main()` function locally that builds a
hardcoded, unbalanced tree (e.g., a root with a left child, which has a right
child, etc.) to verify your iterative stack logic handles standard and
degenerate shapes. Run it through Valgrind before pasting it here.
