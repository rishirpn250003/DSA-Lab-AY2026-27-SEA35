# Decimal to Binary Conversion Using a Stack

## Practical title

**Decimal to Binary Conversion using Stack**

## Problem statement

Write a program that reads a non-negative decimal integer and converts it to its binary representation using a stack.

To convert a decimal number, repeatedly divide it by 2 and push each remainder onto the stack. Since the remainders are generated from least significant bit to most significant bit, popping them from the stack produces the binary digits in the correct order.

## Objective

- Convert a decimal integer to its binary representation.
- Use a stack to reverse the order of generated binary digits.
- Practice stack operations: push, pop, and checking whether the stack is empty.

## Algorithm / approach

1. Read a non-negative decimal integer `number`.
2. If `number` is 0, print `0`.
3. Otherwise, while `number > 0`:
   - Calculate `remainder = number % 2`.
   - Push the remainder onto the stack.
   - Update `number = number / 2` using integer division.
4. Pop and print stack elements until the stack is empty.

Example for decimal 13:

- Remainders pushed: 1, 0, 1, 1
- Values popped and printed: 1, 1, 0, 1
- Binary result: `1101`

## Data structure / concept used

- **Stack:** Stores binary remainders in last-in, first-out order.
- **Integer division and modulo:** Repeated division by 2 produces the binary digits.
- **Looping:** Continue until the quotient becomes zero; then pop all stored bits.

The stack can be implemented using an array, a linked list, or a built-in stack type.

## Test cases

| Decimal input | Expected binary output |
|---:|:---|
| 0 | 0 |
| 1 | 1 |
| 2 | 10 |
| 13 | 1101 |
| 42 | 101010 |
| 255 | 11111111 |

Also verify that a negative input is rejected if the program is designed only for non-negative numbers.

## Sample input and output

### Sample input

```text
13
```

### Sample output

```text
Binary equivalent: 1101
```

## Time complexity

For a positive decimal integer `N`, repeated division by 2 takes **O(log N)** iterations. Each stack push and pop takes **O(1)**, so the overall time complexity is **O(log N)**.

For input 0, the program prints the special-case result directly in **O(1)** time.

## Space complexity

The stack stores one remainder per binary digit, so auxiliary space is **O(log N)** for a positive input. For input 0, only constant space is needed.

## Conclusion

Repeated division by 2 generates binary digits from right to left. A stack reverses their order, allowing the program to print the binary representation from most significant bit to least significant bit.
