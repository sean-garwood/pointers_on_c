/*
 * Simplify this silly code:
 */

void silly(char *message);
void serious(char *message);

void silly(char *message)
{
    char *p_str;

    for (p_str = message; *p_str != '\0'; p_str++)
        if (islower(*p_str))
            *p_str = toupper(*p_str);
}

void serious(char *msg)
{
    *msg = toupper(*msg); // doesn't matter if it's lower or upper
}
