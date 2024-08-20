#ifndef SARRAY_TREE_H
#include "sarray_tree.h"
#endif

static int left_child(int current)
{
    return 2 * current;
}

static int right_child(int current)
{
    return 2 * current + ROOT;
}

void insert(TREE_T value)
{
    int current;
    assert(value != 0); // assuming 0 is not a valid value
    current = ROOT;
    /* go to the proper subtree until a leaf is reached */
    while (tree[current] != 0)
    {
        if (value < tree[current])
            current = left_child(current);
        else
        {
            assert(value != tree[current]); // assuming no duplicate values
            current = right_child(current);
        }
        assert(current <= ARRAY_SIZE);
    }

    tree[current] = value;
}

TREE_T find(TREE_T value)
{
    int current;
    current = ROOT; // start at root noderino

    /* until the value is found, go to the proper subtree */
    while (current < ARRAY_SIZE && tree[current] != value)
    {
        /* go left or right */
        if (value < tree[current])
            current = left_child(current);
        else
            current = right_child(current);
    }

    return (current < ARRAY_SIZE) ? tree + current : 0;
}

static void do_pre_order_traverse(int current, void (*callback)(TREE_T value))
{
    if (current < ARRAY_SIZE && tree[current] != 0)
    {
        callback(tree[current]);
        do_pre_order_traverse(left_child(current), callback);
        do_pre_order_traverse(right_child(current), callback);
    }
}

void pre_order_traverse(void (*callback)(TREE_T value))
{
    do_pre_order_traverse(ROOT, callback);
}
