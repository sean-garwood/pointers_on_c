/*
 * interfacer for a BST
 */

#ifndef TREE_H
#define TREE_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TREE_T int

/* hold value and pointers for one tree node */
typedef struct node
{
    TREE_T value;
    struct node *left;
    struct node *right;
} Node;

/* insert a new value to the tree. argument: value to be added. mustn't exist */
void insert(TREE_T value);

/* find a specific value in the tree */
Node *find(TREE_T value);

/* pre-order traversal. arg is pointer to cb function that has val as arg */
void pre_order_traverse(void (*callback)(TREE_T value));

/*
 * EXERCISE ANSWERS
 */

/* in-order traversal */
void in_order_traverse(void (*callback)(TREE_T value));

/* post-order traversal */
void post_order_traverse(void (*callback)(TREE_T value));

/* callback to count nodes in tree */
/* return 1 if arg is not null pointer, else 0 */
void count_node(TREE_T value);

/* count nodes in tree */
size_t count_nodes(
    void (*traverse)(
        void (*count)(TREE_T value)));

/* comparison callback */
void compare(TREE_T value);

/* return 1 if tree is a bst, else 0 */
int is_bst(void (*traverse)(void (*compare)(TREE_T value)));
#endif // TREE_H
