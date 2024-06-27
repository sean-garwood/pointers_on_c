#include "../ch9.12..14.h"

int main(void)
{
    char key[KEYLEN] = {'\0'};
    char msg[MAXLEN] = {'\0'};

    // get key from user input
    if (!prepare(key))
        return 1;
    printf("Key: %s\n", key);
    encrypt(msg, key);
    decrypt(msg, key);

    return 0;
}

int initialize(char *key)
{
    const char test[] = "xxyyzz";
    strcpy(key, test);
    // printf("Enter key: ");

    // if (*fgets(key, KEYLEN, stdin) == '\0')
    // {
    //     printf("Key is empty\n");
    //     return 0;
    // }
    // remove newline
    // key[strlen(key) - 1] = '\0';
    while (*key)
    {
        if (!isalpha(*key))
        {
            printf("Key contains non-alphabetic characters\n");
            return 0;
        }
        else
        {
            *key = tolower(*key);
            key++;
        }
    }

    return 1;

    // return ( == NULL || !isalpha(*key)) ? 0 : 1;
}

int prepare(char *key)
{
    if (!initialize(key))
        return 0;

    printf("dirty key: %s\n", key);

    char key_uniques[KEYLEN] = {'\0'}; // unique chars go here

    for (int i = 0; i < (int)strlen(key); i++) // convert key to lowercase
    {
        if (strchr(key_uniques, key[i]) == NULL)       // check if key[i] is in key_uniques
            key_uniques[strlen(key_uniques)] = key[i]; // add to key_uniques
    }
    strcpy(key, key_uniques);
    fill(key);
    return 1;
}

void fill(char *key)
{
    // null out remaining chars in key
    for (int i = strlen(key); i < KEYLEN; i++)
        key[i] = '\0';
    // add remaining letters of alphabet to key
    char *alphabet = ALPHABET;
    while (*alphabet)
    {
        if (strchr(key, *alphabet) == NULL)
            key[strlen(key)] = *alphabet;
        alphabet++;
    }
}

void encrypt(char *msg, const char *key)
{
    printf("enter a message: ");
    fgets(msg, MAXLEN, stdin);
    for (int i = 0; i < (int)strlen(msg); i++)
    {
        if (isalpha(msg[i]))
        {
            if (isupper(msg[i])) // preserve case
                msg[i] = toupper(key[tolower(msg[i]) - 'a']);
            else
                msg[i] = key[msg[i] - 'a'];
        }
    }
    printf("Encrypted message: %s\n", msg);
}

// FIXIT: decrypt is not working. returns blank string.
void decrypt(char *msg, const char *key)
{
    for (int i = 0; msg[i]; i++)
    {
        if (isupper(msg[i]))
            msg[i] = toupper(ALPHABET[strchr(key, tolower(msg[i])) - key]);
        else if (!isalpha(msg[i]))
            continue;
        else
            msg[i] = ALPHABET[strchr(key, msg[i]) - key];
    }

    printf("Decrypted message: %s\n", msg);
}
