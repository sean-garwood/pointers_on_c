#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define FAIL -1

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
} DNode;

typedef struct wnode
{
    const char *word;
    struct wnode *next;
} WNode;

// list of letters
typedef struct index
{
    char letter;
    struct index *next;
    struct wnode *words;
} Index;

/*********************Chapter Qs***********************************************/
int sll_insert(register Node **linkp, int new_value);
int rewritten_sll_insert(register Node **linkp, int new_value);
int dll_insert(register DNode *rootp, int value);
/******************************************************************************/

/*********************Exercise 1*********************************************
 * write a fn*/

int sll_count(register Node *node);

/* that counts the number of nodes in a singly linked list.
 *
 *  It should take a pointer to the first node in the list as its only arg.
 *
 *  What must you know in order for this to be possible?

    - Well, I need to konw that the nodes contain pointers to the next node in
      the list and that it is Null terminated.

 *  What other jobs can this fn perform?

    - Not much, but it could be used to check if the list is empty
 *******************************************************************************/

/*********************Exercise 2*********************************************
 * write a fn*/

Node *find_value(register Node *node, int value);

/* to locate a particular value in an unordered, singly linked list.
 * return a pointer to the node containing the value or NULL if the value is not
 * found.
 *
 * Are any changes needed in order to make the fn work on an OSLL?

    - no changes needed to make this work on an ordered list.
 *******************************************************************************/

/*********************Exercise 3*********************************************
 * rewrite `dll_insert` so that the head and tail pointers are passed in as
 * separate pointers rather than as part of a root node.
 *
 * What effect does this change have on the logic of the function?
     - It makes it all ooey gooey and gross.
*******************************************************************************/
int rewrite_dll_insert(register DNode *head, register DNode *tail, int value);

/*********************Exercise 4*********************************************
 * Write a function */

Node *sll_reverse(register Node *root);

/* that reverses a singly linked list. The function should return a pointer to
 * the new root node.
 *
 * Link field of the last node in the list will contain NULL.
 *
 * In event of empty list (root == NULL), the function should return NULL.
 *******************************************************************************/

/*********************Exercise 5*********************************************
 * write a fn */

int sll_remove(Node **rootp, Node *node);

/* that removes a node from a singly linked list. The function should return
 * FALSE if the node was not found in the list, TRUE otherwise.
 *
 * Is there any advantage in taking a pointer to the node to remove as opposed
 * to taking the value? Not that I can think of. Any node not in the list would
 * be inaccessible to the caller, because the list is singly linked to other
 * nodes in the list.
 *******************************************************************************/

/*********************Exercise 6*********************************************
 * write a fn */

int dll_remove(DNode *rootp, DNode *node);

/* that removes a node from a doubly linked list. The function should return
 * FALSE if the node was not found in the list, TRUE otherwise.
 *******************************************************************************/

/*********************Exercise 7*********************************************
 * write a fn */

int concordance_insert(Index **index, const char *word);

/* that inserts a new word into a concordance list.
 * the structure of the list is:
 * a struct of type Index for each letter of the alphabet.
 * each Index struct contains a pointer to a singly linked list of words that
 * begin with the letter stored in the Index struct.
 * if the letter is not already in the list, a new Index struct is created and
 * inserted in the list in alphabetical order.
 *
 * Then, the word is inserted into the singly linked list of words that the
 * Index struct points to.
 * This is achieved by walking down the list until the word-to-insert is greater
 * than curr_word->next->word
 * NULL is always less than any word.
 *
 *******************************************************************************/

/*                       helpers.c                                           */
void print_sll(register Node *root);
void free_sll(register Node *root);
void print_dll(register DNode *root);
void print_concordance(Index *index);
void free_concordance(Index *root);
void *safe_malloc(size_t size);
Index *new_index(const char letter);
Index *build_index(void);
Index *find_index(Index *root, char letter);
int insert_word(WNode **rootp, const char *word);
char* mystrdup(const char* s);
/* procedures */
int four(void);
int five(void);
int six(void);
int seven(void);
