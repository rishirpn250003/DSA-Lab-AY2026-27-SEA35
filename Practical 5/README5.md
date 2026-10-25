# Circular Queue Using an Array for a Parcel Handling System

## Practical title

**Parcel Handling System using an Array-Based Circular Queue**

## Problem statement

Model a parcel handling system with a fixed-capacity queue. Parcels arrive and are placed at the rear of the queue. A worker processes parcels from the front. When a parcel is removed, its array slot can be reused by wrapping the rear index back to the beginning of the array.

The system should support enqueueing a parcel, dequeueing the next parcel, viewing the front parcel, and displaying the queued parcels. It should report overflow when the queue is full and underflow when it is empty.

## Objective

- Implement a FIFO (first-in, first-out) parcel queue.
- Use a circular array so freed positions can be reused.
- Perform enqueue and dequeue operations efficiently.
- Handle full-queue and empty-queue conditions.

## Algorithm / approach

Maintain an array of capacity `CAPACITY`, plus `front`, `rear`, and `count`. Initially, set `front = 0`, `rear = -1`, and `count = 0`.

### Enqueue a parcel

1. If `count == CAPACITY`, report that the queue is full.
2. Otherwise, set `rear = (rear + 1) % CAPACITY`.
3. Store the parcel at `queue[rear]`.
4. Increment `count`.

### Dequeue a parcel

1. If `count == 0`, report that the queue is empty.
2. Otherwise, process or return the parcel at `queue[front]`.
3. Set `front = (front + 1) % CAPACITY`.
4. Decrement `count`.

### View or display parcels

- The front parcel is at `queue[front]` when `count > 0`.
- To display the queue, visit `count` elements starting at `front`, using index `(front + i) % CAPACITY` for each offset `i`.

A parcel can be represented by a tracking number, or by a record containing fields such as tracking number, recipient, and destination.

## Data structure / concept used

- **Circular queue:** A FIFO structure where the last array position connects back to the first.
- **Array:** Stores parcels in a fixed-size block of memory.
- **Modulo operation:** Wraps indexes to the beginning when they reach the array capacity.
- **Queue state:** `front`, `rear`, and `count` track the next parcel to process, the latest arrival, and the number of queued parcels.

## Test cases

| Case | Operations | Expected result |
|---|---|---|
| 1 | Enqueue P101, then dequeue | P101 is processed. |
| 2 | Dequeue from an empty queue | Report queue underflow; do not change queue state. |
| 3 | Fill the queue to capacity, then enqueue one more | Report queue overflow; existing parcels remain unchanged. |
| 4 | Enqueue P101, P102; dequeue once | P101 is processed; P102 is now at the front. |
| 5 | Fill, dequeue some parcels, then enqueue more | Reuse freed slots through circular wraparound. |
| 6 | Display an empty queue | Report that there are no parcels waiting. |
| 7 | Display a wrapped queue | Show parcels in FIFO order, starting at the current front. |

## Sample input and output

Assume a queue capacity of 3. The menu accepts operations such as `ENQUEUE <parcel>`, `DEQUEUE`, and `DISPLAY`.

### Sample input

```text
ENQUEUE P101
ENQUEUE P102
ENQUEUE P103
DEQUEUE
ENQUEUE P104
DISPLAY
```

### Sample output

```text
Parcel P101 processed.
Parcel P104 added to the queue.
Parcels waiting: P102 P103 P104
```

The final enqueue wraps around to a freed array position, while the displayed order remains FIFO.

## Time complexity

- **Enqueue:** O(1)
- **Dequeue:** O(1)
- **View front:** O(1)
- **Display all parcels:** O(n), where `n` is the current number of queued parcels.

## Space complexity

The array uses **O(CAPACITY)** space for parcel records. Enqueue and dequeue require **O(1)** additional space.

## Conclusion

A circular queue is well suited to parcel handling because it processes arrivals in FIFO order and reuses array positions freed by completed parcels. Modulo-based index updates provide constant-time enqueue and dequeue operations while explicit count tracking makes full and empty states clear.
