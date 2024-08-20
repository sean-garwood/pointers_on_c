#ifndef SARRAY_TREE_H
#define SARRAY_TREE_H

#ifndef TREE_H
#include "tree.h"
#endif

#define ROOT 1 // root node. index 0 is not used
#define TREE_SIZE 100
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_T tree[ARRAY_SIZE];

/* compute the subscript of the left child of `current` */
static int left_child(int current);

/* compute the subscript of the right child of `current` */
static int right_child(int current);

/* 'Do' one level of a pre-order traverse.
 *    Helper function is needed to save the information of node in process.
 *    Not a part of client's interface. */
static void do_pre_order_traverse(int current, void (*callback)(TREE_T value));

#endif // SARRAY_TREE_H
