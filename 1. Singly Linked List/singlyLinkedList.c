#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

//Freeing memory from the list
void freeMemory(struct singlyLinkedList *List){
    while (List){
        struct singlyLinkedList *tempNode = NULL;
        tempNode = List;
        List = List->next;
        free(tempNode);
    }
}

/* Function to delete from list*/
struct singlyLinkedList *deleteFromList(int val, struct singlyLinkedList *List){

    if(List == NULL){
        puts("The list is empty.");
    } else {
        struct singlyLinkedList *previousNode = NULL;
        struct singlyLinkedList *currentNode = NULL;
        struct singlyLinkedList *temp = NULL;

        previousNode = List;
        currentNode = List->next;

        while (currentNode != NULL){

            //if first node in the list match
            if(val == previousNode->val){
                temp = previousNode;
                List = currentNode;
                free(temp);
                temp = NULL;
                return List;
            }
            //else others
            else if(val == currentNode->val){
                temp = currentNode;
                previousNode->next = currentNode->next;
                free(temp);
                temp = NULL;
                return List;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return List;
}


/* Function for adding nodes in list. */
struct singlyLinkedList *addToList(int val, struct singlyLinkedList *List, int sorting){

    if(List == NULL){
        List = (struct singlyLinkedList*)malloc(sizeof(struct singlyLinkedList));
        List->val = val;
        List->next = NULL;

    } else {

        struct singlyLinkedList *previousNode = NULL;
        struct singlyLinkedList *currentNode = NULL;
        struct singlyLinkedList *newNode = (struct singlyLinkedList*)malloc(sizeof(struct singlyLinkedList));

        previousNode = List;
        currentNode = List->next;
        newNode->val = val;
        newNode->next = NULL;

        if(sorting){
            while (currentNode != NULL && val > previousNode->val && val > currentNode->val) {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }

            if(val < previousNode->val) {
                newNode->next = previousNode;
                List = newNode;
            }
            else if (currentNode != NULL && val > previousNode->val && val <= currentNode->val){
                previousNode->next = newNode;
                newNode->next = currentNode;
            }else {
                previousNode->next = newNode;
            }

        } else {
            while ((currentNode != NULL)) {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            previousNode->next = newNode;
        }
    }
    return List;
}

/* Function for printing nodes in list. */
void printList(struct singlyLinkedList *List){

    if(List == NULL){
        puts("The list is empty.");
    } else {
        while (List){
            printf("%d->", List->val);
            List = List->next;
        }
        puts("NULL");
    }
}
