#include "../12.h"

/*
 * write a fn that counts the number of nodes in a singly linked list.

 It should take a pointer to the first node in the list as its only arg.

 What must you know in order for this to be possible?

     Well, I need to konw that the nodes contain pointers to the next node in the list and that it is Null terminated.

 What other jobs can this fn perform?

 Not much, but it could be used to check if the list is empty.

 */

int sll_count(register Node *node)
{
    int i = 0;
    while (node != NULL)
    {
        i++;
        node = node->next;
    }
    return i;
}
