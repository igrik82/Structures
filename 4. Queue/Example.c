#include <stdio.h>
#include "queue.h"

int main ()
{
    struct queue *List = NULL;

    // Prepare input data
    int values[] = { 1, 2, 3, 6, 3, 8, 9 };
    int sizeArray = sizeof(values) / sizeof(values[0]);

    // Enqueue data to list
    for(size_t i = 0; i < sizeArray; ++i)
    {
        List = enqueue(values[i], List);
    }
    printList (List);

    // Dequeue data from list
    int data = dequeue(&List);
    printList(List);

    data = dequeue(&List);
    printList(List);

    // Freeing memory
    freeMemory(List);
}