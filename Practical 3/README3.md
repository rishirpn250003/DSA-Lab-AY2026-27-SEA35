# Searching Contact Names Using Sequential and Binary Search

## Practical title

**Contact Name Search using Sequential Search and Binary Search**

## Problem statement

Create a program that stores a list of contact names and searches for a requested name using two methods:

1. **Sequential search:** Check each name in order until the target is found or the list ends.
2. **Binary search:** Repeatedly compare the target with the middle name and discard half of the remaining search range.

Binary search requires the contact names to be sorted alphabetically before searching. The program can search the original list sequentially and a sorted copy with binary search.

## Objective

- Store and search a collection of contact names.
- Implement and compare sequential and binary search.
- Understand why binary search requires sorted data.
- Report whether the requested contact exists and its position in the list being searched.

## Algorithm / approach

### Sequential search

1. Start at the first contact.
2. Compare each contact name with the target name.
3. If they match, report the contact's position and stop.
4. If the end of the list is reached without a match, report that the contact was not found.

### Binary search

1. Sort the contact names alphabetically.
2. Set the lower bound to the first index and the upper bound to the last index.
3. Find the middle index of the current range.
4. Compare the middle name with the target:
   - If they match, report the contact's position and stop.
   - If the target comes alphabetically before the middle name, continue in the left half.
   - If it comes after, continue in the right half.
5. If the bounds cross, report that the contact was not found.

For consistent results, compare names using the same case and alphabetic ordering rules. A program may normalize names to lowercase for case-insensitive searching while preserving the original spelling for display.

## Data structure / concept used

- **Array or list of strings:** Stores the contact names.
- **Sequential search:** Linear traversal through the list.
- **Binary search:** Divide-and-conquer search over a sorted list.
- **Sorting:** Required before binary search if the input is not already sorted.

## Test cases

| Case | Contact list | Search name | Expected result |
|---|---|---|---|
| 1 | Asha, Kiran, Neha, Ravi | Neha | Found by both methods. |
| 2 | Asha, Kiran, Neha, Ravi | Asha | Found at the beginning of the list. |
| 3 | Asha, Kiran, Neha, Ravi | Ravi | Found at the end of the list. |
| 4 | Asha, Kiran, Neha, Ravi | Mohan | Not found by either method. |
| 5 | One contact: Tara | Tara | Found in a one-element list. |
| 6 | Empty list | Tara | Not found; handle the empty list without accessing an element. |
| 7 | Names entered in unsorted order | A target contact | Sequential search works on the original list; sort before binary search. |

## Sample input and output

Assume the program reads the number of contacts, the contact names, and then the name to search.

### Sample input

```text
5
Ravi
Asha
Neha
Kiran
Tara
Neha
```

### Sample output

```text
Sequential search: Neha found at position 3 in the original list.
Binary search: Neha found at position 4 in the alphabetically sorted list.
```

The positions above are one-based. In the sorted list, the order is Asha, Kiran, Neha, Ravi, Tara. Binary search positions refer to this sorted list; they may differ from positions in the original input.

## Time complexity

Let `N` be the number of contact names.

- **Sequential search:** Best case **O(1)**; average and worst cases **O(N)**.
- **Binary search:** Best case **O(1)**; average and worst cases **O(log N)** after sorting.
- **Sorting before binary search:** Typically **O(N log N)** with an efficient comparison sort. If the list is sorted once and searched many times, that one-time sorting cost can be shared across searches.

## Space complexity

- **Sequential search:** **O(1)** auxiliary space.
- **Iterative binary search:** **O(1)** auxiliary space.
- **Sorted copy:** **O(N)** additional space if the original list must be preserved. Sorting in place may use a different amount of auxiliary space depending on the sorting algorithm.

## Conclusion

Sequential search can be used directly on an unsorted contact list and is simple for small collections. Binary search reduces the number of comparisons for larger lists, but it only works correctly when the names are sorted using the same ordering used for comparison.
