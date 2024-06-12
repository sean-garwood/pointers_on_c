/*
 * modify the `identity_matrix` function so it can take matrices of any size by
 * flattening the array. here's the original:
 *
 *
 */
#include <stdio.h>
int identity_matrix(int matrix[10][10]);
int id_matrix(int *matrix, int size);

int identity_matrix(int matrix[10][10])
{
    int is_id_matrix = 1;
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

/*
 * first arg should be a pointer to an int, and the second arg should specify
 * the size of the matrix
 */

int id_matrix(int *matrix, int size)
{
    int is_id_matrix = 1;
    int i = 0;                    // this is the index that will be incremented.
    int *row = matrix + i * size; // the ith row of the matrix
    while (i < size)
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

int main(void)
{
    // set up a test matrix
    const int test_matrix[5][5] = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1}};

    printf("is an id matrix: %d", id_matrix((int *)test_matrix, 5));
    return 0;
}
