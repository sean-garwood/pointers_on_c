#include "../12.h"

int concordance_insert(Index **rootp, char *word)
{
    /*
     * **index: pointer to an index pointer, which either:
         1. points to a null pointer (e.g. the root index's *Index)
                    outcome: a new index node is created and the word is added to it.
         2. points to a pointer to an index node.
                outcome: walk down the list of index nodes until the correct index is found.
                          If the index is not found, create a new index node.
                          Add the word to the index node.
     */

    // check if the root is null
    Index *current = *rootp; // dereference the index pointer to get the index node or null
    char letter = *word;

    while (current != NULL && current->letter < letter)
        current = current->next;

    // on the right index, eg letter == current->letter
    // current is pointing to null

    if (current == NULL)
    {
        // create a new index node
        Index *new = new_index(letter);
        new->next = *rootp;
        *rootp = new;
        current = new;
    }
    else if (current->letter != letter)
    {
        // create a new index node
        Index *new = new_index(letter);
        new->next = current->next;
        current->next = new;
        current = new;
    }

    /*
     * here are some functions that might be handy:

     dereference the index pointer to get the index node

     */
}

Index *new_index(char letter)
{
    // create a new index node
    Index *new_index = safe_malloc(sizeof(Index));

    new_index->letter = letter;
    new_index->next = NULL;
    new_index->words = NULL;
    return new_index;
}
