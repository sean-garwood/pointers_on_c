/*
 * write a program to create this structure:
 *
 * +---+---+     +---+---+     +---+---+     +---+---+
 * |head|----->| | 5 |----->| | 10 |----->|  | 15 | 0 |
 *
 * `----->` means "points to next object in structure"
 *
 * The first object is static and is a pointer to a structure.
 * No need to make it general; that will be covered in ch12.
 */

#include "../11.h"

int main(void)
{
    // start with a static pointer to a node
    static node *head;
    head = malloc(sizeof(node) * 3);
    node *current = head;
    if (head == NULL)
    {
        printf("Memory allocation failed\n%s", "");
        return 1;
    }
    else
    {
        head->value = 5;
        head->next = head + 1;
        (head + 1)->value = 10;
        (head + 1)->next = head + 2;
        (head + 2)->value = 15;
        (head + 2)->next = NULL;
    }
    // print the values
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
    return 0;
}
