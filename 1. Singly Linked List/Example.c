#include <stdio.h>
#include <stdlib.h>
#include "singlyLinkedList.h"

int main() {

    struct singlyLinkedList *Node = NULL;

    int values[] = { 5, 10, 4, 34, 5, 37, 33 ,7 , 24 };
    int sizeArray = sizeof(values) / sizeof(int);

    //add variables to list without sorting (0)
    for(size_t i = 0; i < sizeArray; ++i){
        Node = addToList(values[i], Node, 0);
    }
    printList(Node);

    //delete from list
    Node = deleteFromList(4, Node);
    Node = deleteFromList(7, Node);
    printList(Node);

    freeMemory(Node);
    Node = NULL;



    //add variables to list with sorting (1)
    for(size_t i = 0; i < sizeArray; ++i){
        Node = addToList(values[i], Node, 1);
    }
    printList(Node);

    //delete from list
    Node = deleteFromList(5, Node);
    Node = deleteFromList(37, Node);
    printList(Node);

    freeMemory(Node);
    Node = NULL;

}