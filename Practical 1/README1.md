# Pattern Printing Programs

## Practical title

**Printing numeric and character patterns using nested loops**

## Problem statement

Write programs that read a positive integer `n` and print these four patterns:

1. A right-angle triangle containing increasing numbers.
2. A centered diamond containing palindromic number sequences.
3. A centered pyramid made of asterisks.
4. A centered alphabet pyramid whose letters increase to the middle and then decrease.

Each pattern is printed with `n` rows in its upper portion. The diamond has `2n - 1` rows.

## Objective

- Practice nested loops and row-by-row output.
- Use spaces to align centered shapes.
- Build numeric and alphabetic sequences with simple iteration.
- Understand the time and auxiliary-space costs of pattern printing.

## Algorithm / approach

Read `n` and validate that it is a positive integer. Print each pattern using its own set of nested loops.

### 1. Right-angle triangle with numbers

For each row `i` from 1 through `n`, print the integers from 1 through `i`, then start a new line.

For `n = 5`:

```text
1
12
123
1234
12345
```

### 2. Diamond shape with numbers

Print a numeric-palindrome pyramid, then its inverted half. For upper row `i` from 1 through `n`, print `n - i` leading spaces, then the sequence 1 through `i`, followed by `i - 1` down through 1. For the lower half, repeat the same logic with row sizes `n - 1` down through 1.

For `n = 4`:

```text
   1
  121
 12321
1234321
 12321
  121
   1
```

### 3. Pyramid with asterisks

For each row `i` from 1 through `n`, print `n - i` leading spaces and then `2i - 1` asterisks. Start a new line after each row.

For `n = 5`:

```text
    *
   ***
  *****
 *******
*********
```

### 4. Pyramid using alphabets

For each row `i` from 1 through `n`, print `n - i` leading spaces. Then print letters starting at A and increasing up to the row's middle letter, followed by decreasing letters back to A. For example, row 4 is `ABCDCBA`. This definition assumes `n <= 26` when using the English alphabet without wrapping.

For `n = 5`:

```text
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
```

## Data structure / concept used

- **Loops:** Outer loops select rows; inner loops print spaces and pattern elements.
- **Integer counters:** Track row numbers and sequence values.
- **Character arithmetic or alphabet lookup:** Generate letters for the alphabet pyramid.
- **No additional data structure is required.** The output is written directly as it is generated.

## Test cases

| Input `n` | Expected check |
|---:|---|
| 1 | Each pattern has one row; the diamond is a single `1`. |
| 2 | Triangle has 2 rows; diamond has 3 rows; both pyramids have 2 rows. |
| 5 | Match the sample outputs above; diamond has 9 rows. |
| 0 | Reject as invalid because the number of rows must be positive. |
| -3 | Reject as invalid because the number of rows must be positive. |
| 27 (alphabet pattern) | Reject, or explicitly extend the alphabet behavior; this README assumes A–Z without wrapping. |

## Sample input and output

### Sample input

```text
5
```

### Sample output

The programs may print the four patterns one after another, with headings or blank lines between them:

**Right-angle triangle**

```text
1
12
123
1234
12345
```

**Number diamond**

```text
    1
   121
  12321
 1234321
123454321
 1234321
  12321
   121
    1
```

**Asterisk pyramid**

```text
    *
   ***
  *****
 *******
*********
```

**Alphabet pyramid**

```text
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
```

Exact spacing is significant for the centered patterns. If each exercise is implemented as a separate program, the input `5` is supplied to each program independently.

## Time complexity

- **Right-angle triangle:** `O(n²)` printed digits, since it prints `1 + 2 + ... + n` values.
- **Number diamond:** `O(n²)` printed digits across `2n - 1` rows.
- **Asterisk pyramid:** `O(n²)` characters including leading spaces and asterisks.
- **Alphabet pyramid:** `O(n²)` characters including leading spaces and letters.

These bounds describe the work needed to generate the output. The number of printed characters is itself quadratic in `n`.

## Space complexity

- **Auxiliary space:** `O(1)` for each pattern when printed directly, excluding output buffering used by the runtime.
- **Output space:** `O(n²)` if the complete pattern is stored before printing; direct printing does not require storing it.

## Conclusion

These exercises demonstrate how nested loops can construct patterns one row at a time. Numeric counters control the row lengths and sequences, while leading spaces create alignment. The patterns require constant auxiliary space when printed directly, and their running time grows with the amount of output produced.
