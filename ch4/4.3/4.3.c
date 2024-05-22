/*takes three numbers as input that represent the lengths of the sides of a
triangle and returns the type of triangle it is.*/

#include <stdio.h>
#define SIDES 3
#define EQUILATERAL 1
#define ISOSCELES 2
#define SCALENE 3

int triangle_type(int *sides);

int main(void)
{
    int sides[SIDES];
    int i;

    printf("Enter the lengths of the sides of a triangle: ");
    for (i = 0; i < SIDES; i++)
    {
        scanf("%d", &sides[i]);
    }

    switch (triangle_type(sides))
    {
    case EQUILATERAL:
        printf("Equilateral triangle\n");
        break;
    case ISOSCELES:
        printf("Isosceles triangle\n");
        break;
    case SCALENE:
        printf("Scalene triangle\n");
        break;
    default:
        printf("Invalid triangle\n");
    }

    return 0;
}

int triangle_type(int *sides)
{
    if (sides[0] == sides[1] && sides[1] == sides[2])
    {
        return EQUILATERAL;
    }
    else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2])
    {
        return ISOSCELES;
    }
    else
    {
        return SCALENE;
    }
}
