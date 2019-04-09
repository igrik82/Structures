#ifndef SINGLY_LINKED_LIST_LIBRARY_H
#define SINGLY_LINKED_LIST_LIBRARY_H

struct singlyLinkedList{
    int val;
    struct singlyLinkedList *next;
};

void printList(struct singlyLinkedList *List);
struct singlyLinkedList *addToList(int val, struct singlyLinkedList *List, int sorting);
struct singlyLinkedList *deleteFromList(int val, struct singlyLinkedList *List);
int sort(int val, struct singlyLinkedList *previousNode, struct singlyLinkedList *currentNode);

# endif //SINGLY_LINKED_LIST_LIBRARY_H