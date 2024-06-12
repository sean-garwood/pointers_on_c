/*
 * write a function called `identity_matrix` that takes a 10x10 matrix of ints
 * as its only argument and returns a bolean value indicating whether the matrix
 * is an identity matrix.
 */
#include <stdio.h>
int identity_matrix(int matrix[10][10]);

int main(void)
{
    // set up a test matrix
    int id_matrix[10][10] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

    printf("is an id matrix: %d", identity_matrix(id_matrix));
    return 0;
}

int identity_matrix(int matrix[10][10])
{
    // value to return
    int is_id_matrix = 1;
    /*
     * start with the first 'row', which is the 0th element of the matrix
     lets be fancy and set a pointer to the first row
     */
    int i = 0;            // this is the index that will be incremented.
    int *row = matrix[i]; // the ith row of the matrix
    while (i < 10)
    {
        if (*row != 1)
        {
            is_id_matrix = 0;
            break;
        }
        i++;
    }
    return is_id_matrix;
}
