#ifndef INC_2__DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
#define INC_2__DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H

struct doublyLinkedList{
    struct doublyLinkedList *prev; //pointed to previous node
    char character;
    struct doublyLinkedList *next; // pointed to next node
};

//Printing, in order from places first node
void printList(struct doublyLinkedList *List);

//Add node at the end
struct doublyLinkedList *addNodeAtEnd(char character, struct doublyLinkedList *List);

//Add node at the front
struct doublyLinkedList *addNodeAtFront(char character, struct doublyLinkedList *List);

//Add node(new character) after a given node(existing character)
struct doublyLinkedList *addNodeAfter(char existCharacter, char newCharacter, struct doublyLinkedList *List);

//Delete character
struct doublyLinkedList *deleteCharacter(char character, struct doublyLinkedList *List);

#endif //INC_2__DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
