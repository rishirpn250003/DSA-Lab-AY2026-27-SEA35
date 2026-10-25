# Student Result Database Management Using Array of Structures

## Practical title

**Student Result Database Management System using an Array of Structures**

## Problem statement

Create a simple program to manage student result records. For each student, store identifying information and marks, calculate the total and average, assign a grade, and display the result.

The program uses an **array of structures**: each structure represents one student, and the array stores the records for multiple students.

## Objective

- Define a structure to group related student data.
- Store and process multiple records using an array of structures.
- Calculate each student's total marks, average, and grade.
- Display student results in a readable format.

## Algorithm / approach

1. Read the number of students and subjects.
2. Validate that both values are positive and that the number of students does not exceed the array capacity.
3. For each student:
   - Read the student's ID, name, and marks for each subject.
   - Check that each mark is within the allowed range (for example, 0–100).
   - Add the marks to calculate the total.
   - Calculate the average as `total / number_of_subjects`.
   - Assign a grade according to the selected grading scale.
4. Display each student's ID, name, total, average, and grade.

Example grading scale used in this README:

| Average | Grade |
|---:|:---|
| 90–100 | A |
| 80–89 | B |
| 70–79 | C |
| 60–69 | D |
| Below 60 | F |

A student with any subject mark below the passing mark may also be classified as failing, depending on the institution's rules. The sample below uses the average alone to assign the grade.

## Data structure / concept used

- **Structure:** Holds one student's ID, name, marks, total, average, and grade.
- **Array of structures:** Holds records for all students.
- **Loops:** Read marks and process/display each student.
- **Conditional statements:** Validate marks and select a grade.

Illustrative structure fields:

```text
Student
  id
  name
  marks[subject_count]
  total
  average
  grade
```

## Test cases

| Case | Input condition | Expected result |
|---|---|---|
| 1 | One student with all marks equal to 100 | Total and average are 100; grade is A. |
| 2 | Average is exactly 90 | Grade is A. |
| 3 | Average is exactly 80 | Grade is B. |
| 4 | Average is exactly 60 | Grade is D. |
| 5 | Average is below 60 | Grade is F. |
| 6 | Mark is 101 or less than 0 | Reject the mark and request valid input. |
| 7 | Student count is 0 or exceeds the array capacity | Reject the input. |
| 8 | Several students with different marks | Display one correctly calculated result per student. |

## Sample input and output

Assume the program accepts the student count, subject count, and then each student's ID, name, and marks.

### Sample input

```text
3 3
101 Asha 85 90 95
102 Ravi 70 75 80
103 Neha 55 60 65
```

### Sample output

```text
Student ID  Name   Total  Average  Grade
101         Asha   270    90.00    A
102         Ravi   225    75.00    C
103         Neha   180    60.00    D
```

The input/output format may be adjusted to match the implementation. If names can contain spaces, read each name as a full line rather than as a single word.

## Time complexity

Let `N` be the number of students and `S` the number of subjects.

- Reading marks and calculating totals: **O(N × S)**
- Displaying results: **O(N)**
- Overall: **O(N × S)**

## Space complexity

- Storing student records and marks: **O(N × S)**
- Additional working space per student: **O(1)**

## Conclusion

An array of structures provides a straightforward way to keep each student's related information together while processing a class of records. The program can calculate totals, averages, and grades by traversing the records and their marks. Validation helps keep the stored results within the expected range.
