/* Questions - Chapter 5

1. what is the type and value of the expression?

    (float)(25 / 10);

the parenthetical groupings have the highest priority:
    (25 / 10) = 2
    (float)2  = 2.0
Therefore, the type is `float` and value of the expression is 2.0.

2. what is the result of the following program?
*/
#include <stdio.h>
int func();

int func(void)
{
    static int counter = 1;
    return ++counter;
}

int main()
{
    int answer;
    answer = func() - func() * func();
    printf("%d\n", answer);
}

/*
function calls have higher precedence than any arithmetic operator, so func()
gets called three times. It is unclear whether the order of evaluation is LTR or
RTL, so the result could be:

LTR: 2 - 3 * 4 = 2 - 12 = -10
RTL: 4 - 3 * 2 = 4 - 6 = -2

Let's see what happens on this machine/compiler:

$ cc q5
$ ./q5
-10

The result is -10, implying LTR evaluation.

3. What are some uses for bitwise and shifting operators?

They are shortcuts for certain arithmetic operations, such as multiplying or
dividing by powers of 2. They are also used to manipulate individual bits in
a byte or word. This can be useful for setting or clearing flags, or for
packing multiple values into a single variable, or for masking/salting data.

They are utilized heavily in graphics programming, cryptography, and networking.
See:
* https://graphics.stanford.edu/~seander/bithacks.html
* https://www.cs.ucf.edu/~dmarino/ucf/cis3362/lectures/newlecs/BitwiseOps-Crypto.pdf

4. Is the conditional operator foraster or slower than an if statement?

it is faster. it is a single instruction, whereas an if statement is a branch
that contains at least two instructions. The conditional operator is also more
compact and easier to read, especially for simple conditions.

5. Write an assignment that sets leap_year true if `year` is a leap year.

    leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

6. which operators have side effects, and what are they?

The increment and decrement operators have side effects. They modify the value
either before or after the expression is evaluated. The comma operator also has
side effects. It only returns the value of the last expression, but it evaluates
all expressions in LTR order.

7. What is the result of this fragment?
*/

int a = 20;
// ...
if (1 <= a <= 10)
    printf("a is between 1 and 10\n");
else
    printf("a is not between 1 and 10\n");

/*
Easy. The expression is evaluated from LTR, so:

1 <= a evals to 1
1 <= 10 evals to 1
'a is between 1 and 10' is printed to the console, despite a not being between 1
and 10.

8. rewrite this frag to eliminate redundnancies:
    a = f1(x);
    b = f2(x + a);
    for (c = f3(a, b); c> 0; c = f3(a, b)){
        // do something
        a = f1(++x);
        b = f2(x + a);
    }

    is the same as:

    while (a = f1(x), b = f2(x + a), c = f3(a, b), c > 0)
    {
        // do something
        a = f1(++x);
        b = f2(x + a);
    }

9. Does the following loop do what it's supposed to?

nonzero = 0;
for (i = 0; i < ARRAY_SIZE; i +=1)
    nonzero += array[i];
if (!nonzero)
    printf("Values are all zero\n");
else
    printf("Values are not all zero\n");

No. given

    int array[ARRAY_SIZE] = {-1, 0, 1};

this would evaluate to 0, even though the values are not all zero.
a better approach would be to use a flag:

    all_zero = 1;
    for (i = 0; i < ARRAY_SIZE; i += 1)
    {
        if (array[i] != 0)
        {
            all_zero = 0;
            break;
        }
    }
    if (all_zero)
        printf("Values are all zero\n");
    else
        printf("Values are not all zero\n");

10. Given

    int a = 10, b = -25;
    int c = 0, d = 3;
    int e = 20;

binary:

a =    0 1010
-b =  1 1001
b = 1..0 0111
c = 0
d = 0 0011
e = 1 0100

Evaluate each of the following expressions. Note any side effects. Evaluate each
in their own scope.

* b
    -25
* b++
    -25 ; b becomes -24 after the expression is evaluated
* --a
    9 ; no side effects, a is decremented and the resultant value is 9
* a / 6
    1
* b % 10
    -5
* a << 2
    a = 10  so 0b1010 << 2 = 0b101000 = 40
* b >> 3
    b = -25
    assuming 2's complement
        25 = 0b00000000 00000000 00000000 00011001
        -25 = 0b11111111 11111111 11111111 11100111
    b >> 3 = 0b11...100
    -4
* a > b
    1
* b = a
    10; b is assigned the value of a
* b == a
    0
* a & b
    a = 10 = 000...0 1010
    b = -25 = 111...0 0111
    01010
    00111
    -----
    00010
    2
* a ^ b
    XOR truth table:
        a    b    a ^ b
        0    0    0
        0    1    1
        1    0    1
        1    1    0

    01010
    00111
    -----
    01101
    13
* a | b
    OR truth table:
        a    b    a | b
        0    0    0
        0    1    1
        1    0    1
        1    1    1

    01010
    00111
    -----
    01111
    15
* ~b
    the ~ operator inverts all bits
    -25 = 0b11111111 11111111 11111111 11100111
    ~b = 0b00000000 00000000 00000000 00011000
    24
* c && a
    0
* c || a
    1
* b ? a : c
    a
* a += 2
    12 ; a is assigned the value 12
* b &= 20
    equivalent to b = b & 20
    20 = 0b00000000 00000000 00000000 00010100
    -25 = 0b11111111 11111111 11111111 11100111
    the only column that has two ones in it is the 5th column, so the result is
    10000 = 16 ; b is assigned the value 16
* b >>= 3
    equivalent to b = b >> 3
    0b1...1100
* a %= 6
    4 ; a is assigned the value 4
* d = a > b
    1 ; d is assigned the value 1
* a = b = c = d
    3 ; a, b, and c are all assigned the value 3
* e = d + ( c = a + b )
    e = d + (-15) ; c is assigned the value -15
    e = 3 + (-15) = -12 ; e is assigned the value -12
    -12
* etc...
* b >> a - 4
    a - 4 = 10 - 4 = 6
    b >> 6
    -1

* etc..

* a & 0x1 == b & 0x1
    01010
    00001
    -----
    00000

    00111
    00001
    -----
    00001

    simplifies to `0 == 1`, which is 0
    0
* a | b << a & b

    << is higher precedence than & and & is higher precedence than |
    b << a is first to be evaluated
        b = -25 = 0b11111111 11111111 11111111 11100111
        shift all the bits left by 10 yields
               0b11111111 11111111 10011100 00000000 = b << a
        flip = 0b00000000 00000000 01100011 11111111
        +1   = 0b00000000 00000000 01100100 00000000 = 2**14+2**13+2**10
                                                     = 16384 + 8192 + 1024
                                                     = 25600
        plus one = 0b00000000 00000000 00011001 00000000 = 256 + 1024 + 2048 = 3328
        invert sign = -3328
        b << a y8elds -3328
    a | 0b11111111 11111111 10011100 00000000 & -25
    now, the & is evaluated
        0b11111111 11111111 10011100 00000000
    &   0b11111111 11111111 11111111 11100111
    =   0b11111111 11111111 10011100 00000000

    finally, the | is evaluated against this result.
        0b00000000 00000000 00000000 00001010
    |   0b11111111 11111111 10011100 00000000
        0b11111111 11111111 10011100 00001010
    convert this back to decimal by:
        flip = 0b00000000 00000000 01100011 11110101
        add 1 = 0b00000000 00000000 0110001111110110 = 25590
        invert sign = -25590
    -25590 (phew!)
* a > c && ++ a > b
* a > c || ++ a > b
* ! ~ b++
* b++ & a <= 30
* a-b, c +=d, e -c
* a >>= 3 > 0
* a <<= d > 20 ? b && c++ : d--


**/
