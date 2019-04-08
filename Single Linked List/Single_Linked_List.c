#include <stdio.h>
#include <stdlib.h>
#include "Single_Linked_List.h"

/* Function to delete from list*/
struct singleLinkedList *deleteFromList(int val, struct singleLinkedList *List){
    if(List == NULL){
        puts("The list is empty.");
    } else {
        struct singleLinkedList *previousNode = (struct singleLinkedList*)malloc(sizeof(struct singleLinkedList));
        struct singleLinkedList *currentNode = (struct singleLinkedList*)malloc(sizeof(struct singleLinkedList));
        struct singleLinkedList *temp = (struct singleLinkedList*)malloc(sizeof(struct singleLinkedList));

        previousNode = List;
        currentNode = List->next;

        while (currentNode != NULL){
            if(val == currentNode->val){
                temp = currentNode;
                previousNode->next = currentNode->next;
                free(temp);
                temp = NULL;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return List;
}

/* Function for sorting. */
int sort(int val, struct singleLinkedList *previousNode, struct singleLinkedList *currentNode){
    if(val < previousNode->val){
        return 0;
    }
    else if((currentNode != NULL) && val < currentNode->val){
        return 0;
    }
    return 1;

}

/* Function for adding nodes in list. */
struct singleLinkedList *addToList(int val, struct singleLinkedList *List, int sorting){

    if(List == NULL){

        List = (struct singleLinkedList*)malloc(sizeof(struct singleLinkedList));
        List->val = val;
        List->next = NULL;

    } else {

        struct singleLinkedList *previousNode = (struct singleLinkedList*)malloc(sizeof(struct singleLinkedList));
        struct singleLinkedList *currentNode = (struct singleLinkedList*)malloc(sizeof(struct singleLinkedList));
        struct singleLinkedList *newNode = (struct singleLinkedList*)malloc(sizeof(struct singleLinkedList));

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
void printList(struct singleLinkedList *List){

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