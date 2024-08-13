# Inventory

Question 15.11 from *Pointers On C*

## Prompt

Write a program to keep track of an inventory of parts and their value.

Each part has a description that may be from 1-20 chars in length.

When a new part is added to the inventory, it is assigned the next available part number.
The first part number is 1.

Store the quantity on hand and the total value for each part.

Take a single arg from cli: name of inventory file. if it doesn't exist, an empty file is created.

Prompts for trx and processes them one by one.

## Transactions

### new

  Enters part into system.

  Subcommands: description, quantity, cost-each

- `new description,quantity,cost-each`
  - `new` trx enters a new part into the system.
  - `description` is the part description char[20].
  - `quantity` is the number of parts initially placed into inventory; it may not be negative. Unsigned int.
  - `cost-each` is the cost of each part. It is not an error for a new part to have the same description as an existing part. Unsigned float (2 decimal places).

  Compute and save total value of these parts as quantity * cost-each.
  
  Next available part num is assigned to each new part (global unsigned int).

  Nums of deleted parts are reused when new parts are entered.

### buy

  Adds additional units to an existing part.
  
  `buy part-number,quantity,cost-each`
  
- `part-number`: number of the part.
- `quantity`: number of parts obtained.
- `cost-each`: cost of each part.

### sell

  Removes units from an existing part in inventory.
  
  `sell part-number,quantity,price-each`
  
- `part-number`: number of the part.
- `quantity`: number of parts sold (can't be more than quantity on hand or negative).
- `price-each`: price obtained for each of the parts sold.

### delete

  `delete part-number` removes the part from the inventory.

### print

  Prints the part number, description, quantity on hand, and the total value of all such parts on hand.
  
  `print part-number`
  
  `print all` prints all parts in the inventory in tabular form.

## Unary Commands

`total` computes and prints total value of all parts in inventory.
`end` ends the program.

## hints

- use the part number to determine where in the inv file a part is written.
  - first num is 1, so use part num 0 to store other info (maybe a pointer to
    item 1? total value?)
- when deleting part, set desc to an empty string.
