# Dynamic Text Editor Using a Singly Linked List

## Practical title

**Dynamic Text Editor using a Singly Linked List**

## Problem statement

Create a basic text editor that stores text dynamically using a singly linked list. Each node holds one character and a pointer to the next node. The editor should support inserting a character at a chosen position, deleting a character, displaying the text, and searching for a character or substring.

This README assumes positions are one-based and that insertion or deletion at a position traverses the list from its head. A singly linked list grows as characters are added, so the editor does not need a fixed-size character array.

## Objective

- Represent text as a dynamically allocated singly linked list.
- Practice node creation, traversal, insertion, and deletion.
- Perform simple text operations by position.
- Release allocated nodes when the text is cleared or the program exits.

## Algorithm / approach

Maintain a pointer to the head node. Each node stores a character and a link to the next node.

### Insert a character

1. Validate the insertion position (from 1 through current length + 1).
2. Create a node containing the new character.
3. If inserting at position 1, point the new node to the current head and update the head.
4. Otherwise, traverse to the node immediately before the insertion point.
5. Link the new node into the list.

### Delete a character

1. Validate that the position is between 1 and the current text length.
2. If deleting position 1, move the head to the next node.
3. Otherwise, traverse to the node immediately before the target.
4. Bypass the target node and free its memory.

### Display text

Traverse from the head to the end of the list, printing each node's character in order.

### Search text

Traverse the list and compare characters or candidate substrings. For substring search, a straightforward implementation may check each possible starting position.

## Data structure / concept used

- **Singly linked list:** A dynamic sequence of nodes, with each node pointing to its successor.
- **Node:** Contains one character and a pointer to the next node.
- **Dynamic memory allocation:** Creates nodes as text is inserted and releases them when deleted.
- **Pointers and traversal:** Maintain the head and reach positions by following links.

## Test cases

| Case | Operation | Expected result |
|---|---|---|
| 1 | Insert `H`, `i` at the end | Text becomes `Hi`. |
| 2 | Insert `!` at position 2 in `Hi` | Text becomes `H!i`. |
| 3 | Delete position 2 from `H!i` | Text becomes `Hi`. |
| 4 | Delete the first character from `Hi` | Text becomes `i`; the head is updated. |
| 5 | Display an empty list | Display an empty string or a clear empty-text message. |
| 6 | Insert at position 1 in an empty list | The new character becomes the head. |
| 7 | Use position 0 or a position beyond the valid range | Reject the operation without changing the text. |
| 8 | Search for an existing and a missing substring | Report found for the existing substring and not found for the missing one. |

## Sample input and output

Assume commands use one-based positions and quote a character or text where needed.

### Sample input

```text
INSERT 1 "H"
INSERT 2 "i"
INSERT 2 "!"
DISPLAY
DELETE 2
DISPLAY
```

### Sample output

```text
Text: H!i
Character at position 2 deleted.
Text: Hi
```

The command format is illustrative and can be adapted to the implementation.

## Time complexity

Let `n` be the number of characters in the text.

- **Insert at the head:** O(1)
- **Insert at a given position:** O(n) in the worst case due to traversal.
- **Delete at the head:** O(1)
- **Delete at a given position:** O(n) in the worst case due to traversal.
- **Display text:** O(n)
- **Search for a character:** O(n)
- **Search for a substring of length `m` with a simple repeated traversal:** O(n × m) in the worst case.

## Space complexity

The linked list uses **O(n)** space for `n` characters. Each character requires a node and a next pointer. An individual insert or delete uses **O(1)** additional space, excluding the newly allocated node during insertion.

## Conclusion

A singly linked list lets the editor grow and shrink its text dynamically. It supports efficient changes at the head, while edits at arbitrary positions require traversal. This structure is useful for learning linked-list operations; more advanced editors can use gap buffers, ropes, or doubly linked structures for faster editing and navigation.
