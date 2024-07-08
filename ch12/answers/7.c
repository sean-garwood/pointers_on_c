#include "../12.h"

int concordance_insert(Index **rootp, const char *word)
{
    char letter = word[0];
    Index *root = *rootp;
    Index *letter_index = find_index(root, letter);
    return insert_word(&letter_index->words, word);
}

Index *new_index(char letter)
{
    // create a new index node
    Index *new_index = safe_malloc(sizeof(Index));

    new_index->letter = letter;
    // new_index->next = NULL;
    // new_index->words = NULL;
    return new_index;
}

Index *build_index(void)
{
    Index *root = new_index('a');
    Index *current = root;
    for (char letter = 'b'; letter <= 'z'; letter++)
    {
        Index *new = new_index(letter);
        current->next = new;
        current = new;
    }
    return root;
}

Index *find_index(Index *root, char letter)
{
    Index *current = root;
    while (current != NULL && current->letter != letter)
        current = current->next;
    return current;
}

// return 0 if already in list, 1 if inserted
int insert_word(WNode **rootp, const char *word)
{
    WNode *new = safe_malloc(sizeof(WNode));
    WNode *root = *rootp;

    // go to right spot
    if (root == NULL)
    {
        *rootp = new;
        new->next = NULL;
    }
    else
    {
        WNode *current = root;
        while (current->next != NULL && strcmp(current->next->word, word) < 0)
            current = current->next;
        if (strcmp(current->word, word) == 0)
        {
            free(new);
            return FALSE;
        }
        new->next = current->next;
        current->next = new;
    }
    new->word = mystrdup(word);
    return TRUE;
}

void print_concordance(Index *root)
{
    Index *current = root;
    while (current != NULL)
    {
        printf("%c: ", current->letter);
        for (WNode *current_word = current->words; current_word != NULL; current_word = current_word->next)
            printf("%s ", current_word->word);
        printf("\n");
        current = current->next;
    }
}

void free_concordance(Index *root)
{
    Index *current = root;
    while (current != NULL)
    {
        WNode *next_word;
        for (WNode *current_word = current->words; current_word != NULL; current_word = next_word)
        {
            next_word = current_word->next;
            free(current_word);
        }
        Index *next_index = current->next;
        free(current);
        current = next_index;
    }
}
