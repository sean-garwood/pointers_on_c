#include "ch9.h"
// alphabet array to build key
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define KEYLEN 27

/*
 * write a fn
 */
int prepare(char *key);

/*
 * which accepts a string that will act as a key to encode a string.
 *
 * The key will encode the message thus:
 *
 * 1. drop duplicate chars by retaining the first occurrence only
 * 2. align the key with the alphabet
 * 3. append remaining letters of alphabet to aligned key
 *
 * pseudocode:
 *
 * 1. Convert all letters to lowercase.
 * 2. Drop duplicate chars from the key.
 * 3. create key array of 26 chars and a null terminator.
 * 4. add key to key array.
 * 5. add remaining letters of alphabet to key array.
 * 6. return true result if successful.
 *    a. return false if key is empty or contains non-alphabetic chars.
 */

int initialize(char *key);
void fill(char *key);
/* then, write the fn */
void encrypt(char *msg, const char *key);

/* which uses the key to encrypt chars in plaintext. Non-alphabetical chars
remain unchanged. Case of plaintext is to be preserved. finally, write */

void decrypt(char *msg, const char *key);

/* which decodes cipher. */
