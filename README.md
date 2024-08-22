# Pointers on C
Problem sets from "Pointers on C" by Kenneth A. Reek

## todo

Problem(s) that I've either entirely skipped or got stuck on and moved on from.

See [todo/](./todo/) for more details.

### Skipped

8.6-8.8: Instructiuons are stupid long and kind of nonsensical.
17.6, 17.8: Who uses arrayed BSTs?

### Needs improvement

15.11: Refactor, it's a mess.
       * error handling
       * void pointers to handle generic callbacks
       * write generic traversal function to pass with trx
       * no need for inv struct--just need to init part zero
       * check on the PartData struct--it's a bit weird with the union

17.10: Deleting a node with current interface is messy.
       * need parent node
       * handle root deletion
       * new BST struct with pointer to root node?
