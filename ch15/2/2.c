/*
 * change ex1 so it reads/writes an entire line at a time. you may assume that
 * each line in the file should, but won't necessarily, contain 80 characters or
 * less. In other words, set the max line len to 82.
 */

#include <stdio.h>
#define MAX_LINE_LEN 82

int main(void)
{
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, stdin) != NULL) // user inputs 90 'a' chars and a newline on first call to fgets
        fputs(line, stdout);
    return 0;
}

// author's solution

// int main(void)
// {
//     char buffer[MAX_LINE_LEN];
//     while (gets(buffer) != NULL) // gets is deprecated since C11.
//         puts(buffer);
//     return 0;
// }

// still wrapping lines! No idea what is causing this behaviour. When i input
// >80 characters, it accepts and prints everything.

/*
 * ok, i finally get it. No thanks to copilot. The fgets function reads up to
 * MAX_LINE_LEN - 1 chars, then appends a null byte to the end of the buffer
 * `line`. Perfectly legal since the buffer is of size MAX_LINE_LEN. The fputs
 * call then would print the contents of line to stdout. NULL bytes are
 * invisible. NO NEWLINE IS PRINTED HERE.
 *
 * stdin is NOT FLUSHED after the first call to fgets. So the next call to fgets
 * will continue reading from index MAX_LINE_LEN - 1 of the buffer.
 *
 * I typed 90 'a' and hit enter. First call to fgets reads 81 'a' and sticks a
 * null to it and stores in `line`
 *
 * fputs then writes the contents of `line` to stdout. 81 'a' chars are printed.
 * null chars are NOT PRINTED.
 *
 * The next call to fgets reads the remaining 9 'a' chars and a newline. Then,
 * the stdin stream is empty. fgets will append another null to the data read
 * from stdin and store in `line`. fputs will then print the remaining 9 'a'
 * chars and the newline, and it's done. then we return to the top of the loop.
 *
 * My misconceptions stemmed from two things:
 *
 * 1. I thought stdin was flushed after each call to fgets. It is not.
 * 2. I thought fputs printed the first arg's contents and a newline. It does
 *    not do this! puts does, though.
 *
 * One interesting thing: when i was messing about, I accidentally hit the arrow
 * keys and they were written to stdin. then when i hit enter, the cursor was
 * placed in a very weird position.
 */
