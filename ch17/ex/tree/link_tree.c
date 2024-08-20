#ifndef LINK_TREE_H
#include "link_tree.h"
#endif

/* insert a node to the tree */
void insert(TREE_T value)
{
    Node *current;
    Node **link;

    /* set current to root */
    link = &root;

    /* as long as a value is found, keep walking to next subtree */
    while ((current = *link) != 0)
    {
        if (value < current->value)
            link = &current->left;
        else
        {
            assert(value != current->value); // assuming no duplicate values
            link = &current->right;
        }
    }

    /* Allocate a new node; set pointer */
    current = malloc(sizeof(Node));
    assert(current != NULL);
    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

/* find a specific value in the tree */
TREE_T *find(TREE_T value)
{
    /* start at root */
    Node *current = root;

    /* until the value is found, go to the proper subtree */
    while (current != NULL && current->value != value)
        current = (value < current->value) ? current->left : current->right;

    return (current != NULL) ? &current->value : NULL;
}

/* Do a pre-order traversal of the tree.
 *    Do one level of a pre-order traversal. Helper function is needed to save the information of node in process.
 *    Not part of client interface. */
static void do_pre_order_traverse(Node *current, void (*callback)(TREE_T value))
{
    if (current != NULL)
    {
        callback(current->value);
        do_pre_order_traverse(current->left, callback);
        do_pre_order_traverse(current->right, callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_T value))
{
    do_pre_order_traverse(root, callback);
}

/*
 * EXERCISE ANSWERS
 */
static void do_in_order_traverse(Node *current, void (*callback)(TREE_T value))
{
    if (current != NULL)
    {
        do_in_order_traverse(current->left, callback);
        callback(current->value);
        do_in_order_traverse(current->right, callback);
    }
}

void in_order_traverse(void (*callback)(TREE_T value))
{
    do_in_order_traverse(root, callback);
}

static void do_post_order_traverse(Node *current, void (*callback)(TREE_T value))
{
    if (current != NULL)
    {
        do_post_order_traverse(current->left, callback);
        do_post_order_traverse(current->right, callback);
        callback(current->value);
    }
}

void post_order_traverse(void (*callback)(TREE_T value))
{
    do_post_order_traverse(root, callback);
}
