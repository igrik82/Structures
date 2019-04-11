#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "stack.h"

//Print list
void printList(struct stack *List)
{
    if(List == NULL)
    {
        puts("The list is empty.");
    }
    else
    {
        while(List)
        {
            printf("%d -> ", List->data);
            List = List->next;
        }
        puts("NULL");
    }
}

//Push data to stack
struct stack *pushToStack(int data, struct stack *List)
{
    if(List == NULL)
    {
        List = (struct stack*)malloc(sizeof(struct stack));
        List->data = data;
        List->next = NULL;
    }
    else
    {
        struct stack *currentNode = NULL;
        struct stack *nextNode = NULL;
        struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));

        newNode->data = data;
        newNode->next = NULL;
        currentNode = List;
        nextNode = List->next;

        while(nextNode)
        {
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
        currentNode->next = newNode;
    }
    return List;
}

int popFromStack(struct stack **List)
{
    int data;
    if(*List == NULL)
    {
        fprintf(stderr, "The stack is empty. Pop function forbidden.");
        exit(EXIT_FAILURE);
    }
    else
    {

        struct stack *tempNode = NULL;
        tempNode = *List;
        data = (*List)->data;

        *List = (*List)->next;
        free(tempNode);
        tempNode = NULL;
    }
    return data;
}

void freeMemory(struct stack *List)
{
    if(List == NULL)
    {
        return;
    }
    else
    {
        while (List)
        {
            struct stack *tempNode = NULL;
            tempNode = List;
            List = List->next;
            free(tempNode);
        }
    }
}






















