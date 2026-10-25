# Experiment 6: Train Ticket Booking System Using a Queue

## Practical title

**Train Ticket Booking System using a Queue**

## Problem statement

Create a simple train ticket booking system that manages passenger booking requests in the order they are received. Each request is added to the rear of a queue. The system processes the oldest waiting request first, following the FIFO (first-in, first-out) rule.

The program should allow users to add a booking request, process the next request, view the next request, and display all pending requests. It should handle attempts to process or view requests when the queue is empty.

This experiment focuses on managing booking requests. It does not perform payment processing, seat allocation, or ticket cancellation after confirmation.

## Objective

- Apply the queue data structure to a practical booking workflow.
- Maintain booking requests in FIFO order.
- Implement enqueue, dequeue, front/peek, and display operations.
- Handle the empty-queue condition correctly.

## Algorithm / approach

Maintain a queue of booking requests. Each request can contain a booking ID, passenger name, train number, and number of seats requested.

### Add a booking request (enqueue)

1. Read the booking details.
2. Check that the queue has space if using a fixed-size array.
3. Add the request at the rear of the queue.
4. Confirm that the request has been added.

### Process the next booking request (dequeue)

1. If the queue is empty, report that there are no pending requests.
2. Otherwise, retrieve the request at the front.
3. Process or confirm that request.
4. Remove it from the queue and advance the front position.

### View or display requests

- **View next:** Show the request at the front without removing it.
- **Display all:** Traverse from the front to the rear and show requests in FIFO order.

For a circular-array implementation, update indices using modulo the queue capacity so freed positions can be reused.

## Data structure / concept used

- **Queue:** Stores requests in first-in, first-out order.
- **Array or linked list:** Can be used to implement the queue.
- **Circular array (optional):** Reuses storage after dequeue operations.
- **Booking record:** Groups fields such as booking ID, passenger name, train number, and seat count.
- **Queue operations:** Enqueue, dequeue, peek/front, and display.

## Test cases

| Case | Operation | Expected result |
|---|---|---|
| 1 | Add booking B101, then process next | B101 is processed first. |
| 2 | Add B101 and B102, then process next | B101 is processed; B102 remains at the front. |
| 3 | View next request without processing | Front request is shown and remains queued. |
| 4 | Process when the queue is empty | Display an appropriate empty-queue message. |
| 5 | Add requests until a fixed-capacity queue is full, then add another | Report overflow and retain existing requests. |
| 6 | Dequeue and then enqueue in a circular queue | Reuse the freed slot and preserve FIFO order. |

## Sample input and output

Assume booking requests contain a booking ID, passenger name, train number, and seat count.

### Sample input

```text
ADD B101 "Asha Rao" T204 2
ADD B102 "Ravi Shah" T204 1
VIEW_NEXT
PROCESS_NEXT
DISPLAY
```

### Sample output

```text
Booking B101 added to the queue.
Booking B102 added to the queue.
Next request: B101, Asha Rao, Train T204, Seats 2
Booking B101 processed.
Pending requests:
B102, Ravi Shah, Train T204, Seats 1
```

The exact command and output format can be adjusted to match the program implementation.

## Time complexity

Let `n` be the number of pending booking requests.

- **Enqueue:** O(1)
- **Dequeue:** O(1)
- **View next request:** O(1)
- **Display all pending requests:** O(n)

These operation costs assume the queue is implemented with a linked list or a circular array that tracks the front and rear.

## Space complexity

The queue requires **O(n)** space for `n` pending booking records. Enqueue and dequeue use **O(1)** additional space.

## Conclusion

A queue provides a simple way to process train booking requests in arrival order. Enqueue adds a request at the rear, while dequeue processes the request at the front. This FIFO behavior keeps the pending-request workflow orderly and predictable.
