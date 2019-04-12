#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


// Free memory
void freeMemory(struct queue *List)
{
    while(List)
    {
        struct queue *tempNode = NULL;
        tempNode = List;
        List = List->next;
        free(tempNode);
    }
}

// Dequeue value from the beginning of the list
int dequeue(struct queue **List)
{
    if(List == NULL)
    {
        fprintf(stderr, "The queue is empty.");
        exit(EXIT_FAILURE);
    }
    else
    {
        struct queue *currentNode = NULL;
        struct queue *nextNode = NULL;
        struct queue *tempNode = NULL;

        currentNode = (*List);
        nextNode = (*List)->next;

        while (nextNode->next)
        {
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        currentNode->next = NULL;
        int data = nextNode->value;
        tempNode = nextNode;
        free(tempNode);
        return data;
    }
}

// Enqueue value to the end of the list
struct queue *enqueue(int value, struct queue *List)
{
    if (List == NULL)
    {
        List = (struct queue*) malloc(sizeof(struct queue));
        List->value = value;
        List->next = NULL;
    }
    else
    {
        struct queue *addedNode = (struct queue*) malloc(sizeof(struct queue));
        addedNode->value = value;
        addedNode->next = List;
        List = addedNode;
    }
    return List;
}

// Print queue list
void printList(struct queue *List)
{
    if(List == NULL)
    {
        puts("The list is empty.");
    }
    else
    {
        while(List)
        {
            printf("%d -> ", List->value);
            List = List->next;
        }
        puts("NULL");
    }

}