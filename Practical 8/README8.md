# Binary Search Tree Operations for an Online Directory System

## Practical title

**Binary Search Tree Operations for an Online Directory System**

## Problem statement

Create a simple online directory that stores contact records in a Binary Search Tree (BST). Each record contains a contact name and related details such as a phone number or email address. Use the contact name as the key for ordering and searching.

The system should support inserting a contact, searching for a contact, deleting a contact, and displaying contacts in alphabetical order. Contact names must be compared consistently; this README assumes case-insensitive alphabetical comparison and unique names.

## Objective

- Represent directory entries using BST nodes.
- Implement insertion, search, and deletion by contact name.
- Display contacts in alphabetical order using inorder traversal.
- Understand how a BST's shape affects operation performance.

## Algorithm / approach

Each node stores a contact record and pointers to its left and right child nodes. Keys smaller than a node's name go to its left subtree; larger keys go to its right subtree.

### Insert a contact

1. If the current subtree is empty, create a node for the contact.
2. Compare the new contact's name with the current node's name.
3. Recurse or iterate into the left subtree if it is smaller, or into the right subtree if it is larger.
4. If the name already exists, update the existing record or report a duplicate according to the chosen policy.

### Search for a contact

1. Start at the root.
2. If the target name matches the current node, return the contact.
3. If the target is smaller, continue in the left subtree; otherwise, continue in the right subtree.
4. If a null child is reached, report that the contact was not found.

### Delete a contact

Search for the contact, then handle one of these cases:

1. **No children:** Remove the node.
2. **One child:** Replace the node with its child.
3. **Two children:** Replace its key and record with its inorder successor (the smallest node in its right subtree), then delete the successor from that subtree.

### Display contacts

Perform an inorder traversal: visit the left subtree, display the current contact, then visit the right subtree. This prints contacts in sorted order by name.

## Data structure / concept used

- **Binary Search Tree:** Each node has a key and up to two child links.
- **Contact record:** Stores a name and details such as phone number and email.
- **Dynamic memory / references:** Nodes are added and removed as the directory changes.
- **Tree traversal:** Inorder traversal produces sorted output.
- **Key comparison:** Contact names determine placement and search direction.

## Test cases

| Case | Operation | Expected result |
|---|---|---|
| 1 | Insert Mira, Asha, Ravi | All three contacts are stored. |
| 2 | Search for Asha | Return Asha's contact details. |
| 3 | Search for a missing name | Report contact not found. |
| 4 | Display after inserting Ravi, Asha, Mira | Show Asha, Mira, Ravi in alphabetical order. |
| 5 | Insert a duplicate name | Update or reject it consistently with the duplicate policy. |
| 6 | Delete a leaf node | Remove the contact without affecting other entries. |
| 7 | Delete a node with one child | Link its parent to its child. |
| 8 | Delete a node with two children | Replace it with its inorder successor and preserve BST ordering. |
| 9 | Search or delete in an empty directory | Report not found without error. |

## Sample input and output

Assume commands are `INSERT name phone`, `SEARCH name`, `DELETE name`, and `DISPLAY`.

### Sample input

```text
INSERT Mira 555-0102
INSERT Asha 555-0101
INSERT Ravi 555-0103
SEARCH Asha
DISPLAY
DELETE Mira
DISPLAY
```

### Sample output

```text
Contact added: Mira
Contact added: Asha
Contact added: Ravi
Found: Asha, 555-0101
Directory (alphabetical):
Asha 555-0101
Mira 555-0102
Ravi 555-0103
Contact deleted: Mira
Directory (alphabetical):
Asha 555-0101
Ravi 555-0103
```

The command and output format is illustrative and can be adapted to the implementation.

## Time complexity

Let `h` be the height of the tree and `n` the number of contacts.

- **Insert:** O(h)
- **Search:** O(h)
- **Delete:** O(h)
- **Inorder display:** O(n)

For a reasonably balanced tree, insert, search, and delete take **O(log n)** on average. In the worst case, an unbalanced tree can have height `n`, making these operations **O(n)**.

## Space complexity

The BST stores **O(n)** nodes for `n` contacts. Insert and search use **O(h)** auxiliary space if implemented recursively, or **O(1)** traversal space if implemented iteratively. Recursive deletion and inorder traversal also use **O(h)** call-stack space.

## Conclusion

A Binary Search Tree organizes directory contacts by name and supports insertion, lookup, and deletion by following the tree's ordering. Inorder traversal displays the directory alphabetically. Operation speed depends on tree height, so a self-balancing BST may be preferred when predictable performance is important.
