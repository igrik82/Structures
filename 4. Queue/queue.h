#ifndef _QUEUE_H_
#define _QUEUE_H_

struct queue
{
  int value;
  struct queue *next;
};

// Free memory
void freeMemory(struct queue *List);

// Print queue list
void printList(struct queue *List);

// Enqueue value to the end of the list
struct queue *enqueue(int value, struct queue *List);

// Dequeue value from the beginning of the list
int dequeue(struct queue **List);

#endif //_QUEUE_H_
