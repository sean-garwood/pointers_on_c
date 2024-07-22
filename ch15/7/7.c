/* A certain data file contains the ages of family members.

 The ages of the members of one family are all on the same line, and are
 separated by whitespace.

 For example, this data:

 45 42 22
 36 35 7 3 1
 22 20

 describes three families having three, five and two members, respectively.

 write a program that computes the average age of each famil represented in a
 file of this sort.

 It should print the average age using the `%5.2f` format, followed by a colon
 and the input data.

 Assume that no family contains more than 10 members.

    This implies a max line length of 4 * 9 + 3 = 39, since no one ever lives
    over 999 years old.*/

/*
 * pseudocode

   open file
   while not eof
   read line
     split line into tokens
     collect ages
     compute average of ages
     print formatted string using "average age is %5.2f: %s\n"
   close file
   return 0 */

#include "7.h"

#define MAX_LINE_LEN 40

int main(void)
{
    FILE *input;
    char line[MAX_LINE_LEN];      // hold line of input
    char line_copy[MAX_LINE_LEN]; // copy of the line for processing
    float average;
    input = fopen(INPUT_FILE, "r"); // open file for reading
    if (input == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, input) != NULL)
    {
        strcpy(line_copy, line);          // Make a copy of the line before processing
        average = average_age(line_copy); // get average age using the copy
        printf("average age is %5.2f: %s\n", average, line);
    }

    fclose(input); // Close the file after processing
    return 0;
}

float average_age(char *line)
{
    float age, sum = 0.0;
    int count = 0;
    char *token;

    token = strtok(line, " "); // get first token
    while (token != NULL)
    {
        sscanf(token, "%f", &age); // convert token to int
        sum += age;                // add age to sum
        count++;                   // increment count
        token = strtok(NULL, " "); // get next token
    }

    return sum / count; // return average
}
