#ifndef SINGLE_LINKED_LIST_LIBRARY_H
#define SINGLE_LINKED_LIST_LIBRARY_H

struct singleLinkedList{
    int val;
    struct singleLinkedList *next;
};

void printList(struct singleLinkedList *List);
struct singleLinkedList *addToList(int val, struct singleLinkedList *List, int sorting);
struct singleLinkedList *deleteFromList(int val, struct singleLinkedList *List);
int sort(int val, struct singleLinkedList *previousNode, struct singleLinkedList *currentNode);

# endif //SINGLE_LINKED_LIST_LIBRARY_H