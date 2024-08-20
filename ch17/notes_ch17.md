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
