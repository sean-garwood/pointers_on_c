/*
 * A BST implemented by linking dynamically allocated nodes
 */

#ifndef LINK_TREE_H
#define LINK_TREE_H

#ifndef TREE_H
#include "tree.h"
#endif

#include <string.h>

#define dummies {3, 2, 4, 1, 5, -1, 0, 6, 7, 8}
#define dummy_count 10

/* pointer to root node in tree */
static Node *root;
static size_t node_count;

/* destroy a node */
void destroy_node(TREE_T value);

/* destroy a tree */
void destroy_tree(void);
#endif // LINK_TREE_H

/* returns the number of children a node has */
int number_of_children(Node *node);

/* delete a node with the given value and replace its children */
void delete_node(TREE_T value);
