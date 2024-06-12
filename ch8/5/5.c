/*
 * if A is a matrix of x rows and y columns, and B is a matrix of y rows and z
 * columns, then A and B can be multiplied. The product of AB is a matrix C with
 * x rows and z columns. Each element of C is the sum of the products of the
 * elements of the ith row of A and the jth column of B.
 *
 * write a function to multiply two matrices with the prototype:
 */

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);

/*
 * m1 will be a matrix with x rows, and y columns. m2 will be a matrix with y
 * rows and z columns. r will be the result matrix with x rows and z columns.
 */

#include <stdio.h>

int main(void)
{
    const int test_matrix1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    const int test_matrix2[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}};
    int result_matrix[2][2];
    matrix_multiply((int *)test_matrix1, (int *)test_matrix2,
                    (int *)result_matrix, 2, 3, 2);
    printf("result matrix:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < z; j++)
        {
            int sum = 0;
            for (int k = 0; k < y; k++)
            {
                sum += m1[i * y + k] * m2[k * z + j];
            }
            r[i * z + j] = sum;
        }
    }
}
