# Pointers on C

Problem sets from "Pointers on C" by Kenneth A. Reek

## References

All problems are from the book "Pointers on C" by Kenneth A. Reek.

A few of the programs are of my own creation, but are based on the problems in the book.

### Assembly

* [intel 64 arch manpages](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)
* [opcode and instruction reference for x86](http://ref.x86asm.net/)
* [x86-64 assembly language reference](https://cs.brown.edu/courses/csci1260/spring-2021/lectures/x86-64-assembly-language-reference.html#:~:text=x86-64%20assembly%20language%20is,processors%20is%20developed%20by%20Intel!)
* [Stanford CS107 x86-64 reference sheet](https://web.stanford.edu/class/archive/cs/cs107/cs107.1248/resources/x86-64-reference.pdf)

## Missing material

Questions for chapters 1-4: I did these on paper in a notebook. Don't feel like
transcribing them.

## todo

Problem(s) that I've either entirely skipped or got stuck on and moved on from.

See [todo/](./todo/) for more details.

### Skipped

8.6-8.8: Instructiuons are stupid long and kind of nonsensical.
17.6, 17.8: Who uses arrayed BSTs?

### Needs improvement

15.11: Refactor, it's a mess.
       *error handling
       * void pointers to handle generic callbacks
       *write generic traversal function to pass with trx
       * no need for inv struct--just need to init part zero
       * check on the PartData struct--it's a bit weird with the union

17.10: Deleting a node with current interface is messy.
       *need parent node
       * handle root deletion
       * new BST struct with pointer to root node?
