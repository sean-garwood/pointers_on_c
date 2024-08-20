/*
 * A BST implemented by linking dynamically allocated nodes
 */

#ifndef LINK_TREE_H
#define LINK_TREE_H

#ifndef TREE_H
#include "tree.h"
#endif

#include <malloc.h>

/* hold value and pointers for one tree node */
typedef struct node
{
    TREE_T value;
    struct node *left;
    struct node *right;
} Node;

/* pointer to root node in tree */
static Node *root;

#endif // LINK_TREE_H
