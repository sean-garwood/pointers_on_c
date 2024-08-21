#ifndef LINK_TREE_H
#include "link_tree.h"
#endif

int main(void)
{
    size_t expected_node_count, actual_node_count;
    TREE_T test_values[] = dummies;
    TREE_T init_root_value = test_values[0];

    // insert values into tree
    for (size_t i = 0; i < dummy_count; i++)
        insert(test_values[i]);

    // test the node_count function
    actual_node_count = count_nodes(in_order_traverse);
    assert((expected_node_count = dummy_count) == actual_node_count);

    // test the is_bst function
    assert(is_bst(in_order_traverse));

    // test the delete_node function
    delete_node(5);
    assert((find(4))->right->value == 6);
    assert(find(5) == NULL);
    // test the destroy_tree function
    destroy_tree();
    assert(init_root_value != root->value);
    return 0;
}

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
    if (current == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    current->value = value;
    current->left = NULL;
    current->right = NULL;
    *link = current;
}

/* find a specific value in the tree */
Node *find(TREE_T value)
{
    /* start at root */
    Node *current = root;

    /* until the value is found, go to the proper subtree */
    while (current != NULL && current->value != value)
        current = (value < current->value) ? current->left : current->right;

    return current;
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

/*
 * 17.5 ANSWER
 */

void count_node(TREE_T value)
{
    (void)value;
    node_count++;
}

size_t count_nodes(void (*traverse)(void (*count)(TREE_T value)))
{
    // traverse tree and count nodes
    node_count = 0;
    traverse(count_node);
    return node_count;
}

/*
 * 17.7 ANSWER
 */
void compare(TREE_T value)
{
    static TREE_T last_value = 0;
    if (last_value != 0)
        assert(last_value < value);
    last_value = value;
}

int is_bst(void (*traverse)(void (*compare)(TREE_T value)))
{
    // traverse tree and compare values
    traverse(compare);
    return 1;
}

/*
 * 17.9 ANSWER
 */
void destroy_node(TREE_T value)
{
    Node *doomed_node = find(value);
    if (!(doomed_node == NULL))
    {
        doomed_node->left = doomed_node->right = NULL;
        free(doomed_node);
    }
}

void destroy_tree(void)
{
    // traverse tree and free nodes
    post_order_traverse(destroy_node);
}

/*
 * 17.10 ANSWER
 *
 * Write a function that deletes a value from the tree. If the value is not in
 * the tree, the function should abort the program.
 *
 */

// helper for delete_node
int number_of_children(Node *node)
{
    int children = 0;
    if (node->left != NULL)
        children++;
    if (node->right != NULL)
        children++;
    return children;
}

void delete_node(TREE_T value)
{
    Node *to_delete, *successor;
    assert((to_delete = find(value)) != NULL);

    switch (number_of_children(to_delete))
    {
    case 0:
        destroy_node(value);
        break;
    case 1:
        if (to_delete->left != NULL)
            memcpy(to_delete, to_delete->left, sizeof(Node));
        else
            memcpy(to_delete, to_delete->right, sizeof(Node));
        break;
    case 2:
        // find the in-order successor
        successor = to_delete->right;
        while (successor->left != NULL)
            memcpy(successor, successor->left, sizeof(Node));
        // replace the node with the successor
        memcpy(to_delete, successor, sizeof(Node));
        destroy_node(successor->value);
        break;
    }
}
