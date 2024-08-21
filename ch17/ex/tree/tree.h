/*
 * interfacer for a BST
 */

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <assert.h>

#define TREE_T int

/* insert a new value to the tree. argument: value to be added. mustn't exist */
void insert(TREE_T value);

/* find a specific value in the tree */
TREE_T *find(TREE_T value);

/* pre-order traversal. arg is pointer to cb function that has val as arg */
void pre_order_traverse(
    void (*callback)(TREE_T value));

/*
 * EXERCISE ANSWERS
 */

/* in-order traversal */
void in_order_traverse(void (*callback)(TREE_T value));
/* post-order traversal */
void post_order_traverse(void (*callback)(TREE_T value));
#endif // TREE_H
