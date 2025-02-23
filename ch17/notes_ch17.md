# Chapter 17 Notes

See the [examples](./ex/) directory for examples of stack and queue
implementations.

## Binary search trees

### Algorithm

The searching alorithm is recursive:

* check if empty
  * True: value not in subtree
  * False: check if in root
    * True: value found, end
    * False: compare values
      * less: search left subtree
      * greater: search right subtree

### Traversal

There are three types of tree traversals:

1. Pre-order
1. Post-order
1. Breadth-first

#### Pre-order (NLR)

* Examine the value in the node
* recursively traverse left and right subtree

e.g. ______________[20]
___________________/  \
________________[12]  [25]
_______________/   \
_____________[5]  [16]

20 -> not empty, continue left
12 -> not empty, continue left
5 -> not empty, continue left
[nil] -> back to root, go right
16 -> back to root
...back at 12, both subtrees done, back to root
...back at 20, left subtree done: go right
25 -> not empty, continue left
[nil] -> back to root, continue right
[nil] -> back to root -> all subtrees examined

the pre-order sorting of this BST is therefore:

20, 12, 5, 16, 25.

#### In-order (LNR)

* Examine the value in the node
* recursively traverse left subtree, then right subtree

e.g. ______________________________[20]
___________________________________/  \
________________________________[12]  [25]
_______________________________/   \
_____________________________[5]  [16]

Yields:

5, 12, 16, 20, 25

#### Post-order (LRN)

e.g. ______________________________[20]
___________________________________/  \
________________________________[12]  [25]
_______________________________/   \
_____________________________[5]  [16]

Yields

5, 16, 12, 25, 20

9 5 17 16 12, 26, 29, 28, 25, 20 for the big tree (figure 17.1 in the book)

#### Breadth-first/level-order ()

Examine nodes in level-order.

**Iterative. Requires a queue.**

Revisited in exercises.

### Arrayed BSTs

Not very common, seems silly.

* fixed len of array in C limits num of elements.
  * can realloc larger space/copy values when overflow
* use subscripts to locate parents and children of a particular value.

#### location rules

One-based index:

* parent of node `N` is node `N / 2`
  * int division in c truncates fractional remainder and returns floor
* left child of `N` is node `2N`
* right child of `N` is `2N + 1`

Zero-based index:

* parent: `(N + 1) / 2 - 1`
* L: `2N + 1`
* R: `2N + 2`

#### Static Array BST Implementation

[sarray_tree.c](./ex/tree/sarray_tree.c)

* Uses simpler rules for determining children
  * sizeof array is one larger than 'advertized' size; first element ignored.
* Functions compute the L-/R-children of a node
  * portability
  * readability
* a value of `0` denotes an unused node.
  * can't do this if 0 is a member of the set of possible node values
    * can use a boolean/sparse vector to show which nodes are active instead
    * must then allocate members dynamically

#### problems

space is wasted, eg

* sizeof arr is 100
* members 1..7 inserted
  * stored in 1, 2, 4, 8, 16, 32, 64 -> 8 cannot be inserted (at index 128)
  * if inserted  in 4, 2, 1, 3, 6, 5, 7 => indices 1..7
* must double array size when tree is unbalanced.

Long story short: use a linked tree, for god's sake. I guess I'll do the
exercise anyway to feel true pain.

### Linked BSTs

Eliminates the problem of unused space by dynamically allocating memory to hold
each new value and linking thes structs together into a tree. No memory goes
unused!

* Need each `node` struct to hold a `left` and `right` pointer to its respective
  children
* entire array is replaced by a single pointer to the root node
  * initially set to `NULL` to indicate an empty tree.

#### Linked BST implementation

The `insert` function uses two pointers:

1. examine nodes in the tree to find proper place to insert new value
1. whatever link points to the node currently being examined
    * when a leaf is reached, this must be changed

Walk down the tree, going left or right according to comparison

* left is less
* right is more

...until a leaf is reached.

* create new node
* insert into tree

#### differences from static array BST

`find` only checks for membership; doesn't return value of node.

#### other ideas

* it is often helpful for each node to have a pointer to its parent.
  * `find` could then return a *pointer* to the tree node, rather than its
    value, allowing for its use in other traversals.
* `destroy_tree` left as an exercise.

## Implementation improvements

The [example implementations](./ex/) illustrate ADTs, but are inadequate for use
in real programs.

### Genericity

*The ability to write a set of functions in which the types of the data have not
yet been decided.*

One gap in C is the fact that it is very hard to act generically upon data
types, even if they are very similar, due to the strongly typed syntax and
variance in sizes of data types.

#### Generic stack implementation

[g_stack.h](./ex/stack/g_stack.h) contains a `#define` statement whose body is
the entire implementation of an arrayed stack.

The args to the macro are

* `STACK_T`: The type of value to be stored in the stack
* `SUFFIX`: The name of the type prefixed with an underscore
* `STACK_SIZE`: The size of the static array that will hold the stack

[g_client.c](./ex/g_client.c) is an implementation of a static array stack
implementation. It instantiates two stacks: one of floats, and one of ints.

##### Issues

The example above does not allow for creation of more than one stack of the same
type; it would need to be modified to take an `ID` argument

Also, the following responsibilities fall on the user with this implementation:

* decide on naming convention to avoid name clashes amongst stacks of different
  types
* create only one set of stack routines for each data type
* use proper name when accessing a stack
* pass proper stack struct to functions

## Summary

Three techs for obtaining memory for abstract data types:

1. static array
  fixed size
2. dynamically allocated array
  size computed at runtime, realloc if needed during
3. dynamically allocated linked struct
  no limits. Just use this.

### Stacks

Stack->LIFO, Queue->FIFO

stack can set `stack_t top_element = -1`

push

1. increment `top_element`
1. store value in array

pop

1. remove/return value
1. decrement `top_element`

#### Dynamic stacks

Two add'l fns required:

1. create stack to specified size
1. destroy stack (pop all, free memory)

#### Singly-linked list stack

Values pushed to beginning
Stack popped by removing first element
memory freed during runtime

### Queues

Stack->LIFO, Queue->FIFO

Circular arrays more appropriate than ordinary array: when a var used as a
subscript for a circular array is incr/decr past end of array, its value wraps
to zero.

To determine when full: use var that counts number of inserted values
To use front/rear pointers: must always be at least one empty element in the
array.

### BST

A binary search tree is a struct that is either empty or has a value and up to
two (left and right) child BSTs.

Big-O is much shorter than O(n); i think it's O(log n) average

#### caution: beware orphaned nodes

#### BST traversal

Four orders:

1. Pre-order: NLR

* process node
* traverse left subtree
* traverse right subtree

2. In-order: LNR

* traverse left subtree
* process node
* traverse right subtree

3. Post-order: LRN

* traverse left subtree
* traverse right subtree
* process node

4. Breadth-first: NLR*

Don't use silly arrays to do this; use a linked struct

* process node
* process left child
* process right child
* root = (left.nil?) ? right : left

#### Problems

1. only have one stack, queue or tree

Solved by seaparating allocation of the struct from the functions that
manipulate it.

The resulting loss of encapsulation increases the chance of errors.

2. Inability to declare stacks, queues, trees off diff types

Separate copy of ADT funs for each type makes maintaining code more difficult.

Better to implement code with a #define, which is then expanded with each type.
choose the naming convention carefully.

Make ADT typeless by casting to `void *`, but lose type checking.

Avoid name clashes among versions

## Cautions

1. Use of assertions to check for mem allocations is dangerous. just check if
   null pointer was returned instead.
1. calcs for arrayed binary tree assume array subscripts begin at one.
1. Encapsulating data in module that services it prevents client from accessing
   the data incorrectly.
1. no type checking with typless/generic functions

## tips

1. Avoid fns with side effects => program easier to understand
1. Interface should not divulge details of implementation
1. Parameterized data types are more malleable
1. Only advertized interface for a module should be public
1. Use assertions to guard against (unrecoverable) illegal ops
1. Diff implementations should adhere to a comon interface => interchangeability
1. Reuse, don't rewrite. Keep it DRY
1. Iteration more efficient than tail recursion, but more strict checks/error
   handling required.
