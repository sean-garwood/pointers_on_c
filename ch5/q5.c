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

*/
