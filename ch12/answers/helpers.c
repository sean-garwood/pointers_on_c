#include "../12.h"

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int three(void)
{
    // initialize a doubly linked list
    DNode root;
    DNode *rootp;
    rootp = &root;
    root.data = 0;
    root.next = NULL;
    root.prev = NULL;

    // insert some values into the list
    dll_insert(rootp, 1);
    dll_insert(rootp, 4);
    dll_insert(rootp, 3);
    dll_insert(rootp, 2);
    dll_insert(rootp, 5);

    // print the list
    DNode *curr;
    for (curr = root.next; curr != NULL; curr = curr->next)
        printf("%d\n", curr->data);

    // let's try the rewritten function
    DNode head;
    DNode tail;
    head.next = &tail;
    head.prev = NULL;
    tail.next = NULL;
    tail.prev = &head;

    rewrite_dll_insert(&head, &tail, 1);
    rewrite_dll_insert(&head, &tail, 3);
    rewrite_dll_insert(&head, &tail, 2);

    for (curr = head.next; curr != &tail; curr = curr->next)
        printf("%d\n", curr->data);

    // free memory
    DNode *next;
    for (curr = root.next; curr != NULL; curr = next)
    {
        next = curr->next;
        free(curr);
    }
    for (curr = head.next; curr != &tail; curr = next)
    {
        next = curr->next;
        free(curr);
    }
    return 0;
}
int four(void)
{
    // Test the function
    Node *root = NULL;
    for (int i = 1; i < 6; i++)
        sll_insert(&root, i);

    // Print the original list
    print_sll(root);

    Node *reversed = sll_reverse(root);

    // Print the reversed list
    print_sll(reversed);

    // Free the reversed list
    free_sll(reversed);
    // a call to print_sll(root) here causes a segfault: list has been freed.
    printf("success\n");
    return 0;
}

int five(void)
{
    Node *root = NULL;
    for (int i = 1; i < 6; i++)
        sll_insert(&root, i);

    print_sll(root);

    Node *del_target = find_value(root, 3);
    sll_remove(&root, del_target);

    print_sll(root);
    return 0;
}

int six(void)
{
    // initialize a doubly linked list
    DNode root;
    DNode *rootp;
    rootp = &root;
    root.data = 0;
    root.next = NULL;
    root.prev = NULL;

    // insert some values into the list
    dll_insert(rootp, 1);
    dll_insert(rootp, 4);
    dll_insert(rootp, 3);
    dll_insert(rootp, 2);
    dll_insert(rootp, 5);

    // print the list
    print_dll(root.next);

    // remove a node
    DNode *curr;
    while ((curr = rootp) != NULL && curr->data != 3)
        rootp = curr->next;
    dll_remove(&root, curr);

    print_dll(root.next);
    return 0;
}

int seven(void)
{
    // const char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    Index *index = build_index();
    Index **rootp = &index;
    // add words to the concordance
    concordance_insert(rootp, "asdf");

    print_concordance(index);
    // free memory
    free_concordance(index);
    return 0;
}

char *mystrdup(const char *s)
{
    char *p = malloc(strlen(s) + 1);
    if (p)
        strcpy(p, s);
    return p;
}
