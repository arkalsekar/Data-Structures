# Queues
Queues are types of Data Structures based on FIFO Pattern

## Basic Operations of Queue
A Queue is an object (an abstract data structure - ADT) that allows the following operations:

1. Enqueue: Add an element to the end of the queue
2. Dequeue: Remove an element from the front of the queue
3. IsEmpty: Check if the queue is empty
4. IsFull: Check if the queue is full
5. Peek: Get the value of the front of the queue without removing it

## Types of Queues
1. Linear Queue
Follows FIFO Patterns

2. Circular Queue
Follows FIFO Patterns

3. DE Queue
Doesn't Follows FIFO Patterns

## Implementation
1. Queue Implementation using Arrays
2. Queue Implementation using Linked Lists
3. Queue Implementation using Stack

## Working of Queue
Queue operations work as follows:

1. Print the Queue :
two pointers FRONT and REAR
FRONT track the first element of the queue
REAR track the last element of the queue
initially, set value of FRONT and REAR to -1

2. Enqueue Operation :
check if the queue is full
for the first element, set the value of FRONT to 0
increase the REAR index by 1
add the new element in the position pointed to by REAR

3. Dequeue Operation :
check if the queue is empty
return the value pointed by FRONT
increase the FRONT index by 1
for the last element, reset the values of FRONT and REAR to -1

## Resources